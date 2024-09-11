#include <stdio.h>

extern int add_two_numbers(int a, int b);      // Declaration of the external assembly function
extern int multiply_two_numbers(int a, int b); // Declaration of the second external function

int main() {
    int sum = add_two_numbers(5, 3);        // Call the add function
    int product = multiply_two_numbers(5, 3); // Call the multiply function

    printf("The sum is: %d\n", sum);
    printf("The product is: %d\n", product);

    return 0;
}
