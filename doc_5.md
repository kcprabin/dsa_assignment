# Graph BFS DFS - prog_5

undirected graph using adjacency matrix, with bfs and dfs traversal.

## data structures

```c
int adj[MAX][MAX];  // adjacency matrix
int visited[MAX];   // track visited nodes
int n;              // vertex count
```

adj[i][j] = 1 means theres edge between i and j. for undirected graph, matrix is symmetric.

visited array prevents infinite loops in cyclic graphs.

## functions

**initGraph** - sets all matrix entries to 0

**addEdge(u,v)** - sets adj[u][v] and adj[v][u] to 1 (undirected so both ways)

**resetVisited** - zeros out visited array, need this before each traversal

**displayMatrix** - prints the matrix with headers

**DFS(vertex)** - depth first, recursive:
```c
mark visited
print vertex
for each adjacent unvisited vertex:
    DFS(that vertex)
```
goes deep into one path before backtracking

**BFS(start)** - breadth first, uses queue:
```c
mark start visited, enqueue
while queue not empty:
    dequeue vertex, print it
    enqueue all unvisited neighbors (mark them visited)
```
visits level by level

## main

takes vertices, edges from user, builds graph, then runs both traversals from user specified start vertex.

## sample

graph used:
```
0---1
|   |
3---2
 \ /
  4
```

```
Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v):
0 1
0 3
1 2
2 3
2 4
3 4

Adjacency Matrix:
  0 1 2 3 4 
0 0 1 0 1 0 
1 1 0 1 0 0 
2 0 1 0 1 1 
3 1 0 1 0 1 
4 0 0 1 1 0 

Enter starting vertex for traversal: 0

DFS Traversal: 0 1 2 3 4 
BFS Traversal: 0 1 3 2 4 
```

dfs went 0->1->2->3->4 (followed first neighbor each time)
bfs went 0->(1,3)->(2)->4 (all neighbors first, then their neighbors)

adj matrix is O(V^2) space, not great for sparse graphs but checking edge existence is O(1)
