; int strcmp(const char *s1, const char *s2);

section .text
global ft_strcmp

ft_strcmp:
    mov rax, 0 ; clear rax (index)

.loop:

    mov dl, [rdi + rax] ; rdi = first arg
    mov dh, [rsi + rax] ; rsi = second arg

    cmp dl, 0
    jz .end_string
    cmp dh, 0
    jz .end_string

    cmp dl, dh
    jl .s1_lesser
    jg .s1_greater

    inc rax
    cmp dl, dh
    jz .loop

.end_string:
    cmp dl, dh
    jz .s1_equal
    jl .s1_lesser
    jg .s1_greater

.s1_greater:
    mov rax, 1
    ret

.s1_lesser:
    mov rax, -1
    ret

.s1_equal:
    mov rax, 0
    ret

