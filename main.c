#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>  // For open()
#include <stdlib.h>
#include <stdint.h>

extern char ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern size_t ft_strlen(const char *s);
extern char *ft_strdup(const char *s);

int main(int argc, char *argv[]) {

    char *option = "\0";

    if (argc > 1) {
        option = argv[1];
    }

    // OK
    if (strcmp(option, "-ft_strlen") == 0 || strcmp(option, "-all") == 0) {

        char *null = NULL ;
        
        printf("strlen test 1 %ld\n", strlen("Hello world!"));
        printf("ft_strlen test 1 %ld\n", ft_strlen("Hello world!"));
        printf("strlen test 2 %ld\n", strlen(""));
        printf("ft_strlen test 2 %ld\n", ft_strlen(""));
        printf("strlen test 2 %ld\n", strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
        printf("ft_strlen test 2 %ld\n", ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
        if (0) {
            printf("strlen test 3 %ld\n", strlen(null));
            printf("ft_strlen test 3 %ld\n", ft_strlen(null));
        

            size_t large_size = SIZE_MAX - 1; // Close to the size limit
            char *large_buffer = (char *)malloc(large_size);
            
            memset(large_buffer, 'a', large_size - 1);
            large_buffer[large_size - 1] = '\0'; // Null-terminate the string

            printf("Simulated large buffer strlen: %ld\n", strlen(large_buffer));
            printf("Simulated large buffer ft_strlen: %ld\n", ft_strlen(large_buffer));

            free(large_buffer); // Always free dynamically allocated memory
        }

    }

    // OK
    if (strcmp(option, "-ft_strdup") == 0 || strcmp(option, "-all") == 0) {
        
        char *null = NULL;
        
        // Test 1: Normal string
        char *original = "Hello world!";
        char *dup = strdup(original);
        char *ft_dup = ft_strdup(original);

        printf("strdup test 1: %s\n", dup);
        printf("ft_strdup test 1: %s\n", ft_dup);

        free(dup);
        free(ft_dup);
        
        // Test 2: Empty string
        original = "";
        dup = strdup(original);
        ft_dup = ft_strdup(original);

        printf("strdup test 2: %s\n", dup);
        printf("ft_strdup test 2: %s\n", ft_dup);

        free(dup);
        free(ft_dup);

        // Test 3: Long string
        original = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        dup = strdup(original);
        ft_dup = ft_strdup(original);

        printf("strdup test 3: %s\n", dup);
        printf("ft_strdup test 3: %s\n", ft_dup);

        free(dup);
        free(ft_dup);
        
        // Test 4: NULL input (undefined behavior in the real strdup, so this test is mostly for your custom function)
        if (0) {
            dup = strdup(null); // This will likely cause a segmentation fault, so it's disabled
            ft_dup = ft_strdup(null); // Same here

            printf("strdup test 4: %s\n", dup ? dup : "(null)");
            printf("ft_strdup test 4: %s\n", ft_dup ? ft_dup : "(null)");

            free(dup);
            free(ft_dup);
        }
    }


    // // OK 
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

        // Test 1: Read from a regular file
        errno = 0;
        res = read(fd, buffer, 30);
        printf("read res 1 %ld\n", res);
        printf("read buffer 1 %s\n", buffer);
        perror("perror read 1");

        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = 0;
        res = ft_read(fd, buffer, 30);
        printf("ft_read res 1 %ld\n", res);
        printf("ft_read buffer 1  %s\n", buffer);
        perror("perror ft_read 1");

        // Test 2: Reading from an invalid file descriptor (50000)
        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = read(50000, buffer, 30);
        printf("read res 2 %ld\n", res);
        printf("read buffer 2 %s\n", buffer);
        perror("perror read 2");
    
        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = 0;
        res = ft_read(50000, buffer, 30);
        printf("ft_read res 2 %ld\n", res);
        printf("ft_read buffer 2 %s\n", buffer);
        perror("perror ft_read 2");

        // Test 3: Read from closed file descriptor
        int fd3;
        fd3 = open("./info.txt", O_RDONLY);
        if (fd < 0) {
            perror("Failed to open file");
            return 1;
        }

        close(fd3);

        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = read(fd3, buffer, 30);
        printf("read res 3 %ld\n", res);
        printf("read buffer 3 %s\n", buffer);
        perror("perror read 3");
    
        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = 0;
        res = ft_read(fd3, buffer, 30);
        printf("ft_read res 3 %ld\n", res);
        printf("ft_read buffer 3 %s\n", buffer);
        perror("perror ft_read 3");

        // Test 4 : Read from /dev/null (should return 0)
        int fd4;
        fd4 = open("/dev/null", O_RDONLY);
        if (fd < 0) {
                perror("Failed to open /dev/null");
                return 1;
            }

        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = read(fd4, buffer, 30);
        printf("read res 4 %ld\n", res);
        printf("read buffer 4 %s\n", buffer);
        perror("perror read 4");
    
        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = 0;
        res = ft_read(fd4, buffer, 30);
        printf("ft_read res 4 %ld\n", res);
        printf("ft_read buffer 4 %s\n", buffer);
        perror("perror ft_read 4");

        // Test 5 : Read from a directory

        int fd5;
        fd = open(".", O_RDONLY);
        if (fd < 0) {
            perror("Failed to open directory");
            return 1;
        }
        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = read(fd5, buffer, 30);
        printf("read res 5 %ld\n", res);
        printf("read buffer 5 %s\n", buffer);
        perror("perror read 5");
    
        memset(buffer, 0, sizeof(buffer));
        errno = 0;
        res = 0;
        res = ft_read(fd5, buffer, 40);
        printf("ft_read res 5 %ld\n", res);
        printf("ft_read buffer 5 %s\n", buffer);
        perror("perror ft_read 5");

    }


    if (strcmp(option, "-ft_write") == 0 || strcmp(option, "-all") == 0) {

        char *src = NULL;
        char *msg = "Hello world!\n";

        errno = 0;
        printf("write test 1 = %ld\n", write(1, src, 2));
        perror("perror write");
        errno = 0;
        printf("ft_write test 1 = %ld\n", ft_write(1, src, 2));
        perror("perror ft_write");

        errno = 0;
        printf("write test 2 = %ld\n", write(150000000, src, 2));
        perror("perror write");
        errno = 0;
        printf("ft_write test 2 = %ld\n", ft_write(150000000, src, 2));
        perror("perror ft_write");

        errno = 0;
        printf("write test 3 = %ld\n", write(1, msg, 6));
        perror("perror write");
        errno = 0;
        printf("ft_write test 3 = %ld\n", ft_write(1, msg, 6));
        perror("perror ft_write");

    } 

    if (strcmp(option, "-ft_strcpy") == 0 || strcmp(option, "-all") == 0) {

        char dest[100];
        const char *src = "He";
        ft_strcpy(dest, src);
        printf("Copied string: %s\n", dest);
        printf("Copied string: %d\n", 1);

    } 
    
    if (strcmp(option, "-ft_strcmp") == 0 || strcmp(option, "-all") == 0) {
    
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
