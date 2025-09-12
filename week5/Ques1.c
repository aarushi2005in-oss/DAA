#include <stdio.h>

int main() {
    int m1, n1, m2, n2;
    int mulCount = 0, addCount = 0;  // Counters for operations

    // Input matrix dimensions
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &m1, &n1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &m2, &n2);

    // Check if multiplication is possible
    if (n1 != m2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    int A[m1][n1], B[m2][n2], C[m1][n2];

    // Input elements of first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize result matrix with 0
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication with operation count
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < n1; k++) {
                C[i][j] += A[i][k] * B[k][j];
                mulCount++;  // One multiplication
                if (k > 0) addCount++;  // One addition (except first term)
            }
        }
    }

    // Display result
    printf("\nResultant Matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Show operation counts
    printf("\nNumber of multiplication operations performed: %d\n", mulCount);
    printf("Number of addition operations performed: %d\n", addCount);

    return 0;
}
