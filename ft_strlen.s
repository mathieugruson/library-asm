section .data
    text db "Hello, world!", 0    ; A null-terminated string

section .text
global _start

_start:
    ; Load the address of the string into RDI
    mov rdi, text

    ; Call ft_strlen
    call ft_strlen

    ; Store the result in EAX (number of characters) for exit code
    mov eax, 1               ; syscall number for exit
    mov edi, eax             ; exit code (number of characters returned from ft_strlen)
    syscall                  ; make the system call to exit

ft_strlen:
    xor rcx, rcx             ; Clear counter register (RCX)

.count_loop:
    cmp byte [rdi], 0        ; Compare the byte at RDI with 0 (null terminator)
    je .done                 ; If zero, jump to the end
    inc rdi                  ; Move to the next character
    inc rcx                  ; Increment the counter
    jmp .count_loop          ; Repeat the loop

.done:
    mov rax, rcx             ; Move the counter value to RAX (return value)
    ret                      ; Return
