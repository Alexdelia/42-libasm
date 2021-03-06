global	ft_write
extern	__errno_location		; Same as extern keyword in C

ft_write:
	push	rbx					; call rbx on the stack
	mov		rax,	1			; rax = 1 (syscall write)
	syscall
	test	rax,	rax			; if rax < 0 https://en.wikipedia.org/wiki/TEST_(x86_instruction)
	js		error_write			; if rax < 0, jump to error_write
	pop		rbx					; clean up the stack
	ret							; return

error_write:
	mov		rbx,	rax
	neg		rbx					; rbx = -rbx https://en.wikibooks.org/wiki/X86_Assembly/Arithmetic
	call	__errno_location wrt ..plt	; put rax at location of errno
	mov		[rax],	rbx			; errno = sys_error
	mov		rax, -1				; rax = -1;
	pop		rbx					; clean up the stack
	ret							; return
