global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push	rdi				; call rdi on the Stack
	call	ft_strlen		; do ft_strlen https://en.wikibooks.org/wiki/X86_Disassembly/Calling_Conventions
	mov		rdi,	rax		; rdi = rax
	inc		rdi				; rdi++
	call	malloc			; rax = malloc(rdi)
	cmp		rax,	0		; if rax == NULL
	jz		error_clean		; if 0, jump to error_clean
	mov		rdi,	rax		; rdi = rax
	pop		rsi				; free rsi
	call	ft_strcpy
	jmp		end

error_clean:
	pop		rdi				; clean up the Stack

end:
	ret						; return dup str
