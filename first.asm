section .data

section .text
global _start

_start:
    mov eax, 1
    mov ebx, 5
    int 80h
