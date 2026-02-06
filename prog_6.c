#include <stdio.h>

#define MAX 100

int minHeap[MAX];
int maxHeap[MAX];
int minSize = 0;
int maxSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapifyUp(int index) {
    int parent = (index - 1) / 2;
    
    while (index > 0 && minHeap[index] < minHeap[parent]) {
        swap(&minHeap[index], &minHeap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void maxHeapifyUp(int index) {
    int parent = (index - 1) / 2;
    
    while (index > 0 && maxHeap[index] > maxHeap[parent]) {
        swap(&maxHeap[index], &maxHeap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void insertMinHeap(int value) {
    minHeap[minSize] = value;
    minHeapifyUp(minSize);
    minSize++;
}

void insertMaxHeap(int value) {
    maxHeap[maxSize] = value;
    maxHeapifyUp(maxSize);
    maxSize++;
}

void minHeapifyDown(int arr[], int n, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if (smallest != index) {
        swap(&arr[index], &arr[smallest]);
        minHeapifyDown(arr, n, smallest);
    }
}

void maxHeapifyDown(int arr[], int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != index) {
        swap(&arr[index], &arr[largest]);
        maxHeapifyDown(arr, n, largest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        minHeap[i] = arr[i];
    }
    minSize = n;
    
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapifyDown(minHeap, n, i);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        maxHeap[i] = arr[i];
    }
    maxSize = n;
    
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapifyDown(maxHeap, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printHeapTree(int heap[], int n, char *type) {
    printf("\n%s Heap as tree:\n", type);
    int level = 0;
    int levelSize = 1;
    int printed = 0;
    
    while (printed < n) {
        printf("Level %d: ", level);
        for (int i = 0; i < levelSize && printed < n; i++) {
            printf("%d ", heap[printed]);
            printed++;
        }
        printf("\n");
        level++;
        levelSize *= 2;
    }
}

int main() {
    int arr[MAX];
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    printArray(arr, n);
    
    printf("\n========== MIN HEAP ==========\n");
    buildMinHeap(arr, n);
    printf("Min Heap array: ");
    printArray(minHeap, minSize);
    printf("Root (minimum): %d\n", minHeap[0]);
    printHeapTree(minHeap, minSize, "Min");
    
    printf("\n========== MAX HEAP ==========\n");
    buildMaxHeap(arr, n);
    printf("Max Heap array: ");
    printArray(maxHeap, maxSize);
    printf("Root (maximum): %d\n", maxHeap[0]);
    printHeapTree(maxHeap, maxSize, "Max");
    
    return 0;
}
