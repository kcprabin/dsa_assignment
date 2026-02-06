#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

void initGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // undirected graph
}

void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;
    
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        
        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int edges, u, v, start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    initGraph();
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    displayMatrix();
    
    printf("\nEnter starting vertex for traversal: ");
    scanf("%d", &start);
    
    printf("\nDFS Traversal: ");
    resetVisited();
    DFS(start);
    printf("\n");
    
    printf("BFS Traversal: ");
    resetVisited();
    BFS(start);
    printf("\n");
    
    return 0;
}
