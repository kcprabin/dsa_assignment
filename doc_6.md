# Program 6: Building Min Heap and Max Heap from Unsorted Array

This program takes an unsorted array of integers and constructs both a min heap and a max heap from it. The heaps are stored as arrays but represent complete binary trees.

---

## Data Structures Used

### Heap Arrays

```c
int minHeap[MAX];
int maxHeap[MAX];
int minSize = 0;
int maxSize = 0;
```

Both heaps are stored as arrays. In array representation of a complete binary tree:
- For a node at index `i`
- Parent is at index `(i - 1) / 2`
- Left child is at index `2 * i + 1`
- Right child is at index `2 * i + 2`

### Min Heap Property

Every parent node is smaller than or equal to its children. So the smallest element is always at the root (index 0).

### Max Heap Property

Every parent node is greater than or equal to its children. So the largest element is always at the root (index 0).

---

## Functions

### `swap(int *a, int *b)`

Simple utility function to swap two integer values using pointers.

### `minHeapifyUp(int index)`

Used during insertion. After adding a new element at the end, this function moves it up to its correct position by comparing with parent. Keeps swapping with parent until heap property is satisfied.

### `maxHeapifyUp(int index)`

Same as above but for max heap - element moves up if it's greater than parent.

### `insertMinHeap(int value)` and `insertMaxHeap(int value)`

Inserts a value into the respective heap. Adds at the end and calls heapify up.

### `minHeapifyDown(int arr[], int n, int index)`

This is the key function for building heap. Starting from a node, it:
1. Compares the node with its left and right children
2. Finds the smallest among the three
3. If current node isn't the smallest, swap with the smallest child
4. Recursively heapify the affected subtree

### `maxHeapifyDown(int arr[], int n, int index)`

Same logic but finds the largest instead. Parent should be larger than both children.

### `buildMinHeap(int arr[], int n)`

Builds min heap from the given array using the bottom-up approach:
1. Copy array elements to minHeap array
2. Start from the last non-leaf node (index `n/2 - 1`)
3. Call heapifyDown on each node going backwards to root

Why start from `n/2 - 1`? Because nodes from `n/2` to `n-1` are all leaf nodes - they don't have children, so they already satisfy heap property trivially.

### `buildMaxHeap(int arr[], int n)`

Same approach for max heap.

### `printArray(int arr[], int n)`

Prints array elements in a line.

### `printHeapTree(int heap[], int n, char *type)`

Prints the heap in a level-by-level format to visualize the tree structure. Level 0 has root, level 1 has its children, and so on.

---

## How main() Works

1. Takes number of elements from user
2. Reads the array elements
3. Prints the original unsorted array
4. Builds min heap from the array and displays:
   - The heap as an array
   - The root element (minimum)
   - The heap as a tree (level by level)
5. Builds max heap from the same original array and displays:
   - The heap as an array
   - The root element (maximum)
   - The heap as a tree (level by level)

---

## Sample Output

```
Enter number of elements: 7
Enter 7 elements:
35 33 42 10 14 19 27

Original array: 35 33 42 10 14 19 27 

========== MIN HEAP ==========
Min Heap array: 10 14 19 33 35 42 27 
Root (minimum): 10

Min Heap as tree:
Level 0: 10 
Level 1: 14 19 
Level 2: 33 35 42 27 

========== MAX HEAP ==========
Max Heap array: 42 35 27 10 14 19 33 
Root (maximum): 42

Max Heap as tree:
Level 0: 42 
Level 1: 35 27 
Level 2: 10 14 19 33 
```

Visualizing the Min Heap:
```
        10
       /  \
      14   19
     / \   / \
    33 35 42 27
```

Visualizing the Max Heap:
```
        42
       /  \
      35   27
     / \   / \
    10 14 19 33
```

---

## Another Example

```
Enter number of elements: 5
Enter 5 elements:
50 20 30 10 40

Original array: 50 20 30 10 40 

========== MIN HEAP ==========
Min Heap array: 10 20 30 50 40 
Root (minimum): 10

Min Heap as tree:
Level 0: 10 
Level 1: 20 30 
Level 2: 50 40 

========== MAX HEAP ==========
Max Heap array: 50 40 30 10 20 
Root (maximum): 50

Max Heap as tree:
Level 0: 50 
Level 1: 40 30 
Level 2: 10 20 
```

---

## Time Complexity

- Building heap using bottom-up approach: O(n)
- This is more efficient than inserting elements one by one which would be O(n log n)

The bottom-up approach is faster because most nodes are near the bottom of the tree, and they don't need to travel far during heapify.
