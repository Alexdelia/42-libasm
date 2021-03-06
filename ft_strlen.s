global ft_strlen	

ft_strlen:
	push	rcx						; call rcx on stack
	xor		rcx,	rcx				; rcx = 0;
	jmp		loop					; do loop

loop:
	inc		rcx						; increment rcx
	cmp		byte [rcx + rdi], 0x0	; compare str[i] to '\0'
	je		loop					; jump to loop if (str[i] == '\0')
	mov		rax,	rcx				; ret = i;
	pop		rbp						; clean up the stack
	ret								; return (ret); / return (i);
