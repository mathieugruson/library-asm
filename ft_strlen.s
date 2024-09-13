section .text
    global ft_strlen

    ft_strlen:

    mov rax, 0

    .count_loop:
        cmp byte [rdi + rax], 0        ; Compare the byte at RDI with 0 (null terminator)
        je .done                 ; If zero, jump to the end
        inc rax                  ; Move to the next character
        jmp .count_loop          ; Repeat the loop

    .done:
        ret                      ; Return
