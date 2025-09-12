#include <stdio.h>

// Function to return maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];  // Maximum value
}

int main() {
    int values[] = {60, 100, 120};   // Values of items
    int weights[] = {10, 20, 30};    // Weights of items
    int capacity = 50;               // Knapsack capacity
    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(capacity, weights, values, n));

    return 0;
}
