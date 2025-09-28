#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

/* function prototypes to avoid implicit-declaration warnings */
int minKey(int key[], bool mstSet[]);
void primMST(int graph[V][V]);
void printMST(int parent[], int graph[V][V]);

int main(void)
{
    int graph[V][V] = {
        {0, 2, 0, 0, 0, 4},
        {2, 0, 8, 0, 0, 3},
        {0, 8, 0, 6, 1, 0},
        {0, 0, 6, 0,12, 0},
        {0, 0, 1,12, 0, 2},
        {4, 3, 0, 0, 2, 0}
    };

    primMST(graph);
    return 0;
}

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;      // Start from vertex 0
    parent[0] = -1;  // First node is root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        if (u == -1) break; // disconnected graph safety
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            /* fixed condition: use < to compare weights */
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

void printMST(int parent[], int graph[V][V])
{
    int total = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total weight: %d\n", total);
}
