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
    subl $48,%esp
    movl %eax,8(%esp)
    call trace_handle
    movl $0x53334257,4(%esp) # WB3S
    leal 4(%esp),%ecx
    movl $8,%edx
    call write_record
    movl first_block,%ebp
    xorl %esi,%esi
    xorl %ebx,%ebx
block_loop:
    testl %ebp,%ebp
    je pcode_done
    cmpl $8192,%esi
    jae block_limit
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
pcode_done:
    xorl %eax,%eax
pcode_end:
    movl $0x45334257,4(%esp) # WB3E
    movl %ebx,8(%esp)
    movl %eax,12(%esp)
    leal 4(%esp),%ecx
    movl $12,%edx
    call write_record
    addl $48,%esp
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
