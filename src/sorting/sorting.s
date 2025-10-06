	.file	"sorting.c"
	.text
	.p2align 4
	.globl	mergeSort
	.type	mergeSort, @function
mergeSort:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%edx, %ebx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	cmpl	%ecx, %ebx
	je	.L21
	movl	%ecx, %r14d
	movl	%ecx, %ebp
	movl	%ebx, %edx
	movq	%rsi, 8(%rsp)
	subl	%ebx, %r14d
	shrl	%r14d
	addl	%ebx, %r14d
	movl	%r14d, %ecx
	leal	1(%r14), %r12d
	call	mergeSort
	movq	8(%rsp), %rsi
	movq	%r13, %rdi
	movl	%ebp, %ecx
	movl	%r12d, %edx
	movq	%rax, %r15
	call	mergeSort
	movq	8(%rsp), %rsi
	cmpq	%r15, %r13
	movq	%rax, %rdi
	cmove	%rsi, %r13
	cmpl	%ebx, %ebp
	jb	.L5
	movl	%ebx, %eax
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L22:
	movl	%ebx, %edx
	movl	(%r15,%rdx,4), %esi
	movl	%r12d, %edx
	movl	(%rdi,%rdx,4), %edx
	cmpl	%edx, %esi
	jge	.L19
	addl	$1, %ebx
	movl	%esi, %edx
.L8:
	addl	$1, %eax
	movl	%edx, (%rcx)
	cmpl	%eax, %ebp
	jb	.L5
.L10:
	movl	%eax, %edx
	leaq	0(%r13,%rdx,4), %rcx
	cmpl	%ebx, %r14d
	jb	.L9
	cmpl	%r12d, %ebp
	jnb	.L22
	cmpl	%ebx, %r14d
	jb	.L9
	movl	%ebx, %edx
	addl	$1, %eax
	addl	$1, %ebx
	movl	(%r15,%rdx,4), %edx
	movl	%edx, (%rcx)
	cmpl	%eax, %ebp
	jnb	.L10
.L5:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r13, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	.cfi_restore_state
	movl	%r12d, %edx
	movl	(%rdi,%rdx,4), %edx
.L19:
	addl	$1, %r12d
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L21:
	movl	(%rdi,%rbx,4), %eax
	movl	%eax, (%rsi,%rbx,4)
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	movq	%rsi, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	mergeSort, .-mergeSort
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
