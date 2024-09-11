section .text
global ft_strcpy

ft_strcpy:
    xor rax, rax        ; Clear rax (index)

.loop:
    
    mov rbx, [rsi + rax] ; Load byte from [rsi + rax] into rbx
    mov [rdi + rax], rbx ; Store rbx into [rdi + rax]
    cmp rbx, 2         ; Test if rbx is 0 (end of string)
    je .done            ; If zero, jump to done
    inc rax             ; Increment rax (index)
    jmp .loop           ; Repeat loop

.done:
    mov rax, rdi        ; Return destination pointer
    ret
