# Program 3: Reverse Traversal of Linked List

This program demonstrates how to traverse a singly linked list in reverse order. Since a singly linked list only has forward pointers, we can't just go backwards directly. I've implemented two different approaches here - one using recursion and another using a stack.

---

## Data Structures Used

### Node Structure

```c
struct Node {
    int data;
    struct Node *next;
};
```

Each node holds an integer value and a pointer to the next node. Pretty standard linked list setup.

### Global Head Pointer

```c
struct Node *head = NULL;
```

This points to the first node of the list. Starts as NULL when list is empty.

### Stack Array (for iterative approach)

Inside `reverseTraversalUsingStack()`, I used a simple integer array as a stack:

```c
int stack[100];
int top = -1;
```

---

## Functions

### `createNode(int value)`

Allocates memory for a new node, sets its data to the given value, and sets next to NULL. Returns pointer to the new node.

### `insertAtEnd(int value)`

Adds a new node at the end of the list. If list is empty, the new node becomes the head. Otherwise, we traverse to the last node and link the new node there.

### `displayForward()`

Normal traversal - starts from head, visits each node one by one, prints the data.

### `reverseTraversal(struct Node *node)`

This is the recursive approach for reverse traversal. The trick is simple:
1. First, recursively go to the end of the list
2. Then print on the way back

So if we have 1 -> 2 -> 3, the function calls stack up until we hit NULL, then as each call returns, it prints its node's data. This gives us 3 2 1.

### `displayReverse()`

Just a wrapper that calls `reverseTraversal(head)` with some formatting.

### `reverseTraversalUsingStack()`

The iterative approach:
1. Go through the list from start to end, pushing each value onto a stack
2. Pop everything from the stack and print

Since stack is LIFO (last in first out), the last element we pushed gets printed first - giving us reverse order.

### `freeList()`

Cleans up memory by freeing all nodes. Good practice to avoid memory leaks.

---

## How main() Works

1. Asks user how many elements they want to enter
2. Takes that many integer inputs and builds the list using `insertAtEnd()`
3. Shows the list in forward order first (so user can verify)
4. Shows reverse traversal using recursion
5. Shows reverse traversal using stack method
6. Frees all allocated memory before exiting

---

## Sample Output

```
How many elements? 5
Enter 5 elements:
10
20
30
40
50

Forward: 10 20 30 40 50 
Reverse: 50 40 30 20 10 
Reverse (using stack): 50 40 30 20 10 
```

```
How many elements? 3
Enter 3 elements:
7
14
21

Forward: 7 14 21 
Reverse: 21 14 7 
Reverse (using stack): 21 14 7 
```

---

## Notes

- The recursive method is cleaner but can cause stack overflow for very long lists
- The stack-based method uses extra memory but handles large lists better
- Both give the same output, just different ways of achieving it
