global ft_strcmp

ft_strcmp:
	push	rcx							; call rcx on the stack
	push	rbx							; call rbx on the stack
	xor		rax,	rax					; rax = 0;
	xor		rcx,	rcx					; rcx = 0;
	jmp		loop						; jump to loop

loop:
	mov		al,		BYTE [rdi + rcx]	; first 8 bits of rax = s1[i]
	mov		bl,		BYTE [rsi + rcx]	; first 8 bits of rbx = s2[i]
	cmp		al, 	0					; compare s1[i] == '\0'
	je		end							; if equal (s1[i] == '\0') jump to end
	cmp		bl,		0					; compare s2[i] == '\0'
	je		end							; if equal (s2[i] == '\0') jump to end
	cmp		al,		bl					; if al == bl
	jne		end							; if not equal, jump to end
	inc		rcx							; rcx++
	jmp		loop						; jump to loop

end:
	movzx	rbx,	bl					; rbx = bl  here is why mvzx: https://en.wikibooks.org/wiki/X86_Assembly/Data_Transfer
	movzx	rax,	al					; rax = al
	sub		rax,	rbx					; rax = rax - rdx
	pop		rcx							; clean up the stack
	pop		rbx							; clean up the stack
	ret									; return rax
