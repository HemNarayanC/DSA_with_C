#include <stdio.h>

// Function to calculate the sum of digits of a number recursively
int sumOfDigits(int n) {
    if (n == 0)
        return 0; // Base case: if the number becomes 0, return 0
    else
        return (n % 10) + sumOfDigits(n / 10); // Recursive case: return the last digit + sum of digits of remaining number
}

int main() {
    int num;

    // Get input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate and display the sum of digits
    printf("Sum of digits of %d is %d\n", num, sumOfDigits(num));

    return 0;
}
