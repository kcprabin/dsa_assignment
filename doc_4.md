# Doubly Linked List - prog_4

implements DLL with insert-after and delete operations.

## node structure

```c
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
```

difference from singly linked: each node knows both its neighbors. first node has prev=NULL, last has next=NULL.

## functions

**createNode** - allocates memory, sets data, prev and next to NULL

**insertAtBeginning** - adds at start, used for initial list setup

**insertAfterNode(target, value)** - main insert function:
- find node with target value
- create new node
- adjust 4 pointers: newNode's prev/next, and neighbors' pointers
- careful with last node case (no next neighbor to update)

**deleteNode(value)** - finds and removes node:
- link previous node to next node (skip over current)
- handle edge cases: deleting head, deleting tail
- free the memory

**displayForward/displayBackward** - traverse both ways, shows DLL advantage

**freeList** - memory cleanup

## main

hardcoded demo that:
1. creates list 10->20->30
2. inserts 25 after 20, 15 after 10, 35 after 30
3. deletes middle, head, and tail nodes
4. shows error handling for non-existent nodes

## output

```
Creating list with initial values...

Initial list:
Forward:  10 20 30 
Backward: 30 20 10 

--- Insert After Node Demo ---
Inserted 25 after 20
Forward:  10 20 25 30 
Inserted 15 after 10
Forward:  10 15 20 25 30 
Inserted 35 after 30
Forward:  10 15 20 25 30 35 
Node with value 100 not found!

--- Delete Node Demo ---

Current list:
Forward:  10 15 20 25 30 35 
Deleted node with value 25
Forward:  10 15 20 30 35 
Deleted node with value 10
Forward:  15 20 30 35 
Deleted node with value 35
Forward:  15 20 30 
Node with value 100 not found!

Final list:
Forward:  15 20 30 
Backward: 30 20 15 
```

DLL uses more memory (extra pointer) but deletion is way easier coz you already have prev pointer
