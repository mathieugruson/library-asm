#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>  // For open()

extern char ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);

int main(int argc, char *argv[]) {

    char *option = "\0";

    if (argc > 1) {
        option = argv[1];
    } 

    if (strcmp(option, "-ft_read") == 0 || strcmp(option, "-all") == 0) {
        
        int fd;
        ssize_t res = 0;
        char buffer[100];
        memset(buffer, 0, sizeof(buffer));

        fd = open("./info.txt", O_RDONLY);
        if (fd < 0) {
            perror("Failed to open file");
            return 1;
        }

        errno = 0;
        res = read(fd, buffer, 30);
        printf("read res %ld\n", res);
        printf("read buffer %s\n", buffer);
        perror("perror read");

        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = 0;
        res = ft_read(fd, buffer, 30);
        printf("ft_read res %ld\n", res);
        printf("ft_read buffer %s\n", buffer);
        perror("perror ft_read");

        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = read(50000, buffer, 30);
        printf("read res %ld\n", res);
        printf("read buffer %s\n", buffer);
        perror("perror read");
    
        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = 0;
        res = ft_read(50000, buffer, 30);
        printf("ft_read res %ld\n", res);
        printf("ft_read buffer %s\n", buffer);
        perror("perror ft_read");


    }


    if (strcmp(option, "-ft_write") == 0 || strcmp(option, "-all") == 0) {

        char *src = NULL;
        char *msg = "Hello world!\n";

        errno = 0;
        printf("write ret = %ld\n", write(1, src, 2));
        perror("perror write");
        errno = 0;
        printf("ft_write ret = %ld\n", ft_write(1, src, 2));
        perror("perror ft_write");

        errno = 0;
        printf("write ret = %ld\n", write(150000000, src, 2));
        perror("perror write");
        errno = 0;
        printf("ft_write ret = %ld\n", ft_write(150000000, src, 2));
        perror("perror ft_write");

        errno = 0;
        printf("write ret = %ld\n", write(1, msg, 6));
        perror("perror write");
        errno = 0;
        printf("ft_write ret = %ld\n", ft_write(1, msg, 6));
        perror("perror ft_write");

    } 

    if (strcmp(option, "-ft_strcpy") == 0 || strcmp(option, "-all") == 0) {

        char dest[100];
        const char *src = "He";
        ft_strcpy(dest, src);
        printf("Copied string: %s\n", dest);
        printf("Copied string: %d\n", 1);

    } 
    
    if (strcmp(option, "-ft_strcpy") == 0 || strcmp(option, "-all") == 0) {
    
    /* int strcmp(const char *s1, const char *s2);
     Cette fonction compare chaque caractere, lorsqu'il y a une difference, elle fait une soustraction et renvoie : 
        • 0, if the s1 and s2 are equal;
        • a negative value if s1 is less than s2;
        • a positive value if s1 is greater than s2.
     De sorte que si une est plus courte, alors on soustraira avec 0, mais si meme length et differente, ca compare la position du caractere
     sur la table ascii
    */

        int strcmp_result = 0;
        int ft_strcmp_result = 0;

        strcmp_result = strcmp("B", "A");
        printf("strcmp 2 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("B", "A");
        printf("ft_strcmp 2 result %d\n", ft_strcmp_result);

        strcmp_result = strcmp("B", "B");
        printf("strcmp 3 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("B", "B");
        printf("ft_strcmp 3 result %d\n", ft_strcmp_result);
        
        strcmp_result = strcmp("B", "C");
        printf("strcmp 4 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("B", "C");
        printf("ft_strcmp 4 result %d\n", ft_strcmp_result);

        strcmp_result = strcmp("mB", "mA");
        printf("strcmp 5 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("mB", "mA");
        printf("ft_strcmp 5 result %d\n", ft_strcmp_result);

        strcmp_result = strcmp("mB", "mB");
        printf("strcmp 6 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("mB", "mB");
        printf("ft_strcmp 6 result %d\n", ft_strcmp_result);

        strcmp_result = strcmp("mB", "mC");
        printf("strcmp 7 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("mB", "mC");
        printf("ft_strcmp 7 result %d\n", ft_strcmp_result);

        strcmp_result = strcmp("mB", "mAka");
        printf("strcmp 8 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("mB", "mAka");
        printf("ft_strcmp 8 result %d\n", ft_strcmp_result);

        strcmp_result = strcmp("mB", "mBa");
        printf("strcmp 9 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("mB", "mBa");
        printf("ft_strcmp 9 result %d\n", ft_strcmp_result);

        strcmp_result = strcmp("mBa", "mB");
        printf("strcmp 10 result %d\n", strcmp_result);
        ft_strcmp_result = ft_strcmp("mBa", "mB");
        printf("ft_strcmp 10 result %d\n", ft_strcmp_result);
    
    }
    
    return 0;
}
