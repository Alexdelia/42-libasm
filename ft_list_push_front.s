global ft_list_push_front
extern malloc

ft_list_push_front:
	push	rsp				; call rsp on Stack
	push	rdi				; call rdi (t_list **begin) on Stack
	push	rsi				; call rsi (void *data) on Stack
	mov		rdi,	16		; rdi = 16
	mov		rax,	rax		; rax = 0
	call	malloc			; rax = malloc(16)
	pop		rsi				; clean up rsi from Stack
	pop		rdi				; clean up rdi from Stack
	cmp		rax,	0		; if malloc return 0
	jz		end				; then jump to end
	mov		[rax], rsi		; new.data = data
	mov		rcx, [rdi]		; rcx = *begin
	mov		[rax + 8],	rcx	; new.next = *begin
	mov		[rdi], rax		; *begin = new
	jmp		end				; jump to end

end:
	pop		rsp				; clean up rsp from Stack

ret
