section .text
    global add_two_numbers   ; This makes the function accessible from C

add_two_numbers:
    ; Arguments are passed via registers in the System V AMD64 ABI (for Linux/Unix)
    ; - First argument (int a) is in rdi
    ; - Second argument (int b) is in rsi

    mov rax, rdi   ; Move the first argument (a) into rax
    add rax, rsi   ; Add the second argument (b) to rax

    ret            ; Return, with the result in rax
