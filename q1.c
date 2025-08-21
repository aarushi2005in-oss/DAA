#include <stdio.h>

int main() {
    int N, a = 0, b = 1, count = 0, temp;

    printf("Enter the number of terms: ");
    scanf("%d", &N);

    printf("Fibonacci Series:\n");

    while (count < N) {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
        count++;
    }

    return 0;
}