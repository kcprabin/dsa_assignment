# Program 4: Doubly Linked List - Insert After and Delete Operations

This program shows how to implement a doubly linked list using structures in C. Unlike singly linked list, each node here has two pointers - one pointing forward and one pointing backward. This makes it easier to traverse in both directions and also simplifies deletion.

---

## Data Structures Used

### Node Structure

```c
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
```

This is the key difference from a singly linked list. Each node has:
- `data` - stores the actual value
- `prev` - pointer to the previous node
- `next` - pointer to the next node

For the first node, `prev` is NULL. For the last node, `next` is NULL.

### Global Head Pointer

```c
struct Node *head = NULL;
```

Points to the first node of the list.

---

## Functions

### `createNode(int value)`

Allocates memory for a new node and initializes it. Sets data to the given value, and both prev and next to NULL. Returns the pointer to this new node.

### `insertAtBeginning(int value)`

Adds a new node at the start of the list. Used to build the initial list for demonstration.

Steps:
1. Create new node
2. If list is empty, new node becomes head
3. Otherwise, link new node's next to current head
4. Update current head's prev to point to new node
5. Update head to new node

### `insertAfterNode(int target, int value)`

This is the main insertion function asked in the question. It inserts a new node after a node that contains the target value.

How it works:
1. Search for the node containing target value
2. If not found, print error and return
3. Create new node
4. Set new node's next to target's next
5. Set new node's prev to target
6. If target wasn't the last node, update the next node's prev to point to new node
7. Set target's next to new node

The tricky part is handling the case when we insert after the last node - we need to check if `temp->next` exists before updating its prev pointer.

### `deleteNode(int value)`

Removes a node with the given value from the list.

Steps:
1. Find the node with the value
2. If not found, print error and return
3. If node has a previous node, update its next pointer to skip current node
4. If node is the head (no previous), update head to next node
5. If node has a next node, update its prev pointer to skip current node
6. Free the memory

The beauty of doubly linked list is that we don't need to keep track of the previous node separately during traversal - we already have the prev pointer!

### `displayForward()`

Traverses from head to end, printing each node's data. Standard forward traversal.

### `displayBackward()`

First goes to the last node (by following next pointers), then traverses backward using prev pointers. This shows the advantage of doubly linked list - we can easily go both ways.

### `freeList()`

Cleans up all allocated memory.

---

## How main() Works

The main function demonstrates all operations step by step:

1. **Build initial list** - Creates a list with values 10, 20, 30 using insertAtBeginning
2. **Show initial state** - Displays list in both forward and backward directions
3. **Insert after demo** - 
   - Inserts 25 after 20
   - Inserts 15 after 10
   - Inserts 35 after 30
   - Tries to insert after non-existent node (100) to show error handling
4. **Delete demo** -
   - Deletes 25 (middle node)
   - Deletes 10 (head node)
   - Deletes 35 (tail node)
   - Tries to delete non-existent node (100)
5. **Final state** - Shows what's left in the list
6. **Cleanup** - Frees all memory

---

## Sample Output

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

---

## Why Doubly Linked List?

Compared to singly linked list:
- Can traverse in both directions
- Deletion is easier since we have direct access to previous node
- Can implement things like browser back/forward buttons, undo/redo features
- Takes more memory (extra pointer per node)
