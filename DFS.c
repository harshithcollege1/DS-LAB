#include <stdio.h>
void DFS(int graph[10][10], int n, int start, int visited[]) {
    int stack[10];
    int top = -1;
    stack[++top] = start;
    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            visited[v] = 1;
            for (int i = n - 1; i >= 0; i--) {
                if (graph[v][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}
int main() {
    int n;
    int graph[10][10];
    int visited[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    DFS(graph, n, 0, visited);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT CONNECTED\n");
            return 0;
        }
    }
    printf("Graph is CONNECTED\n");
    return 0;
}