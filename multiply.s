section .text
    global multiply_two_numbers   ; Make the function accessible from C

multiply_two_numbers:
    mov rax, rdi   ; Move the first argument (a) into rax
    imul rax, rsi  ; Multiply rax by the second argument (b)
    ret            ; Return the result in rax
