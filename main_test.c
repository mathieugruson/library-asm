#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

extern int ft_strcmp(const char *s1, const char *s2);

int main() {
    
    errno = 0;
    ft_strcmp("mB", "mBa");

    return 0;
}
