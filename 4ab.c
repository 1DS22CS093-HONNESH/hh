#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 6

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0}
};

// Source Removal Method
void topologicalSortSourceRemoval(int num_vertices) {
    int in_degree[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = 0, rear = 0;
    
    // Compute in-degrees
    for (int i = 0; i < num_vertices; i++)
        for (int j = 0; j < num_vertices; j++)
            if (graph[j][i]) in_degree[i]++;
    
    // Enqueue nodes with in-degree 0
    for (int i = 0; i < num_vertices; i++)
        if (in_degree[i] == 0) queue[rear++] = i;
    
    printf("Topological Sort (Source Removal): ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < num_vertices; v++)
            if (graph[u][v] && --in_degree[v] == 0)
                queue[rear++] = v;
    }
    printf("\n");
}

// DFS Method
void dfs(int v, bool visited[], int stack[], int *top, int num_vertices) {
    visited[v] = true;
    for (int i = 0; i < num_vertices; i++)
        if (graph[v][i] && !visited[i]) dfs(i, visited, stack, top, num_vertices);
    stack[(*top)++] = v;
}

void topologicalSortDFS(int num_vertices) {
    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES], top = 0;
    
    for (int i = 0; i < num_vertices; i++)
        if (!visited[i]) dfs(i, visited, stack, &top, num_vertices);
    
    printf("Topological Sort (DFS): ");
    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    topologicalSortSourceRemoval(MAX_VERTICES);
    topologicalSortDFS(MAX_VERTICES);
    return 0;
}
