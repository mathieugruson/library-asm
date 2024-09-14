; ssize_t read(int fd, void *buf, size_t count)

section .text
    global ft_read
    extern __errno_location


    ft_read:

        mov rax, 0          ; syscall number for read
        syscall

        cmp rax, 0          ; check for error
        jns .done

        push rax
        call __errno_location wrt ..plt ; Call __errno_location to get the address of errno (wrt ..plt to handle a error msg when compiling)

		pop rdi
        neg rdi         ; sys_write return the error with a negative sign as opposite to the one in errno.h because positive number are reserved to the number of char printed 
		mov [rax], rdi  ; call __errno_location return the adress of errno in rax so we need to put the error in the adress for errno to access it

		mov rax, -1     ; return -1 ; put -1 as in write function as rax is the return value
		ret

        .done:
        ret