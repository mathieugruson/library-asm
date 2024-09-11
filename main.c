#include <stdio.h>
extern char *ft_strcpy(char *dest, const char *src);

int main() {
    char dest[100];
    const char *src = "He";
    ft_strcpy(dest, src);
    printf("Copied string: %s\n", dest);
    printf("Copied string: %d\n", 1);

    return 0;
}
