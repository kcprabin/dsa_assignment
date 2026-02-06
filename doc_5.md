# Program 5: Undirected Graph with BFS and DFS Traversal

This program implements an undirected graph using adjacency matrix representation and provides two traversal methods - Breadth First Search (BFS) and Depth First Search (DFS).

---

## Data Structures Used

### Adjacency Matrix

```c
int adj[MAX][MAX];
int n; // number of vertices
```

The adjacency matrix is a 2D array where `adj[i][j] = 1` means there's an edge between vertex i and vertex j. For an undirected graph, the matrix is symmetric - if `adj[i][j] = 1`, then `adj[j][i] = 1` too.

Example for a triangle graph (0-1-2):
```
  0 1 2
0 0 1 1
1 1 0 1
2 1 1 0
```

### Visited Array

```c
int visited[MAX];
```

Keeps track of which vertices we've already visited during traversal. 0 means not visited, 1 means visited. This prevents infinite loops in graphs with cycles.

### Queue (for BFS)

Inside BFS function, I used an array-based queue:
```c
int queue[MAX];
int front = 0, rear = 0;
```

BFS needs a queue to process vertices level by level.

---

## Functions

### `initGraph()`

Sets all entries in adjacency matrix to 0. Called once at the start to make sure we begin with a clean slate.

### `addEdge(int u, int v)`

Adds an edge between vertices u and v. Since the graph is undirected, we set both `adj[u][v]` and `adj[v][u]` to 1.

### `resetVisited()`

Resets the visited array to all zeros. Need to call this before each traversal so both BFS and DFS can work properly.

### `displayMatrix()`

Prints the adjacency matrix in a readable format with row and column headers. Helpful to visualize the graph structure.

### `DFS(int vertex)`

Depth First Search - goes as deep as possible before backtracking.

How it works:
1. Mark current vertex as visited
2. Print it
3. Look at all adjacent vertices (check the row in adjacency matrix)
4. For each unvisited adjacent vertex, recursively call DFS

The recursion naturally handles the backtracking. It's like exploring a maze by always taking the first available path, and only going back when you hit a dead end.

### `BFS(int start)`

Breadth First Search - visits all neighbors first before going deeper.

How it works:
1. Mark starting vertex as visited and add to queue
2. While queue is not empty:
   - Remove front vertex from queue and print it
   - Find all unvisited adjacent vertices
   - Mark them visited and add to queue

BFS explores the graph level by level - first all vertices at distance 1, then distance 2, and so on.

---

## How main() Works

1. Takes number of vertices from user
2. Initializes the adjacency matrix with zeros
3. Takes number of edges
4. For each edge, reads two vertices and calls addEdge()
5. Displays the adjacency matrix
6. Asks for starting vertex for traversal
7. Performs DFS from that vertex and shows the order
8. Resets visited array
9. Performs BFS from same vertex and shows the order

---

## Example Graph Used

```
    0 --- 1
    |     |
    |     |
    3 --- 2
     \   /
      \ /
       4
```

Vertices: 0, 1, 2, 3, 4

Edges: 0-1, 0-3, 1-2, 2-3, 2-4, 3-4

---

## Sample Output

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

Notice how DFS and BFS give different orders:
- **DFS** goes deep: 0 → 1 → 2 → 3 → 4 (goes all the way down one path)
- **BFS** goes wide: 0 → 1,3 → 2 → 4 (visits all neighbors before going deeper)

---

## Another Example

```
Enter number of vertices: 4
Enter number of edges: 4
Enter edges (u v):
0 1
0 2
1 3
2 3

Adjacency Matrix:
  0 1 2 3 
0 0 1 1 0 
1 1 0 0 1 
2 1 0 0 1 
3 0 1 1 0 

Enter starting vertex for traversal: 0

DFS Traversal: 0 1 3 2 
BFS Traversal: 0 1 2 3 
```

---

## Notes

- Adjacency matrix uses O(V²) space where V is number of vertices
- Good for dense graphs where most vertices are connected
- Checking if edge exists is O(1) - just look up adj[i][j]
- For sparse graphs, adjacency list would be more memory efficient
