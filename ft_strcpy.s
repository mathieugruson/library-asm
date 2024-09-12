section .text
global ft_strcpy

ft_strcpy:
    mov rax, 0        ; Clear rax (index)

.loop:
    
    mov dl, [rsi + rax] ; Load bit from [rsi] into dl
    mov [rdi + rax], dl ; Load bit from dl into dl to [rdi]

	cmp dl, 0 ; 

    jz .done            ; If zero, jump to done
	inc rax ; dest++
    jmp .loop           ; Repeat loop

.done:
	mov rax, rdi ; return = dest
    ret
