#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;

    // Step 1: Input the size of the array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Step 2: Input elements
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Bubble sort logic
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            // Compare adjacent elements
            if(arr[j] > arr[j+1]) {
                // Swap if they are in wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Step 4: Output sorted array
    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
