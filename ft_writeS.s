	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 15
	.globl	_ft_write               ## -- Begin function ft_write
	.p2align	4, 0x90
_ft_write:                              ## @ft_write
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$1, %edi
	leaq	L_.str(%rip), %rsi
	movl	$11, %edx
	callq	_write
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello world"


.subsections_via_symbols
