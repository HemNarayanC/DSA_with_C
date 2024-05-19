#include <stdio.h>

// Function to calculate the sum of first n natural numbers recursively
int sumOfNaturals(int n) {
    if (n == 0)
        return 0; // Base case: if n is 0, return 0
    else
        return n + sumOfNaturals(n - 1); // Recursive case: return n + sum of first (n-1) natural numbers
}

int main() {
    int n;

    // Get input from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate and display the sum of first n natural numbers
    printf("Sum of first %d natural numbers is %d\n", n, sumOfNaturals(n));

    return 0;
}
