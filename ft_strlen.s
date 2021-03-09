global ft_strlen	

ft_strlen:
	push	rcx						; call rcx on stack
	xor		rcx,	rcx				; rcx = 0;
	jmp		loop					; do loop

loop:
	cmp		BYTE [rdi + rcx], 0		; compare str[i] to '\0'
	je		end						; jump to loop if (str[i] == '\0')
	inc		rcx						; increment rcx
	jmp		loop					; jump to loop

end:
	mov		rax,	rcx				; ret = i;
	pop		rcx						; clean up the stack
	ret								; return (ret); / return (i);
