#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

typedef struct {
    int dest;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int edge_count;
} Graph;


int findMinNode(int dist[], int visited[], int n) {
    int min = INF;
    int min_index = -1;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra's algorithm 
void dijkstra(Graph graph[], int n, int src) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    int parent[MAX_NODES];
    
    // Initialize distances, visited array, and parent array
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    

    for (int i = 0; i < n - 1; i++) {
        int u = findMinNode(dist, visited, n);
        
        if (u == -1) break;
        
        visited[u] = 1;
        
      
        for (int j = 0; j < graph[u].edge_count; j++) {
            int v = graph[u].edges[j].dest;
            int weight = graph[u].edges[j].weight;
            
            if (!visited[v] && dist[u] != INF && 
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
    

    printf("Shortest distances from node %d:\n", src);

    
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
        if (dist[i] == INF) {
            printf("INFbtNo path\n");
        } else {
            printf("%d", dist[i]);
            
            
            int path[MAX_NODES];
            int path_len = 0;
            int current = i;
            
            while (current != -1) {
                path[path_len++] = current;
                current = parent[current];
            }
            
            for (int j = path_len - 1; j >= 0; j--) {
                printf("%d", path[j]);
                if (j > 0) ;
            }
            printf("\n");
        }
    }
}

int main() {
    int n, m, src;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    Graph graph[MAX_NODES];
    

    for (int i = 0; i < n; i++) {
        graph[i].edge_count = 0;
    }
    

    printf("Enter edges (format: source destination weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        
        if (u >= 0 && u < n && v >= 0 && v < n) {
    
            graph[u].edges[graph[u].edge_count].dest = v;
            graph[u].edges[graph[u].edge_count].weight = w;
            graph[u].edge_count++;
        } else {
            printf("Invalid node indices!\n");
            i--;
        }
    }
    
    printf("Enter source node: ");
    scanf("%d", &src);
    
    if (src >= 0 && src < n) {
        dijkstra(graph, n, src);
    } else {
        printf("Invalid source node!\n");
    }
    
    return 0;
}
