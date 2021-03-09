global ft_strcpy

ft_strcpy:
	push	rcx						; call rcx on the Stack
	push	rdx						; call rdx on the Stack (tmp)
	xor		rcx,	rcx				; rcx = 0
	jmp		loop					; jump to loop

loop:
	cmp		BYTE [rsi + rcx],	0	; compare src[i] = '\0'
	je		end						; if equal, jump to end
	mov		dl,	BYTE [rsi + rcx]	; first 8 bits of rdx (tmp) = src[i]
	mov		[rdi + rcx],	dl		; dest[i] = dl (tmp)
	inc		rcx						; i++
	jmp		loop					; jump to loop

end:
	mov		BYTE [rdi + rcx],	0	; dest[i] = '\0'
	mov		rax,	rdi				; value rax (return) = dest
	pop		rdx						; clean up the Stack
	pop		rcx
	ret								; return rax (dest)
