#include <stdio.h>

// Recursive function to calculate the factorial of a number
unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    unsigned int number;

    // Prompt the user to enter a number to calculate its factorial
    printf("Enter a number to calculate the factorial: ");
    scanf("%u", &number);

    if (number < 0) {
        printf("Cannot calculate the factorial of a negative number.\n");
    } else {
        // Calculate the factorial of the entered number and display the result
        unsigned long long result = factorial(number);
        printf("The factorial of %u is: %llu\n", number, result);
    }

    return 0;
}
