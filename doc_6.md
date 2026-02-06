# Min and Max Heap - prog_6

builds both min heap and max heap from unsorted array input.

## heap basics

heap is stored as array but represents a complete binary tree. for index i:
- parent = (i-1)/2
- left child = 2*i+1  
- right child = 2*i+2

**min heap**: parent <= children (smallest at root)
**max heap**: parent >= children (largest at root)

```c
int minHeap[MAX], maxHeap[MAX];
int minSize = 0, maxSize = 0;
```

## functions

**swap** - swaps two ints using pointers

**heapifyUp** - used when inserting. new element bubbles up to correct position by comparing with parent.

**heapifyDown** - used in build. element sinks down by comparing with children, swapping with smaller(min)/larger(max) child.

**buildMinHeap / buildMaxHeap** - the efficient way:
```c
copy array to heap
start from last non-leaf node (n/2 - 1)
heapifyDown each node going backwards to root
```
why n/2-1? nodes from n/2 onwards are leaves, already valid heaps.

**printHeapTree** - shows heap level by level for visualization

## main

reads array -> builds min heap -> displays -> builds max heap -> displays

shows array form, root element, and tree view for each.

## output

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

tree view:
```
min heap:       max heap:
    10              42
   /  \            /  \
  14   19         35   27
 /\    /\        /\    /\
33 35 42 27     10 14 19 33
```

building heap bottom-up is O(n), faster than inserting one by one O(n log n)
