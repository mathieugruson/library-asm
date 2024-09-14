section .text
global ft_strcmp

ft_strcmp:
    mov rax, 0           ; Clear rax (used as index for string comparison)

.loop:
    mov dl, [rdi + rax]  ; Load byte from the first string (s1) into dl
    mov dh, [rsi + rax]  ; Load byte from the second string (s2) into dh

    cmp dl, 0            ; Check if the current byte from s1 is null (end of string)
    jz .end_string       ; If end of s1, jump to end_string to determine result

    cmp dl, dh           ; Compare current bytes of s1 and s2
    jne .end_string        ; If s1 byte is less than s2 byte, jump to s1_lesser

    inc rax              ; Increment index (rax) to move to the next character
    jmp .loop             ; If characters are equal, loop to compare the next characters

.end_string:
    sub dl, dh 
    movsx rax, dl          ; Set return value to -1 (s1 is less than s2)
    ret                  ; Return from function