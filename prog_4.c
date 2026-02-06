// doubly linked list - insert after & delete
#include <stdio.h>
#include <stdlib.h>

// has both prev and next pointers
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// insert new node after the node containing target value
void insertAfterNode(int target, int value) {
    struct Node *temp = head;
    
    // find the target node first
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with value %d not found!\n", target);
        return;
    }
    
    struct Node *newNode = createNode(value);
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    
    printf("Inserted %d after %d\n", value, target);
}

void deleteNode(int value) {
    struct Node *temp = head;
    
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with value %d not found!\n", value);
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    printf("Deleted node with value %d\n", value);
}

void displayForward() {
    struct Node *temp = head;
    printf("Forward:  ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("Backward: (empty)\n");
        return;
    }
    
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void freeList() {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    printf("Creating list with initial values...\n");
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);
    
    printf("\nInitial list:\n");
    displayForward();
    displayBackward();
    
    printf("\n--- Insert After Node Demo ---\n");
    insertAfterNode(20, 25);
    displayForward();
    
    insertAfterNode(10, 15);
    displayForward();
    
    insertAfterNode(30, 35);
    displayForward();
    
    insertAfterNode(100, 50);
    
    printf("\n--- Delete Node Demo ---\n");
    printf("\nCurrent list:\n");
    displayForward();
    
    deleteNode(25);
    displayForward();
    
    deleteNode(10);
    displayForward();
    
    deleteNode(35);
    displayForward();
    
    deleteNode(100);
    
    printf("\nFinal list:\n");
    displayForward();
    displayBackward();
    
    freeList();
    
    return 0;
}
