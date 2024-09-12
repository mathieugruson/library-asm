#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main() {
    
    int res = 0;
    char *msg = "Hello world!\n";
    res = ft_read(1, msg, 2);
    printf("res %d\n", res);
    perror("open");

    return 0;
}
