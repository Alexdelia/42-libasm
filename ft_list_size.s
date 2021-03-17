global ft_list_size

ft_list_size:
	mov		rsi,	rdi		; rsi = rdi (begin)
	xor		rax,	rax		; rax = 0
	jmp		loop			; jump to loop

loop:
	cmp		rdi,	0		; if rdi == 0 (if begin == NULL)
	jz		end				; then jump to end
	mov		rdi, [rdi + 8]	; begin = begin.next
	inc		rax				; rax++
	jmp		loop			; jmp back to start of loop until begin == NULL

end:
	mov		rdi,	rsi		; rdi = rsi (reput rdi to begin)
	ret						; return rax which is the number of loop so the number of list
