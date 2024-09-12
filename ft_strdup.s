section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    push rdi                  ; save pointer to string for later

    call ft_strlen            ; get length of original string
    add rax, 1                ; include space for terminating null byte

    mov rdi, rax              ; prepare argument for malloc
    call malloc wrt ..plt     ; allocate memory

    cmp rax, 0                ; check if malloc succeeded
    jz .end                   ; if not, skip to end and return NULL

    pop rdi                   ; restore original string pointer
    mov rsi, rdi              ; source string for copy
    mov rdi, rax              ; destination for copy (malloc'd memory)
    call ft_strcpy            ; perform the string copy

.end:
    ret                       ; return the address of the duplicated string (or NULL)
