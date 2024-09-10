section .data
    num DB 1
    num2 DB 2
section .text
global _start

_start:
    MOV bl, [num]
    MOV cl, [num2]
    MOV eax, 1
    INT 80h