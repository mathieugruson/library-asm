section .text
    global ft_strlen

    ft_strlen:

    mov rax, 0 ; Clear rax, will be used to store the length (xor rax, rax is the same)


    .loop:
        cmp byte [rdi + rax], 0      ; Compare current byte to null terminator
        je .done                     ; If null terminator is found, exit the loop
        inc rax                      ; Increment rax (string length counter)
        jmp .loop                    ; Repeat the loop

    .done:
        ret                      ; Return the length in rax