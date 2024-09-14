section .text
global ft_strcmp

ft_strcmp:
    mov rax, 0           ; Clear rax (used as index for string comparison)

.loop:
    mov dl, [rdi + rax]  ; Load byte from the first string (s1) into dl
    mov dh, [rsi + rax]  ; Load byte from the second string (s2) into dh

    cmp dl, 0            ; Check if the current byte from s1 is null (end of string)
    jz .end_string       ; If end of s1, jump to end_string to determine result
    cmp dh, 0            ; Check if the current byte from s2 is null (end of string)
    jz .end_string       ; If end of s2, jump to end_string to determine result

    cmp dl, dh           ; Compare current bytes of s1 and s2
    jl .s1_lesser        ; If s1 byte is less than s2 byte, jump to s1_lesser
    jg .s1_greater       ; If s1 byte is greater than s2 byte, jump to s1_greater

    inc rax              ; Increment index (rax) to move to the next character
    cmp dl, dh           ; Compare the current bytes again (already compared in previous cmp, so redundant)
    jz .loop             ; If characters are equal, loop to compare the next characters

.end_string:
    cmp dl, dh           ; At end of one or both strings, compare final bytes
    jz .s1_equal         ; If they are equal, jump to s1_equal
    jl .s1_lesser        ; If s1 byte is less than s2 byte, jump to s1_lesser
    jg .s1_greater       ; If s1 byte is greater than s2 byte, jump to s1_greater

.s1_greater:
    mov rax, 1           ; Set return value to 1 (s1 is greater than s2)
    ret                  ; Return from function

.s1_lesser:
    mov rax, -1          ; Set return value to -1 (s1 is less than s2)
    ret                  ; Return from function

.s1_equal:
    mov rax, 0           ; Set return value to 0 (s1 is equal to s2)
    ret                  ; Return from function
