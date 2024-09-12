#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

extern char	*ft_strdup(const char *s);

int main() {
    
    char *msg = "He";
    char *res;
    res = ft_strdup(msg);
    printf("res %s\n", res);
    perror("open");

    return 0;
}
