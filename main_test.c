#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main() {
    
    char *msg = "He";
    errno = 0;
    ft_write(500000, msg, 2);

    return 0;
}
