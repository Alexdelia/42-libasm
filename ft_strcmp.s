global ft_strcmp

ft_strcmp:
	push	rdx						; call rcx on the stack
	push	rcx						; call rdx on the stack
	xor		rax,	rax				; rax = 0;
	xor		rdx,	rdx				; rcx = 0;
	xor		rcx,	rcx				; rcx = 0;
	jmp		loop					; jump to loop

loop:
	mov		bl, BYTE [rsi + rcx]
	cmp		BYTE [rdi + rcx], dl
	jne		end
	cmp		BYTE [rsi + rcx], 0
	je		end
	cmp		BYTE [rdi + rcx], 0
	je		end
	inc		rcx						; after comparing all case increment rcx
	jmp		loop					; and jump to start of loop

end:
	mov		al, BYTE [rdi + rcx]	; first 8 bits of rax set to rdi[rcx]
	sub		rax, rdx				; rax = rax - rdx
	ret								; return rax
