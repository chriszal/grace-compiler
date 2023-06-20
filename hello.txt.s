	.text
	.file	"minibasic"
	.globl	hello                   # -- Begin function hello
	.p2align	4, 0x90
	.type	hello,@function
hello:                                  # @hello
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$5, xe(%rip)
	movl	$5, %edi
	callq	writeInteger
	popq	%rax
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	hello, .Lfunc_end0-hello
	.cfi_endproc
                                        # -- End function
	.type	vars,@object            # @vars
	.local	vars
	.comm	vars,104,16
	.section	".note.GNU-stack","",@progbits
