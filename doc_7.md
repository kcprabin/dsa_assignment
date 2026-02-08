# Dijkstra's Algorithm - Shortest Path Implementation

## Overview
This program implements **Dijkstra's Algorithm** to find the shortest path from a source node to all other nodes in a weighted, directed graph.

## Algorithm Description
Dijkstra's algorithm is a greedy algorithm that works as follows:
1. Initialize distances to all nodes as infinity, except the source (distance = 0)
2. Mark all nodes as unvisited
3. While there are unvisited nodes:
   - Select the unvisited node with the minimum distance
   - Mark it as visited
   - For each adjacent node, update its distance if a shorter path is found through the current node
4. Continue until all nodes are visited or no more reachable nodes exist

## Time Complexity
- **With adjacency list and min-heap**: O((V + E) log V), where V = vertices, E = edges
- **Current implementation (simple)**: O(V²)

## Space Complexity
- O(V) for distance, visited, and parent arrays

## Key Features
- Handles weighted graphs
- Reconstructs and displays the shortest path for each node
- Detects unreachable nodes (marked as INF)
- Input validation for node indices
- Adjacency list representation

## Usage Example
```
Enter number of nodes: 4
Enter number of edges: 5
Enter edges (format: source destination weight):
Edge 1: 0 1 4
Edge 2: 0 2 1
Edge 3: 1 3 1
Edge 4: 2 1 2
Edge 5: 2 3 5
Enter source node: 0

Output:
Shortest distances from node 0:
Node    Distance    Path
----    --------    ----
0       0           0
1       3           0 -> 2 -> 1
2       1           0 -> 2
3       4           0 -> 2 -> 1 -> 3
```

## Data Structures
- **Edge**: Stores destination node and weight
- **Graph**: Array of edge lists for each node
- **Distance array**: Stores shortest distance to each node
- **Visited array**: Tracks processed nodes
- **Parent array**: Reconstructs the shortest path

## Limitations
- Current implementation uses simple linear search for minimum distance (O(V²))
- For larger graphs (V > 1000), consider using a min-heap for better performance
- Cannot handle negative edge weights (use Bellman-Ford algorithm instead)

## Applications
- GPS navigation systems
- Network routing protocols
- Social network analysis
- Game pathfinding
- Telecommunication networks
