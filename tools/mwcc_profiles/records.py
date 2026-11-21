"""Decode and check an MWCCPS2 backend capture stream."""
from collections import defaultdict
import struct


def decode(data, stages, layout):
    header, stride = layout["pcode_size"], layout["operand_size"]
    cursor = 0

    def take(size):
        nonlocal cursor
        start = cursor
        cursor += size
        check(cursor <= len(data), "Truncated trace")
        return data[start:cursor]

    def words(fmt):
        fmt = "<" + fmt
        return struct.unpack(fmt, take(struct.calcsize(fmt)))

    def check(condition, message):
        if not condition:
            raise ValueError(f"{message} at trace offset {cursor:#x}")

    functions = []
    function = stage = graph = schedule = None
    while cursor < len(data):
        tag = take(4)
        if tag == b"WB3F":
            (size,) = words("I")
            check(0 < size < 1024 and stage is None and graph is None, "Invalid function name record")
            symbol = take(size).decode("ascii", errors="backslashreplace")
            function = {
                "ordinal": len(functions), "symbol": symbol,
                "pcode_stages": [], "allocation_frames": [], "schedules": [],
            }
            functions.append(function)
        elif tag == b"WB3S":
            (index,) = words("I")
            check(index in stages and stage is None and graph is None, "Unexpected PCode stage")
            name = stages[index]
            check(function is not None, "Missing start of code generation")
            stage = {"stage": name, "pcode": []}
            placements = {}
        elif tag == b"WB3P":
            block, ordinal, size, address, name_size = words("IIIII")
            check(stage is not None and ordinal == len(stage["pcode"]), "Unexpected PCode instruction")
            check(header <= size <= header + stride * 256, "Invalid PCode size")
            check(name_size < 64, "Invalid opcode name length")
            mnemonic = take(name_size).decode("ascii", errors="backslashreplace")
            payload = take(size)
            opcode, count = struct.unpack_from("<HH", payload, layout["pcode_opcode"])
            check(size == header + stride * count, "Invalid PCode operand count")
            operands = []
            for offset in range(header, size, stride):
                kind, reg_class, flags, register = struct.unpack_from("<BBHh", payload, offset)
                if kind == 0:
                    operand = {"kind": kind, "class": reg_class, "register": register, "flags": flags}
                else:
                    operand = {"kind": kind, "raw_hex": payload[offset:offset + stride].hex()}
                    if kind == 2:
                        operand["immediate"] = struct.unpack_from("<H", payload, offset + 2)[0]
                    elif kind == 3:
                        operand["word_0e"] = struct.unpack_from("<I", payload, offset + 0xE)[0]
                    elif kind == 4:
                        operand["offset"] = struct.unpack_from("<i", payload, offset + 2)[0]
                operands.append(operand)
            placements[address] = (block, len(stage["pcode"]))
            (flags,) = struct.unpack_from("<I", payload, 0x0C)
            stage["pcode"].append({
                "block": block, "opcode": opcode, "mnemonic": mnemonic or f"op_{opcode}",
                "flags": flags, "operands": operands,
            })
        elif tag == b"WB3E":
            count, status = words("II")
            check(stage is not None and count == len(stage["pcode"]), "Incomplete PCode stage")
            check(status == 0, f"PCode capture hit limit {status}")
            name = stage["stage"]
            function["pcode_stages"].append(stage)
            if name in ("before_schedule", "before_late_schedule"):
                check(schedule is None, "Unexpected scheduler start")
                schedule = {"pass": "early" if name == "before_schedule" else "late", "issues": []}
                scheduled_instructions = placements
            elif name in ("after_schedule", "after_late_schedule"):
                check(schedule is not None, "Missing scheduler start")
                function["schedules"].append(schedule)
                schedule = None
            stage = None
        elif tag == b"WB3T":
            address, opcode, cycle, slot = words("IIII")
            check(schedule is not None and stage is None, "Unexpected scheduler issue")
            block, ordinal = scheduled_instructions.get(address, (None, None))
            schedule["issues"].append({
                "block": block, "input_ordinal": ordinal, "opcode": opcode,
                "cycle": cycle, "slot": slot,
            })
        elif tag == b"WB3G":
            category, attempt = words("II")
            check(stage is None and graph is None and function is not None and category < 7, "Unexpected allocation frame")
            graph = {
                "register_class": category, "attempt": attempt,
                "simplification": [], "choices": [],
            }
            blockers = []
            incidences = defaultdict(list)
        elif tag == b"WB3M":
            reason, node, degree, cost_field = words("IiiI")
            check(graph is not None and reason < 3, "Unexpected simplification event")
            graph["simplification"].append({
                "node": node, "reason": ("initial_scan", "pressure", "rescan")[reason],
                "weighted_degree": degree, "cost_field": cost_field,
            })
        elif tag == b"WB3R":
            node, color = words("ii")
            check(graph is not None and graph["choices"], "Unexpected color retry")
            choice = graph["choices"][-1]
            check(choice["node"] == node and choice["selected"] == -1 and 0 <= color < 32, "Invalid color retry")
            choice["enabled_for_retry"] = color
        elif tag == b"WB3B":
            node, neighbor, color, flags = words("iiiI")
            check(graph is not None, "Unexpected colored neighbor")
            blockers.append({"node": node, "neighbor": neighbor, "color": color, "flags": flags})
        elif tag == b"WB3D":
            node, selected, available, initial = words("iiII")
            check(graph is not None and all(b["node"] == node for b in blockers), "Mismatched color choice")
            recomputed = initial
            for blocker in blockers:
                color = blocker["color"]
                check(0 <= color < 32, "Invalid blocking color")
                width = 2 if blocker["flags"] & 0x200 else 1
                mask = ((1 << width) - 1) << color
                blocker["removed_mask"] = recomputed & mask
                recomputed &= ~mask
            check(recomputed == available, "Color mask disagrees with observed neighbors")
            graph["choices"].append({
                "node": node, "selected": selected, "available_mask": available,
                "initial_mask": initial, "colored_neighbors": blockers,
            })
            blockers = []
        elif tag == b"WB3C":
            success, total, physical = words("III")
            check(graph is not None and not blockers and 0 <= physical <= total <= 32767, "Invalid graph snapshot")
            raw_nodes = take(total * 30)
            parents = words(f"{total}H")
            nodes = []
            for slot, parent in enumerate(parents):
                node, color, flags = struct.unpack_from("<hhH", raw_nodes, slot * 30 + 0x10)
                nodes.append({
                    "slot": slot, "node_id": node, "physical": slot < physical,
                    "color": color, "flags": flags, "parent": parent,
                })
            graph.update(coloring_succeeded=bool(success), nodes=nodes)
        elif tag == b"WB3I":
            owner, low, high = words("III")
            check(graph is not None and "nodes" in graph, "Unexpected graph edge")
            check(low < high < len(graph["nodes"]) and owner in (low, high), "Invalid graph edge")
            incidences[(low, high)].append(owner)
        elif tag == b"WB3X":
            (count,) = words("I")
            check(graph is not None and "nodes" in graph, "Missing graph snapshot")
            check(count == sum(map(len, incidences.values())), "Incomplete graph edge list")
            check(all(sorted(owners) == list(edge) for edge, owners in incidences.items()), "Graph incidence mismatch")
            graph["edges"] = sorted(incidences)
            function["allocation_frames"].append(graph)
            graph = None
        elif tag == b"WB3!":
            raise ValueError("Interference graph exceeded capture limits")
        else:
            raise ValueError(f"Unexpected record {tag!r} at trace offset {cursor - 4:#x}")
    check(functions and stage is None and graph is None and schedule is None, "No complete trace")
    for function in functions:
        pcode = function["pcode_stages"]
        check(
            pcode and pcode[0]["stage"] == "instruction_selection" and pcode[-1]["stage"] == "before_emission",
            f"Incomplete code generation for {function['symbol']}",
        )
    return functions


def pcode_text(functions):
    lines = []
    for function in functions:
        for stage in function["pcode_stages"]:
            lines.append(f"{function['symbol']} / {stage['stage']}")
            block = None
            for ins in stage["pcode"]:
                if block != ins["block"]:
                    block = ins["block"]
                    lines.append(f"  block {block}")
                operands = []
                for operand in ins["operands"]:
                    if operand["kind"] == 0:
                        prefix = "r" if operand["class"] == 0 else f"class{operand['class']}:"
                        operands.append(f"{prefix}{operand['register']}")
                    elif operand["kind"] == 2:
                        operands.append(str(operand["immediate"]))
                    elif operand["kind"] == 3:
                        operands.append(f"imm({operand['word_0e']:#x})")
                    elif operand["kind"] == 4:
                        operands.append(f"ref({operand['offset']:+#x})")
                    else:
                        operands.append(f"kind{operand['kind']}")
                suffix = " " + ", ".join(operands) if operands else ""
                lines.append(f"    {ins['mnemonic']}{suffix}")
            lines.append("")
    return "\n".join(lines)
