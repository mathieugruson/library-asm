; ssize_t write(int fd, const void *buf, size_t count);

section .text
    global ft_write
    extern __errno_location 

    ft_write:

        mov rax, 1          ; syscall number for write
        syscall ; not necessary to pass the arg rdi and rsi because they are already there. It is done automatically sometimes

		cmp rax, 0 ; check for error
        jns .done

		push rax
        call __errno_location wrt ..plt ; Call __errno_location to get the address of errno (wrt ..plt to handle a error msg when compiling)

        pop rdi                           ; rdi = error code
        neg rdi                           ; Make error code positive
        mov [rax], rdi                    ; Store the error in errno
		
        mov rax, -1 ; return -1 ; put -1 as in write function as rax is the return value
		ret
        
        .done:
            ret

; https://android.googlesource.com/kernel/lk/+/dima/for-travis/include/errno.h
; https://www.tortall.net/projects/yasm/manual/html/objfmt-elf64.html

