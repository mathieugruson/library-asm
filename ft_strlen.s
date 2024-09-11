section .data
    text db "He", 0    ; A null-terminated string

section .text
global _start

_start:
    ; Load the address of the string into RDI
    mov rdi, text

    ; Call ft_strlen
    call ft_strlen

    ; Store the result in EAX (number of characters) for exit code
    mov eax, 60               ; syscall number for exit
    syscall                  ; make the system call to exit

ft_strlen:

.count_loop:
    cmp byte [rdi], 0        ; Compare the byte at RDI with 0 (null terminator)
    je .done                 ; If zero, jump to the end
    inc rdi                  ; Move to the next character
    jmp .count_loop          ; Repeat the loop

.done:
    ret                      ; Return
