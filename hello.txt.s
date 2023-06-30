	.text
	.file	"minibasic"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
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
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	vars,@object            # @vars
	.local	vars
	.comm	vars,104,16
	.type	xe,@object              # @xe
	.local	xe
	.comm	xe,4,4
	.section	".note.GNU-stack","",@progbits
