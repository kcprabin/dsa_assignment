# Reverse Traversal of Linked List - prog_3

prints linked list elements in reverse without actually reversing the list. did it two ways - recursion and using a stack.

## the node struct

```c
struct Node {
    int data;
    struct Node *next;
};
```

basic singly linked list node. data + pointer to next.

head pointer is global, starts NULL.

## functions

**createNode** - mallocs a node, sets data, returns pointer

**insertAtEnd** - adds node at end. traverse till last node, link new one there.

**displayForward** - normal traversal, start to end

**reverseTraversal (recursive)** - this is the interesting one:
```c
void reverseTraversal(struct Node *node) {
    if (node == NULL) return;
    reverseTraversal(node->next);  // go to end first
    printf("%d ", node->data);      // print while coming back
}
```
basically recurse to end, then print on return. call stack does the work.

**reverseTraversalUsingStack** - iterative version:
- go through list, push each value onto stack
- pop and print everything
- stack is LIFO so last element prints first

**freeList** - cleanup, frees all nodes

## main

takes n elements from user, builds list, then shows:
1. forward print
2. reverse using recursion
3. reverse using stack

both reverse methods give same output obviously

## output

```
How many elements? 5
Enter 5 elements:
10 20 30 40 50

Forward: 10 20 30 40 50 
Reverse: 50 40 30 20 10 
Reverse (using stack): 50 40 30 20 10 
```

recursive is cleaner code but stack method is safer for huge lists (no stackoverflow risk)
