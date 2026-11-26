"""Readable views of the MWCCPS2 frontend IR captures.

Two sources feed this module:

* ``ir_raw`` stages from the binary trace: raw copies of the Statement list and
  every reachable ENode, Object, Type and CLabel at the CodeGen boundaries.
* ``iro.log``: the compiler's own IroDump.c writer, enabled by the tracer, which
  prints the IR optimizer's linear form (flow graph plus numbered nodes) after
  each optimizer phase.
"""
import difflib
import re
import struct


STATEMENT_NAMES = {
    0: "ST_0", 1: "NOP", 2: "LABEL", 3: "GOTO", 4: "EXPR", 5: "SWITCH", 6: "IFGOTO", 7: "IFNGOTO",
    8: "RETURN", 9: "OVF", 10: "EXIT", 11: "ENTRY", 12: "BEGINCATCH", 13: "ENDCATCH",
    14: "ENDCATCHDTOR", 15: "GOTOEXPR", 16: "ASM", 17: "BEGINLOOP", 18: "ENDLOOP",
}

# TypeIntegral.integral (Type+6) for TYPEINT (1) and TYPEFLOAT (2).
INTEGRAL_NAMES = {
    0: "bool", 1: "char", 2: "s8", 3: "u8", 4: "wchar", 5: "s16", 6: "u16", 7: "s32", 8: "u32",
    9: "long", 10: "ulong", 11: "s64", 12: "u64", 13: "f32", 14: "f64s", 15: "f64", 16: "f64l",
    17: "s128", 18: "u128",
}
TYPE_NAMES = {
    0: "void", 3: "enum", 4: "struct", 5: "class", 6: "func", 7: "bitfield", 8: "label",
    10: "memberptr", 11: "ptr", 12: "array",
}

# Linear-node annotations from IroDump.c that are present on nearly every node.
IRO_NOISE_FLAGS = {"<reffed>", "<ind>", "<immind>", "<assigned>", "<used>"}


def _type_name(types, address):
    raw = types.get(address)
    if raw is None:
        return "?"
    kind, size, integral = raw[0], struct.unpack_from("<i", raw, 2)[0], raw[6]
    if kind in (1, 2):
        return INTEGRAL_NAMES.get(integral, f"int{integral}")
    name = TYPE_NAMES.get(kind, f"type{kind}")
    return name if kind in (0, 11) else f"{name}{size}"


def structure_stage(raw_stage, layout, enode_names):
    """Turn one raw stage into JSON-friendly statements with nested expression trees.

    ``enode_names`` is the profile's ENodeType table; the numbering differs between builds.
    """
    nodes, objects, types = raw_stage["nodes"], raw_stage["objects"], raw_stage["types"]
    labels = raw_stage.get("labels", {})
    lists = raw_stage["lists"]
    data, rtype = layout["enode_data"], layout["enode_rtype"]
    label_names = {}
    defines = {}
    switches, cases = raw_stage.get("switches", {}), raw_stage.get("cases", {})

    def int128(raw, offset):
        words = struct.unpack_from("<4I", raw, offset)
        value = (words[0] << 96) | (words[1] << 64) | (words[2] << 32) | words[3]
        return value - (1 << 128) if value >> 127 else value

    def label_name(address):
        if address in labels and labels[address][1]:
            return labels[address][1]
        return label_names.setdefault(address, f"L{len(label_names)}")

    def obj_info(address):
        raw, name = objects.get(address, (b"", ""))
        info = {"object": name or f"obj_{len(name)}"}
        if raw:
            info["storage"] = "local" if raw[2] == 1 else "global" if raw[2] == 0 else f"datatype{raw[2]}"
        return info

    def tree(address, seen):
        if not address:
            return None
        if address not in nodes:
            return {"op": "?", "address": f"{address:#x}"}
        if address in seen:
            return {"op": "cycle"}
        raw = nodes[address]
        kind = raw[0]
        op = enode_names[kind] if kind < len(enode_names) else f"E{kind}"
        out = {
            "op": op,
            "type": _type_name(types, struct.unpack_from("<I", raw, rtype)[0]) if rtype >= 0 else "?",
        }
        flags = struct.unpack_from("<H", raw, 2)[0]
        if flags:
            out["flags"] = flags
        slots = struct.unpack_from("<4I", raw, data)
        children = []
        if op == "EINTCONST":
            out["value"] = int128(raw, data)
        elif op == "EREUSE":
            out["reuses"] = defines.setdefault(slots[0], len(defines))
        elif op == "EFLOATCONST":
            out["value"] = struct.unpack_from("<d", raw, data)[0]
        elif op == "EOBJREF":
            out.update(obj_info(slots[0]))
        elif op in ("EFUNCCALL", "EFUNCCALLP"):
            children.append(tree(slots[0], seen | {address}))
            cursor, guard = slots[1], 0
            while cursor and cursor in lists and guard < 4096:
                next_entry, node = struct.unpack_from("<II", lists[cursor])
                children.append(tree(node, seen | {address}))
                cursor, guard = next_entry, guard + 1
        else:
            if op == "EDEFINE":
                out["define"] = defines.setdefault(address, len(defines))
            for slot in slots[:3]:
                if slot in nodes:
                    children.append(tree(slot, seen | {address}))
        if children:
            out["args"] = children
        return out

    statements = []
    for address, raw in raw_stage["statements"]:
        kind = raw[4]
        expr = struct.unpack_from("<I", raw, layout["stmt_expr"])[0]
        label = struct.unpack_from("<I", raw, layout["stmt_label"])[0]
        stmt = {"kind": STATEMENT_NAMES.get(kind, f"ST_{kind}")}
        if label and kind in (2, 3, 6, 7):
            stmt["label"] = label_name(label)
        if expr:
            stmt["expr"] = tree(expr, frozenset())
        if kind == 5 and label in switches:
            info = switches[label]
            cursor, entries = struct.unpack_from("<I", info, layout["switch_cases"])[0], []
            while cursor in cases and len(entries) < 65536:
                case = cases[cursor]
                target = struct.unpack_from("<I", case, layout["case_label"])[0]
                entries.append({"value": int128(case, 8), "label": label_name(target)})
                cursor = struct.unpack_from("<I", case, 0)[0]
            stmt["cases"] = sorted(entries, key=lambda entry: entry["value"])
            stmt["default"] = label_name(struct.unpack_from("<I", info, layout["switch_default"])[0])
        statements.append(stmt)
    return {"stage": raw_stage["stage"], "symbol": raw_stage["symbol"], "statements": statements}


def _flags(node):
    flags = node.get("flags", 0)
    if not flags:
        return ""
    names = ["volatile"] if flags & 2 else []
    if flags & ~2:
        names.append(f"{flags & ~2:#x}")
    return "{" + ",".join(names) + "}"


def sexpr(node):
    if node is None:
        return "nil"
    op, kind = node["op"], node.get("type", "?") + _flags(node)
    if op == "EINTCONST":
        return f"{node['value']}:{kind}"
    if op == "EFLOATCONST":
        return f"{node['value']!r}:{kind}"
    if op == "EOBJREF":
        return f"&{node['object']}"
    args = node.get("args", [])
    if op == "EREUSE":
        return f"(EREUSE:{kind} d{node['reuses']})"
    if op == "EDEFINE":
        op = f"EDEFINE=d{node['define']}"
    if op == "EINDIRECT" and len(args) == 1 and args[0] and args[0]["op"] == "EOBJREF":
        return f"{args[0]['object']}:{kind}"
    inner = " ".join(sexpr(arg) for arg in args)
    return f"({op}:{kind} {inner})" if inner else f"({op}:{kind})"


def statement_text(stmt):
    parts = [stmt["kind"]]
    if "label" in stmt:
        parts.append(stmt["label"])
    if "expr" in stmt:
        parts.append(sexpr(stmt["expr"]))
    if "cases" in stmt:
        parts.append("[" + " ".join(f"{c['value']}:{c['label']}" for c in stmt["cases"]) + f"] default {stmt['default']}")
    return " ".join(parts)


# --- IroDump.c log -----------------------------------------------------------

_NODE = re.compile(r"^\s*(\d+): (.*)$")
_DUMP = re.compile(r"^Dumping function (.*?) after (.*?) ?$")


def parse_iro_log(text):
    """Split the optimizer log into functions, phases, flow-graph blocks and events."""
    functions = []
    function = phase = block = None
    events = []
    blanks = 0
    in_dump = False
    for line in text.splitlines():
        if line.startswith("Starting function "):
            function = {"symbol": line[len("Starting function "):].strip(), "phases": []}
            functions.append(function)
            events, in_dump = [], False
            continue
        match = _DUMP.match(line)
        if match:
            if function is None or function["symbol"] != match.group(1):
                function = {"symbol": match.group(1), "phases": []}
                functions.append(function)
            phase = {"phase": match.group(2).strip(), "events": events, "blocks": []}
            function["phases"].append(phase)
            events, in_dump, block, blanks = [], True, None, 0
            continue
        if in_dump:
            if not line.strip():
                blanks += 1
                if blanks >= 3:
                    in_dump = False
                continue
            blanks = 0
            if line.startswith("----") or line == "Flowgraph":
                continue
            if line.startswith("Flowgraph node "):
                block = {"id": int(line.split()[2]), "succ": [], "pred": [], "loop_depth": 0, "nodes": []}
                phase["blocks"].append(block)
                continue
            if block is not None:
                if line.startswith("Succ = "):
                    block["succ"] = [int(v) for v in line[7:].split()]
                    continue
                if line.startswith("Pred = "):
                    block["pred"] = [int(v) for v in line[7:].split()]
                    continue
                if line.startswith("LoopDepth = "):
                    block["loop_depth"] = int(line.split("=")[1])
                    continue
                if line.startswith(("MustReach", "Dom:")):
                    continue
                node = _NODE.match(line)
                if node:
                    block["nodes"].append((int(node.group(1)), node.group(2).rstrip()))
                    continue
            in_dump = False
        if line.strip(" -*") and function is not None:
            events.append(line.rstrip())
    return functions


def _linear_statements(block_nodes):
    """Render IRO linear nodes as one s-expression per root (a node no other node uses)."""
    table, used = {}, set()
    for index, text in block_nodes:
        words = text.split()
        flags = [w for w in words if w.startswith("<")]
        words = [w for w in words if not w.startswith("<")]
        table[index] = (words, flags)
    refs = {}
    for index, (words, _) in table.items():
        op = words[0] if words else ""
        if op.startswith("E") or op in ("If", "IfNot", "Return", "Switch", "Funccall"):
            for word in words[1:]:
                ref = word.strip("(),")
                if ref.isdigit() and int(ref) in table and int(ref) != index:
                    refs.setdefault(index, []).append(int(ref))
                    used.add(int(ref))

    def render(index, depth=0):
        words, flags = table[index]
        if depth > 200:
            return f"#{index}"
        extra = "".join(f for f in flags if f not in IRO_NOISE_FLAGS)
        if not words:
            return "?"
        if words[0] == "Operand":
            return " ".join(words[1:]) + extra
        if words[0] == "EINDIRECT" and len(words) == 2 and words[1].isdigit():
            child = int(words[1])
            if child in table and table[child][0][:1] == ["Operand"]:
                inner = " ".join(table[child][0][1:])
                if not inner.lstrip("-").isdigit():
                    return f"*{inner}{extra}"
        parts = [words[0]]
        for word in words[1:]:
            ref = word.strip("(),")
            parts.append(render(int(ref), depth + 1) if ref.isdigit() and int(ref) in refs.get(index, []) else word)
        return f"({' '.join(parts)}){extra}"

    return [(index, render(index)) for index, _ in block_nodes if index not in used]


def iro_phase_text(phase):
    lines = []
    for block in phase["blocks"]:
        depth = f" loop_depth={block['loop_depth']}" if block["loop_depth"] else ""
        lines.append(f"  B{block['id']} succ={block['succ']} pred={block['pred']}{depth}")
        for index, text in _linear_statements(block["nodes"]):
            if text != "(Nop)" and text != "(End)":
                lines.append(f"    #{index} {text}")
    return lines


_INDEX = re.compile(r"^(\s*)#\d+ ")


def strip_indices(lines):
    """Linear node numbers shift whenever a pass rebuilds nodes; compare without them."""
    return [_INDEX.sub(r"\1", line) for line in lines]


def summarize_iro(function):
    """JSON form: each phase keeps its events and rendered blocks; repeats are marked unchanged."""
    phases, previous = [], None
    for phase in function["phases"]:
        body = iro_phase_text(phase)
        entry = {"phase": phase["phase"], "events": phase["events"]}
        if strip_indices(body) == previous:
            entry["unchanged"] = True
        else:
            entry["ir"] = body
            previous = strip_indices(body)
        phases.append(entry)
    return phases


# --- Text and diff views -------------------------------------------------------

def stage_lines(function):
    """Ordered (stage key, lines) for every frontend IR snapshot of one function."""
    out = []
    ir_stages = function.get("ir_stages", [])
    for stage in ir_stages[:1]:
        out.append((stage["stage"], [statement_text(s) for s in stage["statements"]]))
    body = []
    for index, phase in enumerate(function.get("iro_phases", [])):
        body = list(phase.get("ir", body))
        out.append((f"iro[{index}] {phase['phase']}", body))
    for stage in ir_stages[1:]:
        out.append((stage["stage"], [statement_text(s) for s in stage["statements"]]))
    return out


def ir_text(functions):
    lines = []
    for function in functions:
        ir_stages = function.get("ir_stages", [])
        if not ir_stages and not function.get("iro_phases"):
            continue
        previous = None
        for key, body in stage_lines(function):
            phase_events = []
            if key.startswith("iro["):
                phase_events = function["iro_phases"][int(key[4:key.index("]")])]["events"]
            lines.append(f"{function['symbol']} / {key}")
            lines.extend(f"  ! {event}" for event in phase_events)
            if strip_indices(body) == previous:
                lines.append("  (unchanged)")
            else:
                lines.extend(f"  {line}" for line in body)
            previous = strip_indices(body)
            lines.append("")
    return "\n".join(lines) + "\n" if lines else ""


def _keyed(function):
    """Key each snapshot by phase name and occurrence so skipped phases do not shift the rest."""
    counts, out = {}, []
    for key, body in stage_lines(function):
        name = key.split("] ", 1)[1] if key.startswith("iro[") else key
        nth = counts[name] = counts.get(name, -1) + 1
        out.append((f"{name}#{nth}", key, strip_indices(body)))
    return out


def diff_ir(fn_a, fn_b, context=3):
    stages_a, stages_b = _keyed(fn_a), _keyed(fn_b)
    bodies_b = {key: (label, body) for key, label, body in stages_b}
    keys_a = {key for key, _, _ in stages_a}
    summaries, first, first_diff = [], None, []
    for key, label_a, body_a in stages_a:
        label_b, body_b = bodies_b.get(key, (None, None))
        equal = body_a == body_b
        summaries.append({"stage": key, "equal": equal, "missing_in_b": body_b is None})
        if not equal and first is None:
            if body_b is None:
                continue
            first = f"{label_a} | {label_b}" if label_a != label_b else label_a
            first_diff = list(difflib.unified_diff(
                body_a, body_b, fromfile=f"A:{label_a}", tofile=f"B:{label_b}", lineterm="", n=context,
            ))
    only_a = [key for key, _, _ in stages_a if key not in bodies_b]
    only_b = [key for key, _, _ in stages_b if key not in keys_a]
    return {
        "first_diverging_ir_stage": first, "ir_stage_diff": first_diff, "ir_stage_summaries": summaries,
        "ir_stages_only_in_a": only_a, "ir_stages_only_in_b": only_b,
    }
