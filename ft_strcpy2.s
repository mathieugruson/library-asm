;char	*ft_strcpy(char *dest, const char *src);

section .text
	global ft_strcpy

	ft_strcpy:
		mov rax, rdi ; return = dest

	.loop:
		mov	dl, [rsi] ; dl = *src
		mov [rdi], dl ; *dest = *src

		test dl, dl ; if (*src == 0)
		jz .end

		inc rdi ; dest++
		inc rsi ; src++
		jmp .loop

	.end:
		ret

section .note.GNU-stack