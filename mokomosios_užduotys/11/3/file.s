	.file	"file.c"
	.text
	.globl	readCount
	.bss
	.align 4
readCount:
	.space 4
	.globl	writeCount
	.align 4
writeCount:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii "wb\0"
	.align 8
.LC1:
	.ascii "Could not open the following file: %s\12\0"
	.text
	.globl	saveToFile
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.seh_proc	saveToFile
saveToFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	16(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L2
	movq	16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L1
.L2:
	movq	-8(%rbp), %rdx
	leaq	32(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	movl	32(%rbp), %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rcx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	movl	writeCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, writeCount(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
.L1:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "rb\0"
.LC3:
	.ascii "Memory allocation failed!\0"
	.align 8
.LC4:
	.ascii "Could not read data from the following file: %s\12\0"
	.text
	.globl	loadFromFile
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.seh_proc	loadFromFile
loadFromFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L5
	movq	16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	jmp	.L6
.L5:
	movq	-8(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L7
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$0, %eax
	jmp	.L6
.L7:
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	movl	%eax, -20(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	je	.L8
	movq	16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, %eax
	jmp	.L6
.L8:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	readCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, readCount(%rip)
	movq	-16(%rbp), %rax
.L6:
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
