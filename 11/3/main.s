	.file	"main.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "all good\0"
.LC1:
	.ascii "something's wrong\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movl	$10, -36(%rbp)
	movl	$10, -40(%rbp)
	movl	$10, -4(%rbp)
	movabsq	$7074718926913495398, %rax
	movq	%rax, -51(%rbp)
	movl	$7235938, -44(%rbp)
	movabsq	$7955998168185922937, %rax
	movq	%rax, -60(%rbp)
	movb	$0, -52(%rbp)
	movl	-36(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	movl	-40(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -32(%rbp)
	movl	-36(%rbp), %ecx
	movq	-16(%rbp), %rdx
	leaq	-51(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	movl	-4(%rbp), %ecx
	movq	-32(%rbp), %rdx
	leaq	-51(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	movl	-36(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -36(%rbp)
	leaq	-36(%rbp), %rdx
	leaq	-51(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	%rax, -16(%rbp)
	movl	-40(%rbp), %ecx
	movq	-24(%rbp), %rdx
	leaq	-60(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	leaq	-40(%rbp), %rdx
	leaq	-60(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	%rax, -32(%rbp)
	leaq	-40(%rbp), %rdx
	leaq	-51(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	%rax, -24(%rbp)
	movq	.refptr.readCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L2
	movq	.refptr.writeCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L3
.L2:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L3:
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movl	%edx, 40(%rbp)
	movl	$0, %ecx
	call	_time64
	movl	%eax, %ecx
	call	srand
	movl	$0, -4(%rbp)
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -4(%rbp)
.L6:
	movl	-4(%rbp), %eax
	cmpl	40(%rbp), %eax
	jl	.L7
	nop
	nop
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "Array elements:\0"
.LC3:
	.ascii "%d. %d\12\0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, -4(%rbp)
	jmp	.L9
.L10:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L9:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L10
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.1.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.writeCount, "dr"
	.globl	.refptr.writeCount
	.linkonce	discard
.refptr.writeCount:
	.quad	writeCount
	.section	.rdata$.refptr.readCount, "dr"
	.globl	.refptr.readCount
	.linkonce	discard
.refptr.readCount:
	.quad	readCount
