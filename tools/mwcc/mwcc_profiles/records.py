"""Decode and check an MWCCPS2 backend capture stream."""
from collections import defaultdict
import struct


def decode(data, stages, layout, ir_layout=None):
    header, stride = layout["pcode_size"], layout["operand_size"]
    ir_layout = ir_layout or {}
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
    function = stage = graph = schedule = ir_stage = None
    pending_ir = []
    finished_placements = {}
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
            if pending_ir:
                function["ir_raw"] = pending_ir
                pending_ir = []
            functions.append(function)
        elif tag == b"WB3J":
            index, owner, size = words("III")
            check(index in stages and ir_stage is None and stage is None and size < 1024, "Unexpected IR stage")
            ir_stage = {
                "stage": stages[index], "symbol": take(size).decode("ascii", errors="backslashreplace"),
                "statements": [], "nodes": {}, "depths": {}, "objects": {}, "types": {}, "lists": {},
            }
        elif tag == b"WB3K":
            (address,) = words("I")
            check(ir_stage is not None, "Unexpected IR statement")
            ir_stage["statements"].append((address, take(ir_layout["stmt_size"])))
        elif tag == b"WB3U":
            address, depth = words("II")
            check(ir_stage is not None, "Unexpected IR node")
            ir_stage["nodes"][address] = take(ir_layout["enode_size"])
            ir_stage["depths"].setdefault(address, depth)
        elif tag == b"WB3W":
            (address,) = words("I")
            check(ir_stage is not None, "Unexpected IR type")
            ir_stage["types"][address] = take(ir_layout["type_size"])
        elif tag == b"WB3O":
            address, size = words("II")
            check(ir_stage is not None and size < 1024, "Unexpected IR object")
            raw = take(ir_layout["object_size"])
            ir_stage["objects"][address] = (raw, take(size).decode("ascii", errors="backslashreplace"))
        elif tag == b"WB3H":
            address, size = words("II")
            check(ir_stage is not None and size < 256, "Unexpected IR label")
            raw = take(ir_layout["label_size"])
            ir_stage.setdefault("labels", {})[address] = (raw, take(size).decode("ascii", errors="backslashreplace"))
        elif tag == b"WB3c":
            (address,) = words("I")
            check(ir_stage is not None, "Unexpected IR switch")
            ir_stage.setdefault("switches", {})[address] = take(ir_layout["switch_size"])
        elif tag == b"WB3k":
            (address,) = words("I")
            check(ir_stage is not None, "Unexpected IR switch case")
            ir_stage.setdefault("cases", {})[address] = take(ir_layout["case_size"])
        elif tag == b"WB3A":
            (address,) = words("I")
            check(ir_stage is not None, "Unexpected IR argument list")
            ir_stage["lists"][address] = take(8)
        elif tag == b"WB3Z":
            count, status = words("II")
            check(ir_stage is not None and count == len(ir_stage["statements"]), "Incomplete IR stage")
            check(status == 0, "IR capture hit its node or depth limit")
            pending_ir.append(ir_stage)
            ir_stage = None
        elif tag == b"WB3S":
            (index,) = words("I")
            check(index in stages and stage is None and graph is None, "Unexpected PCode stage")
            name = stages[index]
            check(function is not None, "Missing start of code generation")
            stage = {"stage": name, "pcode": []}
            placements = {}
            labels = {}
        elif tag == b"WB3L":
            block, label = words("II")
            check(stage is not None and label != 0 and label not in labels, "Invalid PCode label record")
            labels[label] = block
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
        elif tag == b"WB3N":
            index, size = words("II")
            check(stage is not None and stage["pcode"] and 0 < size < 1024, "Invalid operand symbol record")
            operands = stage["pcode"][-1]["operands"]
            check(index < len(operands) and operands[index]["kind"] == 4, "Unexpected symbol operand")
            check("symbol" not in operands[index], "Duplicate operand symbol")
            operands[index]["symbol"] = take(size).decode("ascii", errors="backslashreplace")
        elif tag == b"WB3E":
            count, status = words("II")
            check(stage is not None and count == len(stage["pcode"]), "Incomplete PCode stage")
            check(status == 0, f"PCode capture hit limit {status}")
            for instruction in stage["pcode"]:
                for operand in instruction["operands"]:
                    if operand["kind"] == 6:
                        label = struct.unpack_from("<I", bytes.fromhex(operand["raw_hex"]), 2)[0]
                        if label in labels:
                            operand["target_block"] = labels[label]
            name = stage["stage"]
            function["pcode_stages"].append(stage)
            finished_placements = placements
            if name in ("before_schedule", "before_late_schedule"):
                check(schedule is None, "Unexpected scheduler start")
                schedule = {"pass": "early" if name == "before_schedule" else "late", "issues": [], "decisions": []}
                scheduled_instructions = placements
                pending_ready = []
            elif name in ("after_schedule", "after_late_schedule"):
                check(schedule is not None, "Missing scheduler start")
                function["schedules"].append(schedule)
                schedule = None
            stage = None
        elif tag == b"WB3Q":
            cycle, slot, address, cycles_word, meta_word = words("IIIII")
            check(schedule is not None and stage is None, "Unexpected scheduler ready candidate")
            block, ordinal = scheduled_instructions.get(address, (None, None))
            pending_ready.append({
                "block": block,
                "input_ordinal": ordinal,
                "earliest_cycle": cycles_word & 0xFFFF,
                "preferred_cycle": (cycles_word >> 16) & 0xFFFF,
                "priority": meta_word & 0xFFFF,
                "unscheduled_preds": (meta_word >> 16) & 0xFFFF,
            })
        elif tag == b"WB3V":
            cycle, slot, address = words("III")
            check(schedule is not None and stage is None, "Unexpected scheduler decision")
            if address:
                block, ordinal = scheduled_instructions.get(address, (None, None))
                selected = {"block": block, "input_ordinal": ordinal}
            else:
                selected = None
            schedule["decisions"].append({
                "cycle": cycle,
                "slot": slot,
                "stalled": selected is None,
                "selected": selected,
                "ready_list": pending_ready,
            })
            pending_ready = []
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
        elif tag == b"WB3Y":
            branch, insn, pred_next, flags, live, safe, ft_block, target_block = words("IIIIiiII")
            check(function is not None and stage is None, "Unexpected delay-slot fall-through record")
            located = finished_placements.get(branch, (None, None))
            reasons = []
            if pred_next == 0xFFFFFFFF:
                reasons.append("no_predecessor_list")
            elif pred_next:
                reasons.append("multiple_predecessors")
            if not insn:
                reasons.append("empty_block")
            else:
                if flags & 0x48000106:
                    reasons.append(f"flags_{flags & 0x48000106:#x}")
                if safe == 0:
                    reasons.append("unsafe_to_hoist")
                if live == 1:
                    reasons.append("destination_live")
            function.setdefault("fallthrough_checks", []).append({
                "branch_block": located[0], "branch_ordinal": located[1],
                "candidate": finished_placements.get(insn, (None, None)) if insn else None,
                "candidate_flags": flags, "single_predecessor": pred_next == 0,
                "destination_live": live == 1 if live >= 0 else None,
                "safe_to_hoist": safe == 1 if safe >= 0 else None,
                "fill": not reasons, "reasons": reasons,
            })
        elif tag == b"WB3!":
            raise ValueError("Interference graph exceeded capture limits")
        else:
            raise ValueError(f"Unexpected record {tag!r} at trace offset {cursor - 4:#x}")
    check(functions and stage is None and graph is None and schedule is None and ir_stage is None, "No complete trace")
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
                        name = operand.get("symbol")
                        offset = operand["offset"]
                        if name:
                            operands.append(f"{name}{offset:+#x}" if offset else name)
                        else:
                            operands.append(f"ref({offset:+#x})")
                    elif operand["kind"] == 6 and "target_block" in operand:
                        operands.append(f"block {operand['target_block']}")
                    else:
                        operands.append(f"kind{operand['kind']}")
                suffix = " " + ", ".join(operands) if operands else ""
                lines.append(f"    {ins['mnemonic']}{suffix}")
            lines.append("")
    return "\n".join(lines)


def regalloc_text(functions):
    lines = []
    for function in functions:
        lines.append(f"=== {function['symbol']} ===")
        for frame in function["allocation_frames"]:
            lines.append(
                f"  class={frame['register_class']} attempt={frame['attempt']} "
                f"succeeded={frame['coloring_succeeded']} nodes={len(frame['nodes'])} edges={len(frame['edges'])}"
            )
            lines.append("  simplification:")
            for step in frame["simplification"]:
                lines.append(
                    f"    node={step['node']} reason={step['reason']} "
                    f"deg={step['weighted_degree']} cost={step['cost_field']}"
                )
            lines.append("  choices:")
            for choice in frame["choices"]:
                retry = f" retry={choice['enabled_for_retry']}" if "enabled_for_retry" in choice else ""
                blockers = ",".join(
                    f"{b['neighbor']}(c{b['color']})" for b in choice["colored_neighbors"] if b["removed_mask"]
                )
                lines.append(
                    f"    node={choice['node']} selected={choice['selected']}{retry} "
                    f"avail={choice['available_mask']:#x} init={choice['initial_mask']:#x} "
                    f"blockers=[{blockers}]"
                )
        lines.append("")
    return "\n".join(lines)


def scheduler_text(functions):
    lines = []
    for function in functions:
        stage_lookup = {
            stage["stage"]: stage["pcode"] for stage in function["pcode_stages"]
        }
        lines.append(f"=== {function['symbol']} ===")
        for sch in function["schedules"]:
            pre_name = "before_schedule" if sch["pass"] == "early" else "before_late_schedule"
            pcode = stage_lookup.get(pre_name, [])
            stalls = sum(1 for d in sch.get("decisions", []) if d["stalled"])
            lines.append(
                f"  pass={sch['pass']} issues={len(sch['issues'])} "
                f"decisions={len(sch.get('decisions', []))} stalls={stalls}"
            )
            for dec in sch.get("decisions", []):
                sel = dec["selected"]
                if sel is None:
                    sel_str = "STALL"
                else:
                    ord_idx = sel["input_ordinal"]
                    mnem = pcode[ord_idx]["mnemonic"] if ord_idx is not None and ord_idx < len(pcode) else "?"
                    sel_str = f"b{sel['block']}:#{ord_idx}({mnem})"
                ready_parts = []
                for cand in dec["ready_list"]:
                    ord_idx = cand["input_ordinal"]
                    mnem = pcode[ord_idx]["mnemonic"] if ord_idx is not None and ord_idx < len(pcode) else "?"
                    ready_parts.append(
                        f"#{ord_idx}({mnem},e={cand['earliest_cycle']},d={cand['preferred_cycle']},p={cand['priority']},pred={cand['unscheduled_preds']})"
                    )
                lines.append(
                    f"    cyc={dec['cycle']} slot={dec['slot']} -> {sel_str} | ready=[{', '.join(ready_parts)}]"
                )
        lines.append("")
    return "\n".join(lines)


def fallthrough_text(functions):
    """One line per conditional branch the 3.0.3 delay-slot filler tried to fill from its fall-through block."""
    lines = []
    for function in functions:
        checks = function.get("fallthrough_checks")
        if checks is None:
            continue
        lines.append(f"{function['symbol']}")
        for check in checks:
            candidate = check["candidate"]
            where = f"block {candidate[0]} #{candidate[1]}" if candidate else "-"
            verdict = "fill" if check["fill"] else "nop: " + ", ".join(check["reasons"])
            lines.append(
                f"  branch block {check['branch_block']} #{check['branch_ordinal']}: candidate {where} "
                f"flags={check['candidate_flags']:#010x} -> {verdict}"
            )
    return "\n".join(lines) + "\n" if lines else ""
