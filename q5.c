#include <stdio.h>

// Function to find GCD (HCF)
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Input
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Compute and print GCD (HCF)
    int gcd = findGCD(num1, num2);
    printf("GCD (HCF) of %d and %d is: %d\n", num1, num2, gcd);

    return 0;
}
