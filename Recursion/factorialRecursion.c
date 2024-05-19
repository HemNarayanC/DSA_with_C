#include <stdio.h>

// Function to find the factorial of a number recursively
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
        return 1;
    // Recursive case: factorial of n is n times factorial of (n-1)
    else
        return n * factorial(n - 1);
}

// Main function to test the factorial function
int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    // Check if the entered number is non-negative
    if (n < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
        printf("Factorial of %d is %llu\n", n, factorial(n));
    return 0;
}
