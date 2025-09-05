#include <stdio.h>

// Function to rotate the matrix 90 degrees clockwise
void rotate(int n, int matrix[n][n]) {
    int i, j, temp;

    // Step 1: Transpose the matrix
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (i = 0; i < n; i++) {
        for (j = 0; j < n / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

int main() {
    int n, i, j;
    printf("Enter size of matrix (n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotate(n, matrix);

    printf("Matrix after 90 degree clockwise rotation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
