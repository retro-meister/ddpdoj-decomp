# In-process PE32 trace thunks. The generator defines each profile’s addresses and layout.
.macro original_call target
    .byte 0xe8
    .long \target - (trace_base + (. - trace_start) + 4)
.endm

.macro snapshot stage
    pushfl
    pushal
    movl $\stage,%eax
    call capture_pcode
    popal
    popfl
.endm

.macro stage_hook name, target, argc, before, after
\name:
    .ifc \name,selection
        call function_name
    .endif
    .if \before
        snapshot \before
    .endif
    .if \argc
        .rept \argc
            pushl (4 * \argc)(%esp)
        .endr
    .endif
    original_call \target
    .if \argc
        leal (4 * \argc)(%esp),%esp
    .endif
    .if \after
        snapshot \after
    .endif
    ret
.endm

# Trace routines carry EDI = stderr handle. Each caller reserves a DWORD for
# WriteFile's count at frame offset zero, below the trace record.
trace_handle:
    pushl $-12
    call *get_std_handle
    movl %eax,%edi
    ret
write_record:
    leal 4(%esp),%eax
    pushl $0
    pushl %eax
    pushl %edx
    pushl %ecx
    pushl %edi
    call *write_file
    ret

function_name:
    pushfl
    pushal
    # CodeGen saves the compiler symbol's text pointer before instruction selection.
    movl function_name_stack(%esp),%esi
    subl $16,%esp
    call trace_handle
    movl $0x46334257,4(%esp) # WB3F
    xorl %ebx,%ebx
    testl %esi,%esi
    je name_length
name_loop:
    cmpb $0,(%esi,%ebx)
    je name_length
    incl %ebx
    cmpl $1024,%ebx
    jb name_loop
name_length:
    movl %ebx,8(%esp)
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    testl %ebx,%ebx
    je name_done
    movl %esi,%ecx
    movl %ebx,%edx
    call write_record
name_done:
    addl $16,%esp
    popal
    popfl
    ret

capture_pcode:
    subl $56,%esp
    movl %eax,8(%esp)
    call trace_handle
    movl $0x53334257,4(%esp) # WB3S
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    movl first_block,%ebp
    xorl %esi,%esi
    xorl %ebx,%ebx
    movl $0,48(%esp)
block_loop:
    testl %ebp,%ebp
    je pcode_done
    cmpl $8192,%esi
    jae block_limit
    # The backend links bound LabelRecords through block+8. Capture the
    # association even for empty blocks, without following operand pointers.
    movl 8(%ebp),%eax
label_loop:
    testl %eax,%eax
    je block_instructions
    cmpl $65536,48(%esp)
    jae label_limit
    incl 48(%esp)
    movl $0x4c334257,4(%esp) # WB3L
    movl %esi,8(%esp)
    movl %eax,12(%esp)
    movl (%eax),%eax
    movl %eax,44(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    movl 44(%esp),%eax
    jmp label_loop
block_instructions:
    movl 0x14(%ebp),%ecx
    movl %ecx,36(%esp)
instruction_loop:
    movl 36(%esp),%ecx
    testl %ecx,%ecx
    je next_block
    cmpl $65536,%ebx
    jae instruction_limit
    movzwl pcode_count(%ecx),%edx
    cmpl $256,%edx
    ja operand_limit
    imull $operand_size,%edx,%edx
    addl $pcode_size,%edx
    movl $0x50334257,4(%esp) # WB3P
    movl %esi,8(%esp)
    movl %ebx,12(%esp)
    movl %edx,16(%esp)
    movl %ecx,20(%esp)
    movzwl pcode_opcode(%ecx),%eax
    movl $0,40(%esp)
    xorl %edx,%edx
    cmpl $opcode_limit,%eax
    ja mnemonic_ready
    imull $44,%eax,%eax
    movl opcode_table(%eax),%ecx
    testl %ecx,%ecx
    je mnemonic_ready
    movl %ecx,40(%esp)
mnemonic_loop:
    cmpb $0,(%ecx,%edx)
    je mnemonic_ready
    incl %edx
    cmpl $64,%edx
    jb mnemonic_loop
mnemonic_ready:
    movl %edx,24(%esp)
    leal 4(%esp),%ecx
    movl $24,%edx
    call write_record
    movl 24(%esp),%edx
    testl %edx,%edx
    je write_instruction
    movl 40(%esp),%ecx
    call write_record
write_instruction:
    movl 36(%esp),%ecx
    movl 16(%esp),%edx
    call write_record
    movl 36(%esp),%eax
    call capture_operand_symbols
    incl %ebx
    movl 36(%esp),%ecx
    movl (%ecx),%ecx
    movl %ecx,36(%esp)
    jmp instruction_loop
next_block:
    incl %esi
    movl (%ebp),%ebp
    jmp block_loop
block_limit:
    movl $1,%eax
    jmp pcode_end
instruction_limit:
    movl $2,%eax
    jmp pcode_end
operand_limit:
    movl $3,%eax
    jmp pcode_end
label_limit:
    movl $4,%eax
    jmp pcode_end
pcode_done:
    xorl %eax,%eax
pcode_end:
    movl $0x45334257,4(%esp) # WB3E
    movl %ebx,8(%esp)
    movl %eax,12(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    addl $56,%esp
    ret

# Both profiles store a compiler object pointer at +6 of a tag-4 operand.
# Read its interned name directly. This avoids calling the compiler's symbol
# formatter, which can allocate and cache a mangled name.
capture_operand_symbols:
    pushl %esi
    pushl %ebx
    pushl %ebp
    subl $32,%esp
    leal pcode_size(%eax),%esi
    movzwl pcode_count(%eax),%ebp
    xorl %ebx,%ebx
operand_symbol_loop:
    cmpl %ebp,%ebx
    jae operand_symbols_done
    cmpb $4,(%esi)
    jne operand_symbol_next
    movl 6(%esi),%eax
    movl $16,%ecx
symbol_alias:
    testl %eax,%eax
    je operand_symbol_next
    cmpb $6,2(%eax)
    jne symbol_name
    movl 0x28(%eax),%eax
    decl %ecx
    jnz symbol_alias
    jmp operand_symbol_next
symbol_name:
    # Object types 0 through 5 and 8 carry an interned name at +8.
    cmpb $5,2(%eax)
    jbe symbol_base_name
    cmpb $8,2(%eax)
    jne operand_symbol_next
symbol_base_name:
    movl 8(%eax),%ecx
    testl %ecx,%ecx
    je operand_symbol_next
    addl $10,%ecx
    xorl %edx,%edx
symbol_length:
    cmpb $0,(%ecx,%edx)
    je symbol_ready
    incl %edx
    cmpl $1024,%edx
    jb symbol_length
    jmp operand_symbol_next
symbol_ready:
    testl %edx,%edx
    je operand_symbol_next
    movl $0x4e334257,4(%esp) # WB3N
    movl %ebx,8(%esp)
    movl %edx,12(%esp)
    movl %ecx,16(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    movl 16(%esp),%ecx
    movl 12(%esp),%edx
    call write_record
operand_symbol_next:
    incl %ebx
    addl $operand_size,%esi
    jmp operand_symbol_loop
operand_symbols_done:
    addl $32,%esp
    popl %ebp
    popl %ebx
    popl %esi
    ret

choice:
    pushal
    subl $32,%esp
    movl $0x44334257,4(%esp) # WB3D
    movswl 0x10(%ebx),%eax
    movl %eax,8(%esp)
    movswl 0x12(%ebx),%eax
    movl %eax,12(%esp)
    .if is_303
        movl %edx,16(%esp)
        movl 72(%esp),%eax
    .else
        movl %ebp,16(%esp)
        movl 68(%esp),%eax
    .endif
    movl %eax,20(%esp)
    call trace_handle
    leal 4(%esp),%ecx
    movl $20,%edx
    call write_record
    addl $32,%esp
    popal
    cmpw $-1,0x12(%ebx)
    ret

blocker:
    .if is_303
        cmpw $-1,0x12(%edi)
    .else
        cmpw $-1,0x12(%edx)
    .endif
    je blocker_continue
    pushal
    subl $32,%esp
    movl $0x42334257,4(%esp) # WB3B
    movswl 0x10(%ebx),%eax
    movl %eax,8(%esp)
    .if is_303
        movl %edi,%edx
    .endif
    movswl 0x10(%edx),%eax
    movl %eax,12(%esp)
    movswl 0x12(%edx),%eax
    movl %eax,16(%esp)
    movzwl 0x14(%edx),%eax
    movl %eax,20(%esp)
    call trace_handle
    leal 4(%esp),%ecx
    movl $20,%edx
    call write_record
    addl $32,%esp
    popal
blocker_continue:
    .if is_303
        movw 0x12(%edi),%cx
    .else
        movw 0x12(%edx),%cx
    .endif
    cmpw $-1,%cx
    ret

simplify:
    pushfl
    pushal
    subl $64,%esp
    call trace_handle
    movzbl register_class,%esi
    movl $0x47334257,4(%esp) # WB3G
    movl %esi,8(%esp)
    movl allocation_attempt,%eax
    movl %eax,12(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    addl $64,%esp
    popal
    popfl
    original_call simplify_target
    ret

.macro simplify_event name, node, reason
\name:
    pushal
    movl \node,%ebx
    movl $\reason,%eax
    call emit_simplification
    popal
    orw $2,0x14(\node)
    ret
.endm
    .if is_303
        simplify_event simplify_initial,%edx,0
        simplify_event simplify_pressure,%edx,1
    .else
        simplify_event simplify_initial,%eax,0
        simplify_event simplify_pressure,%ecx,1
    .endif
    simplify_event simplify_rescan,%edx,2

emit_simplification:
    # The pressure/rescan path can have live x87 values across this call.
    movl %esp,%esi
    subl $560,%esp
    andl $-16,%esp
    fxsave 32(%esp)
    movl $0x4d334257,4(%esp) # WB3M
    movl %eax,8(%esp)
    movswl 0x10(%ebx),%eax
    movl %eax,12(%esp)
    movswl 0x16(%ebx),%eax
    movl %eax,16(%esp)
    movl 0x0c(%ebx),%eax
    movl %eax,20(%esp)
    call trace_handle
    leal 4(%esp),%ecx
    movl $20,%edx
    call write_record
    fxrstor 32(%esp)
    movl %esi,%esp
    ret

retry:
    pushal
    subl $16,%esp
    movl $0x52334257,4(%esp) # WB3R
    movswl 0x10(%ebx),%edx
    movl %edx,8(%esp)
    movl %ecx,12(%esp)
    call trace_handle
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    addl $16,%esp
    popal
    .if is_303
        addl $0x19,(%esp)
        orl %eax,8(%esp)
    .else
        addl $0x17,(%esp)
        orl %eax,4(%esp)
    .endif
    ret

color:
    pushl 4(%esp)
    original_call color_target
    leal 4(%esp),%esp
    pushfl
    pushal
    subl $64,%esp
    movl $0x43334257,4(%esp) # WB3C
    movl %eax,8(%esp)
    movzbl register_class,%esi
    movl node_count(,%esi,4),%ebx
    movl physical_count(,%esi,4),%ecx
    movl %ebx,12(%esp)
    movl %ecx,16(%esp)
    cmpl $32767,%ebx
    ja graph_limit
    testl %ebx,%ebx
    je graph_limit
    cmpl %ebx,%ecx
    ja graph_limit
    movl graph_nodes,%ebp
    testl %ebp,%ebp
    je graph_limit
    cmpl $0,coalesce_parents
    je graph_limit
    call trace_handle
    leal 4(%esp),%ecx
    movl $16,%edx
    call write_record
    movl %ebp,%ecx
    imull $30,%ebx,%edx
    call write_record
    movl coalesce_parents,%ecx
    leal (,%ebx,2),%edx
    call write_record

    movl $0,24(%esp) # node index
    movl $0,28(%esp) # incidence count
edge_node_loop:
    movl 0x1a(%ebp),%esi
edge_loop:
    testl %esi,%esi
    je edge_next_node
    cmpl $524288,28(%esp)
    jae graph_limit
    incl 28(%esp)
    movl $0x49334257,4(%esp) # WB3I
    movl 24(%esp),%eax
    movl %eax,8(%esp)
    movzwl 0x0c(%esi),%eax
    movl %eax,12(%esp)
    movzwl 0x0e(%esi),%eax
    movl %eax,16(%esp)
    cmpl 24(%esp),%eax
    je edge_high
    movl 4(%esi),%esi
    jmp edge_write
edge_high:
    movl 8(%esi),%esi
edge_write:
    leal 4(%esp),%ecx
    movl $16,%edx
    call write_record
    jmp edge_loop
edge_next_node:
    addl $30,%ebp
    incl 24(%esp)
    cmpl %ebx,24(%esp)
    jb edge_node_loop
    movl $0x58334257,4(%esp) # WB3X
    movl 28(%esp),%eax
    movl %eax,8(%esp)
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    addl $64,%esp
    popal
    popfl
    ret

graph_limit:
    call trace_handle
    movl $0x21334257,4(%esp) # WB3!
    leal 4(%esp),%ecx
    movl $4,%edx
    call write_record
    addl $64,%esp
    popal
    popfl
    ret

schedule_select:
    pushfl
    pushal
    subl $40,%esp
    movl 80(%esp),%esi
    movl 84(%esp),%eax
    movl %eax,32(%esp)
    .if is_303
        movzwl 92(%esp),%ebp
    .else
        movzwl %bx,%ebp
    .endif
    movl %ebp,36(%esp)
    call trace_handle
    xorl %ebx,%ebx
schedule_ready_loop:
    testl %esi,%esi
    je schedule_ready_done
    cmpl $256,%ebx
    jae schedule_ready_done
    movl $0x51334257,4(%esp) # WB3Q
    movl 32(%esp),%eax
    movl %eax,8(%esp)
    movl 36(%esp),%eax
    movl %eax,12(%esp)
    movl 0x0c(%esi),%eax
    movl %eax,16(%esp)
    movl 0x14(%esi),%eax
    movl %eax,20(%esp)
    movl 0x18(%esi),%eax
    movl %eax,24(%esp)
    leal 4(%esp),%ecx
    movl $24,%edx
    call write_record
    movl (%esi),%esi
    incl %ebx
    jmp schedule_ready_loop
schedule_ready_done:
    addl $40,%esp
    popal
    popfl
    pushl 8(%esp)
    pushl 8(%esp)
    original_call schedule_select_target
    leal 8(%esp),%esp
    pushfl
    pushal
    subl $32,%esp
    movl %eax,%esi
    movl $0x56334257,4(%esp) # WB3V
    movl 76(%esp),%eax
    movl %eax,8(%esp)
    .if is_303
        movzwl 84(%esp),%eax
    .else
        movzwl %bx,%eax
    .endif
    movl %eax,12(%esp)
    xorl %eax,%eax
    testl %esi,%esi
    je schedule_select_write
    movl 0x0c(%esi),%eax
schedule_select_write:
    movl %eax,16(%esp)
    call trace_handle
    leal 4(%esp),%ecx
    movl $16,%edx
    call write_record
    addl $32,%esp
    popal
    popfl
    ret

schedule_issue:
    pushfl
    pushal
    subl $32,%esp
    movl 76(%esp),%eax
    movl $0x54334257,4(%esp) # WB3T
    movl %eax,8(%esp)
    movzwl pcode_opcode(%eax),%eax
    movl %eax,12(%esp)
    .if is_303
        movl 80(%esp),%eax
        movl %eax,16(%esp)
        movl 84(%esp),%ebx
    .else
        movl 84(%esp),%eax
        movl %eax,16(%esp)
    .endif
    movzwl %bx,%ebx
    movl %ebx,20(%esp)
    call trace_handle
    leal 4(%esp),%ecx
    movl $20,%edx
    call write_record
    addl $32,%esp
    popal
    popfl
    pushl 8(%esp)
    pushl 8(%esp)
    original_call schedule_issue_target
    leal 8(%esp),%esp
    ret

# 3.0.3 delay-slot filler: entry of the fall-through attempt for a conditional branch.
# EBX = target block, EBP = fall-through block, ESI = branch, [esp+4] = fall-through's first instruction,
# [esp+0x1c] = the branch's block (offsets before the hook's return address).
# Records why a fall-through fill can or cannot happen, then re-runs the displaced `cmp`.
.if is_303
fallthrough:
    pushal
    subl $48,%esp
    # Original ESP = ESP + 48 (frame) + 32 (pushal) + 4 (return address).
    movl $0x59334257,4(%esp) # WB3Y
    movl %esi,8(%esp)
    movl 88(%esp),%eax
    movl %eax,12(%esp)
    movl $-1,16(%esp)
    testl %ebp,%ebp
    je 1f
    movl 0xc(%ebp),%ecx
    testl %ecx,%ecx
    je 1f
    movl 8(%ecx),%ecx
    movl %ecx,16(%esp)
1:
    movl $0,20(%esp)
    movl $-1,24(%esp)
    movl $-1,28(%esp)
    testl %eax,%eax
    je 2f
    movl 0xc(%eax),%ecx
    movl %ecx,20(%esp)
    movzwl pcode_count(%eax),%ecx
    testl %ecx,%ecx
    je 2f
    pushl %eax
    original_call fill_safe
    addl $4,%esp
    movzbl %al,%eax
    movl %eax,28(%esp)
    movl 12(%esp),%eax
    movl 112(%esp),%ecx
    pushl %ecx
    pushl %eax
    original_call fill_live
    addl $8,%esp
    movzbl %al,%eax
    movl %eax,24(%esp)
2:
    movl %ebp,32(%esp)
    movl %ebx,36(%esp)
    call trace_handle
    leal 4(%esp),%ecx
    movl $36,%edx
    call write_record
    addl $48,%esp
    popal
    cmpl $0,8(%esp)
    ret
.endif

# Frontend IR: the Statement list and ENode trees that CodeGen hands to the IR
# optimizer and to the backend. EBX = function Object, ESI = Statement list at
# the hooked call site (both callee-saved there). The walker writes raw fixed-size
# copies of every reachable Statement, ENode, Object and Type, and the decoder
# rebuilds the trees from the pointers inside them. EBP counts the remaining node
# budget across the recursion.
.ifdef ir_stmt_size
.macro ir_hook name, target, argc, before, after, result
\name:
    .if \before
        pushfl
        pushal
        movl $\before,%eax
        call ir_capture
        popal
        popfl
    .endif
    .rept \argc
        pushl (4 * \argc)(%esp)
    .endr
    original_call \target
    leal (4 * \argc)(%esp),%esp
    .if \after
        pushfl
        pushal
        .if \result
            movl %eax,%esi
        .endif
        movl $\after,%eax
        call ir_capture
        popal
        popfl
    .endif
    ret
.endm

ir_capture:
    subl $48,%esp
    movl %eax,8(%esp)
    call trace_handle
    movl $0x4a334257,4(%esp) # WB3J
    movl %ebx,12(%esp)
    xorl %edx,%edx
    xorl %ecx,%ecx
    testl %ebx,%ebx
    je ir_name_length
    movl 8(%ebx),%ecx
    testl %ecx,%ecx
    je ir_name_length
    addl $10,%ecx
ir_name_loop:
    cmpb $0,(%ecx,%edx)
    je ir_name_length
    incl %edx
    cmpl $1024,%edx
    jb ir_name_loop
ir_name_length:
    movl %edx,16(%esp)
    movl %ecx,40(%esp)
    leal 4(%esp),%ecx
    movl $16,%edx
    call write_record
    movl 16(%esp),%edx
    testl %edx,%edx
    je ir_statements
    movl 40(%esp),%ecx
    call write_record
ir_statements:
    movl $ir_budget,%ebp
    xorl %ebx,%ebx
ir_statement_loop:
    testl %esi,%esi
    je ir_statements_done
    testl %ebp,%ebp
    jle ir_statements_done
    decl %ebp
    movl $0x4b334257,4(%esp) # WB3K
    movl %esi,8(%esp)
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    movl %esi,%ecx
    movl $ir_stmt_size,%edx
    call write_record
    # LABEL, GOTO, IFGOTO and IFNGOTO keep a CLabel in the label slot.
    movzbl 4(%esi),%eax
    cmpl $31,%eax
    ja 1f
    movl $ir_label_statements,%ecx
    btl %eax,%ecx
    jnc 1f
    movl ir_stmt_label(%esi),%eax
    call ir_label
1:
    cmpb $5,4(%esi)
    jne 1f
    movl ir_stmt_label(%esi),%eax
    call ir_switch
1:
    movl ir_stmt_expr(%esi),%eax
    xorl %ecx,%ecx
    call ir_node
    incl %ebx
    movl (%esi),%esi
    jmp ir_statement_loop
ir_statements_done:
    movl $0x5a334257,4(%esp) # WB3Z
    movl %ebx,8(%esp)
    xorl %eax,%eax
    testl %ebp,%ebp
    jg ir_status
    incl %eax
ir_status:
    movl %eax,12(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    addl $48,%esp
    ret

# EAX = CLabel. Raw prefix and its unique name.
ir_label:
    testl %eax,%eax
    je ir_label_done
    pushl %esi
    subl $24,%esp
    movl %eax,%esi
    xorl %edx,%edx
    xorl %ecx,%ecx
    .if ir_label_name >= 0
        movl ir_label_name(%esi),%ecx
        testl %ecx,%ecx
        je ir_label_name_ready
        addl $10,%ecx
ir_label_name_loop:
        cmpb $0,(%ecx,%edx)
        je ir_label_name_ready
        incl %edx
        cmpl $256,%edx
        jb ir_label_name_loop
        xorl %edx,%edx
    .endif
ir_label_name_ready:
    movl %ecx,16(%esp)
    movl %edx,12(%esp)
    movl $0x48334257,4(%esp) # WB3H
    movl %esi,8(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    movl %esi,%ecx
    movl $ir_label_size,%edx
    call write_record
    movl 12(%esp),%edx
    testl %edx,%edx
    je 1f
    movl 16(%esp),%ecx
    call write_record
1:
    addl $24,%esp
    popl %esi
ir_label_done:
    ret

# EAX = SwitchInfo: raw prefix, then each case (linked through +0) and its CLabel.
ir_switch:
    testl %eax,%eax
    je ir_switch_done
    pushl %esi
    subl $24,%esp
    movl %eax,%esi
    movl $0x63334257,4(%esp) # WB3c
    movl %esi,8(%esp)
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    movl %esi,%ecx
    movl $ir_switch_size,%edx
    call write_record
    movl ir_switch_default(%esi),%eax
    call ir_label
    movl ir_switch_cases(%esi),%esi
    movl $65536,20(%esp)
ir_case_loop:
    testl %esi,%esi
    je ir_switch_end
    decl 20(%esp)
    js ir_switch_end
    movl $0x6b334257,4(%esp) # WB3k
    movl %esi,8(%esp)
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    movl %esi,%ecx
    movl $ir_case_size,%edx
    call write_record
    movl ir_case_label(%esi),%eax
    call ir_label
    movl (%esi),%esi
    jmp ir_case_loop
ir_switch_end:
    addl $24,%esp
    popl %esi
ir_switch_done:
    ret

# EAX = Type. Writes its raw prefix once per reference.
ir_type:
    testl %eax,%eax
    je ir_type_done
    pushl %esi
    subl $16,%esp
    movl %eax,%esi
    movl $0x57334257,4(%esp) # WB3W
    movl %esi,8(%esp)
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    movl %esi,%ecx
    movl $ir_type_size,%edx
    call write_record
    addl $16,%esp
    popl %esi
ir_type_done:
    ret

# EAX = Object. Raw prefix, then its interned name when it has one.
ir_object:
    testl %eax,%eax
    je ir_object_done
    pushl %esi
    subl $24,%esp
    movl %eax,%esi
    xorl %edx,%edx
    xorl %ecx,%ecx
    cmpb $5,2(%esi)
    jbe ir_object_named
    cmpb $8,2(%esi)
    jne ir_object_name_ready
ir_object_named:
    movl 8(%esi),%ecx
    testl %ecx,%ecx
    je ir_object_name_ready
    addl $10,%ecx
ir_object_name_loop:
    cmpb $0,(%ecx,%edx)
    je ir_object_name_ready
    incl %edx
    cmpl $1024,%edx
    jb ir_object_name_loop
    xorl %edx,%edx
ir_object_name_ready:
    movl %ecx,16(%esp)
    movl %edx,12(%esp)
    movl $0x4f334257,4(%esp) # WB3O
    movl %esi,8(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    movl %esi,%ecx
    movl $ir_object_size,%edx
    call write_record
    movl 12(%esp),%edx
    testl %edx,%edx
    je ir_object_with_type
    movl 16(%esp),%ecx
    call write_record
ir_object_with_type:
    movl ir_object_type(%esi),%eax
    call ir_type
    addl $24,%esp
    popl %esi
ir_object_done:
    ret

# EAX = ENode, ECX = depth.
ir_node:
    testl %eax,%eax
    je ir_node_return
    testl %ebp,%ebp
    jle ir_node_return
    cmpl $ir_max_depth,%ecx
    jb ir_node_enter
    xorl %ebp,%ebp
    jmp ir_node_return
ir_node_enter:
    decl %ebp
    pushl %esi
    pushl %ebx
    subl $24,%esp
    movl %eax,%esi
    movl %ecx,%ebx
    movl $0x55334257,4(%esp) # WB3U
    movl %esi,8(%esp)
    movl %ebx,12(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    movl %esi,%ecx
    movl $ir_enode_size,%edx
    call write_record
    .if ir_enode_rtype >= 0
        movl ir_enode_rtype(%esi),%eax
        call ir_type
    .endif
    movzbl (%esi),%eax
    cmpl $128,%eax
    jae ir_node_done
    movzbl trace_base + (ir_child_table - trace_start)(%eax),%eax
    movl %eax,16(%esp)
    incl %ebx
    testb $16,16(%esp)
    je 1f
    movl ir_enode_data(%esi),%eax
    call ir_object
1:
    testb $1,16(%esp)
    je 1f
    movl ir_enode_data(%esi),%eax
    movl %ebx,%ecx
    call ir_node
1:
    testb $2,16(%esp)
    je 1f
    movl ir_enode_data+4(%esi),%eax
    movl %ebx,%ecx
    call ir_node
1:
    testb $4,16(%esp)
    je 1f
    movl ir_enode_data+8(%esi),%eax
    movl %ebx,%ecx
    call ir_node
1:
    testb $8,16(%esp)
    je ir_node_done
    # ENodeList: next at +0, node at +4.
    movl ir_enode_data+4(%esi),%esi
    movl $4096,20(%esp)
ir_list_loop:
    testl %esi,%esi
    je ir_node_done
    decl 20(%esp)
    js ir_node_done
    movl $0x41334257,4(%esp) # WB3A
    movl %esi,8(%esp)
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    movl %esi,%ecx
    movl $8,%edx
    call write_record
    movl 4(%esi),%eax
    movl %ebx,%ecx
    call ir_node
    movl (%esi),%esi
    jmp ir_list_loop
ir_node_done:
    addl $24,%esp
    popl %ebx
    popl %esi
ir_node_return:
    ret
.endif

# 3.0.3 IR optimizer log. The compiler keeps its IroDump.c writer; this opens its
# FILE on a path chosen by the tracer and enables it, and forces every
# IRO_DumpAfterPhase call to dump the flow graph.
.ifdef iro_log_flag
iro_log_open:
    pushfl
    pushal
    pushl $iro_log_mode
    pushl $trace_base + (iro_log_path - trace_start)
    original_call msl_fopen
    addl $8,%esp
    movl %eax,iro_log_file
    testl %eax,%eax
    je 1f
    movb $1,iro_log_flag
1:
    popal
    popfl
    ret
iro_phase:
    testl %esp,%esp
    ret

# Extra flow-graph dump after an optimizer call that the compiler does not label.
.macro iro_dump_hook name, target, label
\name:
    original_call \target
    pushfl
    pushal
    pushl $1
    pushl $trace_base + (\name\()_label - trace_start)
    original_call iro_dump_after_phase
    addl $8,%esp
    popal
    popfl
    ret
\name\()_label:
    .asciz "\label"
.endm
.endif
