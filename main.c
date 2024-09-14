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


#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"

void compare_and_print(const char *test_name, const char *dup, const char *ft_dup) {
    if (strcmp(dup, ft_dup) == 0) {
        printf(COLOR_GREEN "%s: OK\n" COLOR_RESET, test_name);
    } else {
        printf(COLOR_RED "%s: FAIL\n" COLOR_RESET, test_name);
    }
}

void ft_strdup_test(void) {
    
 char *null = NULL;
    
    // Test 1: Normal string
    char *original = "Hello world!";
    char *dup = strdup(original);
    char *ft_dup = ft_strdup(original);

    printf("strdup test 1: %s\n", dup);
    printf("ft_strdup test 1: %s\n", ft_dup);
    
    compare_and_print("Test 1", dup, ft_dup);

    free(dup);
    free(ft_dup);
    
    // Test 2: Empty string
    original = "";
    dup = strdup(original);
    ft_dup = ft_strdup(original);

    printf("strdup test 2: %s\n", dup);
    printf("ft_strdup test 2: %s\n", ft_dup);

    compare_and_print("Test 2", dup, ft_dup);

    free(dup);
    free(ft_dup);

    // Test 3: Long string
    original = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    dup = strdup(original);
    ft_dup = ft_strdup(original);

    printf("strdup test 3: %s\n", dup);
    printf("ft_strdup test 3: %s\n", ft_dup);

    compare_and_print("Test 3", dup, ft_dup);

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

void compare_strlen_and_print(const char *test_name, const char *input) {
    size_t strlen_result = strlen(input);
    size_t ft_strlen_result = ft_strlen(input);

    printf("strlen %s: %ld\n", test_name, strlen_result);
    printf("ft_strlen %s: %ld\n", test_name, ft_strlen_result);

    if (strlen_result == ft_strlen_result) {
        printf(COLOR_GREEN "%s: OK\n" COLOR_RESET, test_name);
    } else {
        printf(COLOR_RED "%s: FAIL\n" COLOR_RESET, test_name);
    }
}

void compare_read_and_print(const char *test_name, int fd, char *buffer, ssize_t size) {
    
    memset(buffer, 0, size);
    errno = 0;
    ssize_t res_read = read(fd, buffer, size);
    printf("read %s: %ld\n", test_name, res_read);
    printf("read buffer %s: %s\n", test_name, buffer);
    perror("perror read");

    memset(buffer, 0, size);
    errno = 0;
    ssize_t res_ft_read = ft_read(fd, buffer, size);
    printf("ft_read %s: %ld\n", test_name, res_ft_read);
    printf("ft_read buffer %s: %s\n", test_name, buffer);
    perror("perror ft_read");

    if (res_read == res_ft_read) {
        printf(COLOR_GREEN "%s: OK\n" COLOR_RESET, test_name);
    } else {
        printf(COLOR_RED "%s: FAIL\n" COLOR_RESET, test_name);
    }
}

void compare_write_and_print(const char *test_name, int fd, const char *buffer, size_t size) {
    errno = 0;  // Reset errno before calling ft_write
    ssize_t res_write = write(fd, buffer, size);
    printf("write %s = %ld\n", test_name, res_write);
    perror("perror write");

    errno = 0;  // Reset errno before calling ft_write
    ssize_t res_ft_write = ft_write(fd, buffer, size);
    printf("ft_write %s = %ld\n", test_name, res_ft_write);
    perror("perror ft_write");

    if (res_write == res_ft_write) {
        printf(COLOR_GREEN "%s: OK\n" COLOR_RESET, test_name);
    } else {
        printf(COLOR_RED "%s: FAIL\n" COLOR_RESET, test_name);
    }
}

void compare_strcpy_and_print(const char *test_name, const char *src) {
    char dest_strcpy[100];
    char dest_ft_strcpy[100];

    // Perform the copy
    strcpy(dest_strcpy, src);
    ft_strcpy(dest_ft_strcpy, src);

    // Print source and results
    printf("Source string: \"%s\"\n", src);
    printf("strcpy result: \"%s\"\n", dest_strcpy);
    printf("ft_strcpy result: \"%s\"\n", dest_ft_strcpy);

    // Compare results and print test result
    if (strcmp(dest_strcpy, dest_ft_strcpy) == 0) {
        printf(COLOR_GREEN "%s: PASS\n" COLOR_RESET "\n", test_name);
    } else {
        printf(COLOR_RED "%s: FAIL\n" COLOR_RESET "\n", test_name);
    }
}


void compare_strcmp_and_print(const char *test_name, const char *str1, const char *str2) {
    int strcmp_result = strcmp(str1, str2);
    int ft_strcmp_result = ft_strcmp(str1, str2);

    printf("strcmp %s result: %d\n", test_name, strcmp_result);
    printf("ft_strcmp %s result: %d\n", test_name, ft_strcmp_result);

    if (strcmp_result == ft_strcmp_result) {
        printf(COLOR_GREEN "%s: PASS\n" COLOR_RESET "\n", test_name);
    } else {
        printf(COLOR_RED "%s: FAIL\n" COLOR_RESET "\n", test_name);
    }
}

int main(int argc, char *argv[]) {

    char *option = "\0";

    if (argc > 1) {
        option = argv[1];
    }

    // OK
    if (strcmp(option, "-ft_strlen") == 0 || strcmp(option, "-all") == 0) {

        printf("FT_STRLEN\n\n");
        char *null = NULL;
    
        // Test 1: Normal string
        compare_strlen_and_print("Test 1", "Hello world!");
        
        // Test 2: Empty string
        compare_strlen_and_print("Test 2", "");
        
        // Test 3: Long string
        compare_strlen_and_print("Test 3", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        
        // Test 4: NULL input (undefined behavior in the real strlen, so it's commented out)
        if (0) {
            printf("strlen test 4 %ld\n", strlen(null));
            printf("ft_strlen test 4 %ld\n", ft_strlen(null));
        }

        // Simulating large buffer test
        if (0) {
            size_t large_size = SIZE_MAX - 1; // Close to the size limit
            char *large_buffer = (char *)malloc(large_size);
            
            if (large_buffer != NULL) {
                memset(large_buffer, 'a', large_size - 1);
                large_buffer[large_size - 1] = '\0'; // Null-terminate the string

                printf("Simulated large buffer strlen: %ld\n", strlen(large_buffer));
                printf("Simulated large buffer ft_strlen: %ld\n", ft_strlen(large_buffer));

                free(large_buffer); // Always free dynamically allocated memory
            }
        }

    }

    // OK
    if (strcmp(option, "-ft_strdup") == 0 || strcmp(option, "-all") == 0) {
        
        printf("\nFT_STRLEN\n\n");
        ft_strdup_test();
        
    }


    // OK 
    if (strcmp(option, "-ft_read") == 0 || strcmp(option, "-all") == 0) {
    

        printf("\nFT_READ\n\n");

        char buffer[100];
        ssize_t buffer_size = sizeof(buffer);

        // Test 1: Read from a regular file
        int fd = open("./info.txt", O_RDONLY);
        if (fd < 0) {
            perror("Failed to open file");
            return 1;
        }

        memset(buffer, 0, buffer_size);
        errno = 0;
        ssize_t res_read = read(fd, buffer, buffer_size);
        printf("read %s: %ld\n", "Test 1", res_read);
        printf("read buffer %s: %s\n", "Test 1", buffer);
        perror("perror read");
        close(fd);

        fd = open("./info.txt", O_RDONLY);
        if (fd < 0) {
            perror("Failed to open file");
            return 1;
        }
        memset(buffer, 0, buffer_size);
        errno = 0;
        ssize_t res_ft_read = ft_read(fd, buffer, buffer_size);
        printf("ft_read %s: %ld\n", "Test 1", res_ft_read);
        printf("ft_read buffer %s: %s\n", "Test 1", buffer);
        perror("perror ft_read");

        if (res_read == res_ft_read) {
            printf(COLOR_GREEN "%s: OK\n" COLOR_RESET, "Test 1");
        } else {
            printf(COLOR_RED "%s: FAIL\n" COLOR_RESET, "Test 1");
        }
        close(fd);



        // Test 2: Reading from an invalid file descriptor (50000)
        compare_read_and_print("Test 2", 50000, buffer, buffer_size);

        // Test 3: Read from a closed file descriptor
        int fd3 = open("./info.txt", O_RDONLY);
        if (fd3 < 0) {
            perror("Failed to open file");
            return 1;
        }
        close(fd3);  // Close file descriptor
        compare_read_and_print("Test 3", fd3, buffer, buffer_size);

        // Test 4: Read from /dev/null (should return 0)
        int fd4 = open("/dev/null", O_RDONLY);
        if (fd4 < 0) {
            perror("Failed to open /dev/null");
            return 1;
        }
        compare_read_and_print("Test 4", fd4, buffer, buffer_size);
        close(fd4);

        // Test 5: Read from a directory
        int fd5 = open(".", O_RDONLY);
        if (fd5 < 0) {
            perror("Failed to open directory");
            return 1;
        }
        compare_read_and_print("Test 5", fd5, buffer, buffer_size);
        close(fd5);
    }

    // OK
    if (strcmp(option, "-ft_write") == 0 || strcmp(option, "-all") == 0) {
        
        printf("\nFT_WRITE\n\n");

        char *src = NULL;
        char *msg = "Hello world!\n";
        
        // Test 1: Write from NULL pointer
        compare_write_and_print("Test 1", 1, src, 2);

        // Test 2: Writing to an invalid file descriptor
        compare_write_and_print("Test 2", 150000000, src, 2);

        // Test 3: Write a valid string to stdout
        compare_write_and_print("Test 3", 1, msg, 6);

        // Test 4: Writing with zero-length buffer
        compare_write_and_print("Test 4", 1, msg, 0);

        // Test 5: Writing to a closed file descriptor
        int fd = open("info.txt", O_CREAT | O_RDWR, 0644);
        close(fd);
        compare_write_and_print("Test 5", fd, msg, 5);

        // Test 6: Writing to a file descriptor that is not writable (read-only)
        int dir_fd = open("info.txt", O_RDONLY);
        compare_write_and_print("Test 6", dir_fd, msg, 5);
        close(dir_fd);

        // Test 7: Writing to a pipe
        int fds[2];
        pipe(fds);
        compare_write_and_print("Test 7", fds[1], msg, 5);
        close(fds[0]);
        close(fds[1]);

    } 


    // OK 
    if (strcmp(option, "-ft_strcpy") == 0 || strcmp(option, "-all") == 0) {

        printf("\nFT_STRCPY\n\n");

        compare_strcpy_and_print("Test 1: Normal string", "Hello, World!");

        // Test 2: Empty string
        compare_strcpy_and_print("Test 2: Empty string", "");

        // Test 3: Single character
        compare_strcpy_and_print("Test 3: Single character", "A");

        // Test 4: Long string
        compare_strcpy_and_print("Test 4: Long string", "This is a very long string, but it fits within the buffer!");

    }


    // OK
    if (strcmp(option, "-ft_strcmp") == 0 || strcmp(option, "-all") == 0) {
    

        /* int strcmp(const char *s1, const char *s2);
        Cette fonction compare chaque caractere, lorsqu'il y a une difference, elle fait une soustraction et renvoie : 
            • 0, if the s1 and s2 are equal;
            • a negative value if s1 is less than s2;
            • a positive value if s1 is greater than s2.
        De sorte que si une est plus courte, alors on soustraira avec 0, mais si meme length et differente, ca compare la position du caractere
        sur la table ascii
        */
        printf("\nFT_STRCMP\n\n");

        // Test 1: "B" vs "A"
        compare_strcmp_and_print("Test 1", "B", "A");

        // Test 2: "B" vs "B"
        compare_strcmp_and_print("Test 2", "B", "B");

        // Test 3: "B" vs "C"
        compare_strcmp_and_print("Test 3", "B", "C");

        // Test 4: "mB" vs "mA"
        compare_strcmp_and_print("Test 4", "mB", "mA");

        // Test 5: "mB" vs "mB"
        compare_strcmp_and_print("Test 5", "mB", "mB");

        // Test 6: "mB" vs "mC"
        compare_strcmp_and_print("Test 6", "mB", "mC");

        // Test 7: "mB" vs "mAka"
        compare_strcmp_and_print("Test 7", "mB", "mAka");

        // Test 8: "mB" vs "mBa"
        compare_strcmp_and_print("Test 8", "mB", "mBa");

        // Test 9: "mBa" vs "mB"
        compare_strcmp_and_print("Test 9", "mBa", "mB");
    
    }
    
    return 0;
}
