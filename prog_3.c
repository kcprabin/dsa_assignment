// linked list reverse traversal
// two methods: recursion and stack
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayForward() {
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// recursion trick - go to end first, print on way back
void reverseTraversal(struct Node *node) {
    if (node == NULL)
        return;
    
    reverseTraversal(node->next);
    printf("%d ", node->data);
}

void displayReverse() {
    printf("Reverse: ");
    reverseTraversal(head);
    printf("\n");
}

void reverseTraversalUsingStack() {
    int stack[100];
    int top = -1;
    
    struct Node *temp = head;
    while (temp != NULL) {
        stack[++top] = temp->data;
        temp = temp->next;
    }
    
    printf("Reverse (using stack): ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
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
    int n, value;
    
    printf("How many elements? ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(value);
    }
    
    printf("\n");
    displayForward();
    
    displayReverse();
    
    reverseTraversalUsingStack();
    
    freeList();
    
    return 0;
}
