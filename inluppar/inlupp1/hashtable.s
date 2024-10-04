	.file	"hashtable.c"
	.text
	.p2align 4
	.globl	ioopm_hash_table_create
	.type	ioopm_hash_table_create, @function
ioopm_hash_table_create:
.LFB30:
	.cfi_startproc
	endbr64
	movl	$136, %esi
	movl	$1, %edi
	jmp	calloc@PLT
	.cfi_endproc
.LFE30:
	.size	ioopm_hash_table_create, .-ioopm_hash_table_create
	.p2align 4
	.globl	ioopm_hash_table_destroy
	.type	ioopm_hash_table_destroy, @function
ioopm_hash_table_destroy:
.LFB31:
	.cfi_startproc
	endbr64
	testq	%rdi, %rdi
	je	.L3
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%rdi, %r14
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	leaq	136(%rdi), %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.p2align 4,,10
	.p2align 3
.L7:
	movq	(%r12), %rbx
	testq	%rbx, %rbx
	je	.L5
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%rbx, %rbp
	movq	16(%rbx), %rbx
	movq	8(%rbp), %rdi
	call	free@PLT
	movq	%rbp, %rdi
	call	free@PLT
	testq	%rbx, %rbx
	jne	.L6
.L5:
	movq	$0, (%r12)
	addq	$8, %r12
	cmpq	%r13, %r12
	jne	.L7
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 40
	movq	%r14, %rdi
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_restore 13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_restore 14
	.cfi_def_cfa_offset 8
	jmp	free@PLT
.L3:
	ret
	.cfi_endproc
.LFE31:
	.size	ioopm_hash_table_destroy, .-ioopm_hash_table_destroy
	.p2align 4
	.globl	ioopm_hash_table_insert
	.type	ioopm_hash_table_insert, @function
ioopm_hash_table_insert:
.LFB35:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movslq	%esi, %rax
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rax, %rbp
	imulq	$2021161081, %rax, %rax
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sarq	$35, %rax
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%rdx, 8(%rsp)
	movl	%ebp, %edx
	sarl	$31, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	sall	$4, %edx
	addl	%eax, %edx
	movl	%ebp, %eax
	subl	%edx, %eax
	movslq	%eax, %r14
	movq	(%rdi,%r14,8), %r13
	testq	%r13, %r13
	je	.L17
	movq	%r13, %rbx
	xorl	%edx, %edx
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L20:
	movq	16(%rbx), %rax
	movq	%rbx, %rdx
	testq	%rax, %rax
	je	.L19
	movq	%rax, %rbx
.L18:
	cmpl	(%rbx), %ebp
	jne	.L20
	xorl	%ebx, %ebx
	testq	%rdx, %rdx
	je	.L21
	movq	%rdx, %rbx
.L19:
	movq	16(%rbx), %r13
	testq	%r13, %r13
	je	.L22
.L21:
	cmpl	%ebp, 0(%r13)
	je	.L48
	movl	$24, %esi
	movl	$1, %edi
	call	calloc@PLT
	movq	%rax, %r15
	testq	%rax, %rax
	je	.L28
.L27:
	movl	%ebp, (%r15)
	movq	8(%rsp), %rdi
	call	strdup@PLT
	movq	%r13, 16(%r15)
	movq	%rax, 8(%r15)
.L28:
	testq	%rbx, %rbx
	je	.L29
.L26:
	movq	%r15, 16(%rbx)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
.L17:
	.cfi_restore_state
	movl	$24, %esi
	movl	$1, %edi
	call	calloc@PLT
	movq	%rax, %r15
	testq	%rax, %rax
	je	.L29
	movl	%ebp, (%rax)
	movq	8(%rsp), %rdi
	call	strdup@PLT
	movq	$0, 16(%r15)
	movq	%rax, 8(%r15)
.L29:
	movq	%r15, (%r12,%r14,8)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
.L48:
	.cfi_restore_state
	movq	8(%r13), %rdi
	call	free@PLT
	movq	8(%rsp), %rdi
	call	strdup@PLT
	movq	%rax, 8(%r13)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
.L22:
	.cfi_restore_state
	movl	$24, %esi
	movl	$1, %edi
	call	calloc@PLT
	movq	%rax, %r15
	testq	%rax, %rax
	jne	.L27
	jmp	.L26
	.cfi_endproc
.LFE35:
	.size	ioopm_hash_table_insert, .-ioopm_hash_table_insert
	.p2align 4
	.globl	ioopm_hash_table_lookup
	.type	ioopm_hash_table_lookup, @function
ioopm_hash_table_lookup:
.LFB37:
	.cfi_startproc
	endbr64
	movslq	%esi, %rax
	movl	%esi, %edx
	imulq	$2021161081, %rax, %rax
	sarl	$31, %edx
	sarq	$35, %rax
	subl	%edx, %eax
	movl	%eax, %edx
	sall	$4, %edx
	addl	%eax, %edx
	movl	%esi, %eax
	subl	%edx, %eax
	cltq
	movq	(%rdi,%rax,8), %rax
	testq	%rax, %rax
	jne	.L52
	ret
	.p2align 4,,10
	.p2align 3
.L51:
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L49
.L52:
	cmpl	(%rax), %esi
	jne	.L51
	movq	8(%rax), %rax
	ret
	.p2align 4,,10
	.p2align 3
.L49:
	ret
	.cfi_endproc
.LFE37:
	.size	ioopm_hash_table_lookup, .-ioopm_hash_table_lookup
	.p2align 4
	.globl	ioopm_hash_table_remove
	.type	ioopm_hash_table_remove, @function
ioopm_hash_table_remove:
.LFB38:
	.cfi_startproc
	endbr64
	movslq	%esi, %rax
	movl	%esi, %edx
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	imulq	$2021161081, %rax, %rax
	sarl	$31, %edx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	sarq	$35, %rax
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	subl	%edx, %eax
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%eax, %edx
	sall	$4, %edx
	addl	%eax, %edx
	movl	%esi, %eax
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	subl	%edx, %eax
	movslq	%eax, %rbp
	movq	(%rdi,%rbp,8), %r14
	testq	%r14, %r14
	je	.L68
	movq	%rdi, %r13
	movq	%r14, %rbx
	xorl	%r12d, %r12d
	jmp	.L59
	.p2align 4,,10
	.p2align 3
.L61:
	movq	16(%rbx), %rdx
	movq	%rbx, %r12
	testq	%rdx, %rdx
	je	.L60
	movq	%rdx, %rbx
.L59:
	cmpl	(%rbx), %esi
	jne	.L61
	testq	%r12, %r12
	jne	.L77
	cmpl	(%r14), %esi
	jne	.L57
	movq	8(%r14), %r15
	movq	%r15, %rdi
	call	strdup@PLT
	movq	%r15, %rdi
	movq	%rax, %r12
	movq	16(%r14), %rax
	movq	%rax, 0(%r13,%rbp,8)
	call	free@PLT
	movq	%r14, %rdi
	call	free@PLT
.L57:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r12, %rax
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
.L77:
	.cfi_restore_state
	movq	%r12, %rbx
.L60:
	movq	16(%rbx), %r14
	testq	%r14, %r14
	je	.L68
	xorl	%r12d, %r12d
	cmpl	(%r14), %esi
	jne	.L57
	movq	8(%r14), %r15
	movq	%r15, %rdi
	call	strdup@PLT
	movq	%r15, %rdi
	movq	%rax, %r12
	movq	16(%r14), %rax
	movq	%rax, 16(%rbx)
	call	free@PLT
	movq	%r14, %rdi
	call	free@PLT
	jmp	.L57
	.p2align 4,,10
	.p2align 3
.L68:
	xorl	%r12d, %r12d
	jmp	.L57
	.cfi_endproc
.LFE38:
	.size	ioopm_hash_table_remove, .-ioopm_hash_table_remove
	.p2align 4
	.globl	ioopm_hash_table_size
	.type	ioopm_hash_table_size, @function
ioopm_hash_table_size:
.LFB39:
	.cfi_startproc
	endbr64
	leaq	136(%rdi), %rcx
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L81:
	movq	(%rdi), %rax
	testq	%rax, %rax
	je	.L79
	.p2align 4,,10
	.p2align 3
.L80:
	movq	16(%rax), %rax
	addl	$1, %edx
	testq	%rax, %rax
	jne	.L80
.L79:
	addq	$8, %rdi
	cmpq	%rcx, %rdi
	jne	.L81
	movl	%edx, %eax
	ret
	.cfi_endproc
.LFE39:
	.size	ioopm_hash_table_size, .-ioopm_hash_table_size
	.p2align 4
	.globl	ioopm_hash_table_is_empty
	.type	ioopm_hash_table_is_empty, @function
ioopm_hash_table_is_empty:
.LFB40:
	.cfi_startproc
	endbr64
	leaq	136(%rdi), %rcx
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L90:
	movq	(%rdi), %rax
	testq	%rax, %rax
	je	.L88
	.p2align 4,,10
	.p2align 3
.L89:
	movq	16(%rax), %rax
	addl	$1, %edx
	testq	%rax, %rax
	jne	.L89
.L88:
	addq	$8, %rdi
	cmpq	%rcx, %rdi
	jne	.L90
	testl	%edx, %edx
	sete	%al
	ret
	.cfi_endproc
.LFE40:
	.size	ioopm_hash_table_is_empty, .-ioopm_hash_table_is_empty
	.p2align 4
	.globl	ioopm_hash_table_clear
	.type	ioopm_hash_table_clear, @function
ioopm_hash_table_clear:
.LFB41:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	leaq	136(%rdi), %r13
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	.p2align 4,,10
	.p2align 3
.L99:
	movq	(%r12), %rbx
	testq	%rbx, %rbx
	je	.L97
	.p2align 4,,10
	.p2align 3
.L98:
	movq	%rbx, %rbp
	movq	16(%rbx), %rbx
	movq	8(%rbp), %rdi
	call	free@PLT
	movq	%rbp, %rdi
	call	free@PLT
	testq	%rbx, %rbx
	jne	.L98
.L97:
	movq	$0, (%r12)
	addq	$8, %r12
	cmpq	%r13, %r12
	jne	.L99
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE41:
	.size	ioopm_hash_table_clear, .-ioopm_hash_table_clear
	.p2align 4
	.globl	ioopm_hash_table_keys
	.type	ioopm_hash_table_keys, @function
ioopm_hash_table_keys:
.LFB42:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rdi, %rcx
	leaq	136(%rdi), %rbp
	xorl	%edx, %edx
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	.p2align 4,,10
	.p2align 3
.L109:
	movq	(%rcx), %rax
	testq	%rax, %rax
	je	.L107
	.p2align 4,,10
	.p2align 3
.L108:
	movq	16(%rax), %rax
	addl	$1, %edx
	testq	%rax, %rax
	jne	.L108
.L107:
	addq	$8, %rcx
	cmpq	%rbp, %rcx
	jne	.L109
	movl	$4, %esi
	movslq	%edx, %rdi
	call	calloc@PLT
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L112:
	movq	(%rbx), %rdx
	testq	%rdx, %rdx
	je	.L110
	addl	$1, %esi
	movslq	%esi, %rcx
	.p2align 4,,10
	.p2align 3
.L111:
	movl	(%rdx), %esi
	movq	16(%rdx), %rdx
	movl	%esi, -4(%rax,%rcx,4)
	movq	%rcx, %rsi
	addq	$1, %rcx
	testq	%rdx, %rdx
	jne	.L111
.L110:
	addq	$8, %rbx
	cmpq	%rbp, %rbx
	jne	.L112
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE42:
	.size	ioopm_hash_table_keys, .-ioopm_hash_table_keys
	.p2align 4
	.globl	ioopm_hash_table_values
	.type	ioopm_hash_table_values, @function
ioopm_hash_table_values:
.LFB43:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%rdi, %rcx
	xorl	%edx, %edx
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	leaq	136(%rdi), %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.p2align 4,,10
	.p2align 3
.L127:
	movq	(%rcx), %rax
	testq	%rax, %rax
	je	.L125
	.p2align 4,,10
	.p2align 3
.L126:
	movq	16(%rax), %rax
	addl	$1, %edx
	testq	%rax, %rax
	jne	.L126
.L125:
	addq	$8, %rcx
	cmpq	%r13, %rcx
	jne	.L127
	movslq	%edx, %rdi
	movl	$8, %esi
	call	calloc@PLT
	movq	%rax, %r14
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L130:
	movq	(%r12), %rbx
	testq	%rbx, %rbx
	je	.L128
	addl	$1, %eax
	movslq	%eax, %rbp
	.p2align 4,,10
	.p2align 3
.L129:
	movq	8(%rbx), %rdi
	call	strdup@PLT
	movq	16(%rbx), %rbx
	movq	%rax, -8(%r14,%rbp,8)
	movq	%rbp, %rax
	addq	$1, %rbp
	testq	%rbx, %rbx
	jne	.L129
.L128:
	addq	$8, %r12
	cmpq	%r13, %r12
	jne	.L130
	popq	%rbx
	.cfi_def_cfa_offset 40
	movq	%r14, %rax
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE43:
	.size	ioopm_hash_table_values, .-ioopm_hash_table_values
	.p2align 4
	.globl	ioopm_hash_table_has_key
	.type	ioopm_hash_table_has_key, @function
ioopm_hash_table_has_key:
.LFB44:
	.cfi_startproc
	endbr64
	movslq	%esi, %rax
	movl	%esi, %edx
	imulq	$2021161081, %rax, %rax
	sarl	$31, %edx
	sarq	$35, %rax
	subl	%edx, %eax
	movl	%eax, %edx
	sall	$4, %edx
	addl	%eax, %edx
	movl	%esi, %eax
	subl	%edx, %eax
	cltq
	movq	(%rdi,%rax,8), %rax
	testq	%rax, %rax
	jne	.L145
	jmp	.L146
	.p2align 4,,10
	.p2align 3
.L144:
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L148
.L145:
	cmpl	(%rax), %esi
	jne	.L144
	cmpq	$0, 8(%rax)
	setne	%al
	ret
	.p2align 4,,10
	.p2align 3
.L148:
	ret
.L146:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE44:
	.size	ioopm_hash_table_has_key, .-ioopm_hash_table_has_key
	.p2align 4
	.globl	ioopm_hash_table_has_value
	.type	ioopm_hash_table_has_value, @function
ioopm_hash_table_has_value:
.LFB45:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	leaq	136(%rdi), %r13
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
.L153:
	movq	(%r12), %rbx
	testq	%rbx, %rbx
	jne	.L152
	jmp	.L150
	.p2align 4,,10
	.p2align 3
.L161:
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	je	.L150
.L152:
	movq	8(%rbx), %rsi
	movq	%rbp, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L161
	movl	$1, %eax
.L149:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L150:
	.cfi_restore_state
	addq	$8, %r12
	cmpq	%r13, %r12
	jne	.L153
	xorl	%eax, %eax
	jmp	.L149
	.cfi_endproc
.LFE45:
	.size	ioopm_hash_table_has_value, .-ioopm_hash_table_has_value
	.p2align 4
	.globl	ioopm_hash_table_all
	.type	ioopm_hash_table_all, @function
ioopm_hash_table_all:
.LFB46:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	leaq	136(%rdi), %r14
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rdx, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
.L166:
	movq	0(%r13), %rbx
	testq	%rbx, %rbx
	jne	.L165
	jmp	.L163
	.p2align 4,,10
	.p2align 3
.L176:
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	je	.L163
.L165:
	movq	8(%rbx), %rsi
	movl	(%rbx), %edi
	movq	%rbp, %rdx
	call	*%r12
	testb	%al, %al
	jne	.L176
.L162:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L163:
	.cfi_restore_state
	addq	$8, %r13
	cmpq	%r14, %r13
	jne	.L166
	movl	$1, %eax
	jmp	.L162
	.cfi_endproc
.LFE46:
	.size	ioopm_hash_table_all, .-ioopm_hash_table_all
	.p2align 4
	.globl	ioopm_hash_table_any
	.type	ioopm_hash_table_any, @function
ioopm_hash_table_any:
.LFB47:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	leaq	136(%rdi), %r14
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rdx, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
.L181:
	movq	0(%r13), %rbx
	testq	%rbx, %rbx
	jne	.L180
	jmp	.L178
	.p2align 4,,10
	.p2align 3
.L188:
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	je	.L178
.L180:
	movq	8(%rbx), %rsi
	movl	(%rbx), %edi
	movq	%rbp, %rdx
	call	*%r12
	testb	%al, %al
	je	.L188
.L177:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L178:
	.cfi_restore_state
	addq	$8, %r13
	cmpq	%r14, %r13
	jne	.L181
	xorl	%eax, %eax
	jmp	.L177
	.cfi_endproc
.LFE47:
	.size	ioopm_hash_table_any, .-ioopm_hash_table_any
	.p2align 4
	.globl	ioopm_hash_table_apply_to_all
	.type	ioopm_hash_table_apply_to_all, @function
ioopm_hash_table_apply_to_all:
.LFB48:
	.cfi_startproc
	endbr64
	testq	%rdi, %rdi
	je	.L200
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	testq	%rsi, %rsi
	je	.L189
	movq	%rdi, %r13
	movq	%rdx, %r12
	leaq	136(%rdi), %r14
	.p2align 4,,10
	.p2align 3
.L193:
	movq	0(%r13), %rbx
	testq	%rbx, %rbx
	je	.L191
	.p2align 4,,10
	.p2align 3
.L192:
	movl	(%rbx), %edi
	leaq	8(%rbx), %rsi
	movq	%r12, %rdx
	call	*%rbp
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L192
.L191:
	addq	$8, %r13
	cmpq	%r14, %r13
	jne	.L193
.L189:
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L200:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	.cfi_restore 14
	ret
	.cfi_endproc
.LFE48:
	.size	ioopm_hash_table_apply_to_all, .-ioopm_hash_table_apply_to_all
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
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
