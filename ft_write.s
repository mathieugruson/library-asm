; ssize_t write(int fd, const void *buf, size_t count);

section .text
    global ft_write
    extern __errno_location 

    ft_write:

        mov rax, 1          ; syscall number for write
        syscall ; not necessary to pass the arg. It is done automatically sometimes

		cmp rax, 0 ; check for error
        jl .errno           ; Check if there was an error (set sign flag)
        ret

	.errno:
		mov rdi, rax ; rdi = error code
        call __errno_location wrt ..plt ; Call __errno_location to get the address of errno (wrt ..plt to handle a error msg when compiling)

		neg rdi ; sys_write return the error with a negative sign as opposite to the one in errno.h because positive number are reserved to the number of char printed 
		mov [rax], rdi ; call __errno_location return the adress of errno in rax so we need to put the error in the adress for errno to access it

		mov rax, -1 ; return -1 ; put -1 as in write function as rax is the return value
		ret


; https://android.googlesource.com/kernel/lk/+/dima/for-travis/include/errno.h
; https://www.tortall.net/projects/yasm/manual/html/objfmt-elf64.html

