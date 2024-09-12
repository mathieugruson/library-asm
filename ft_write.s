; ssize_t write(int fd, const void *buf, size_t count);

section .text
global ft_write
extern __errno_location

ft_write:
    mov rax, 1          ; syscall number for write
    syscall
    js .error           ; Check if there was an error (set sign flag)
    ret
.error:
    mov rdi, qword [rel __errno_location] ; Load address of errno
    mov dword [rdi], eax ; Store error code in errno
    ret

