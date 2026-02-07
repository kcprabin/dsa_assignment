#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;
long long swaps = 0;

void generateRandomNumbers(int arr[], int n);
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void resetCounters();

int main() {
    int n, choice;
    
    srand(time(NULL));
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Error: Enter a positive number.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    int *original = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL || original == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    generateRandomNumbers(arr, n);
    
    for (int i = 0; i < n; i++) {
        original[i] = arr[i];
    }
    
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("\nBefore sorting:\n");
    printArray(original, n);
    
    resetCounters();
    
    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice.\n");
            free(arr);
            free(original);
            return 1;
    }
    
    printf("\nAfter sorting:\n");
    printArray(arr, n);
    
    printf("\nComparisons: %lld\n", comparisons);
    if (choice != 4) {
        printf("Swaps: %lld\n", swaps);
    } else {
        printf("Array Copies: %lld\n", swaps);
    }
    
    free(arr);
    free(original);
    
    return 0;
}

void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;
    }
}

void printArray(int arr[], int n) {
    if (n <= 100) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < 50; i++) {
            printf("%d ", arr[i]);
        }
        printf("... %d more ... ", n - 100);
        for (int i = n - 50; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void resetCounters() {
    comparisons = 0;
    swaps = 0;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
        swaps++;
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
        swaps++;
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        swaps++;
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        swaps++;
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        swaps++;
        j++;
        k++;
    }
    
    free(leftArr);
    free(rightArr);
}
