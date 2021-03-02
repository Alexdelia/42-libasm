.global ft_strlen	

ft_strlen:
	push	rcx						; call rcx on stack
	dec		rcx						; decrement rcx
	jmp		loop					; do loop

loop:
	inc		rcx						; increment rcx
	cmp		byte[rcx + rdi], 0x0	; compare str[i] to '\0'
	je		loop					; jump to loop if (str[i] == '\0')
	
end:
	pop		rbp						; clean up the stack
	ret		rcx						; return rcx
