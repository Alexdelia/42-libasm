global ft_read
extern __errno_location		; Same as extern keyword in C
extern error

ft_read:
	push	rbx				; call rbx on the stack
	mov		rax,	0		; rax = 0 (syscall read)
	syscall
	test	rax,	rax		; if rax < 0 https://en.wikipedia.org/wiki/TEST_(x86_instruction)
	js		error_read		; if rax < 0, jump to error_read
	pop		rbx				; clean up the stack
	ret						; return

error_read:
	mov		rbx,	rax
	neg		rbx				; rbx = -rbx https://en.wikibooks.org/wiki/X86_Assembly/Arithmetic
	call	__errno_location wrt ..plt	; put rax at location of errno
	mov		[rax],	rbx		; errno = sys_error
	mov		rax,	-1		; rax = -1
	pop		rbx				; clean up the stack
	ret						; return
