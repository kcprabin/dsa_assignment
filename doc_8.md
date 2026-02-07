# Program 8: Sorting Algorithm Comparison and Analysis Tool

## 📋 Problem Statement

Write a program that generates a list of N random integers in the range [1, 1000], where N is provided by the user at run time. The program should:
- Allow the user to choose from four sorting algorithms (Bubble Sort, Selection Sort, Insertion Sort, Merge Sort)
- Sort the randomly generated numbers using the chosen algorithm
- Display the numbers before and after sorting
- Show the total number of comparisons and swaps performed by the algorithm

## 🎯 Objective

To implement and compare different sorting algorithms by tracking their performance metrics (comparisons and swaps/operations), helping users understand the efficiency differences between various sorting techniques.

## 🔧 Algorithm Overview

### 1. **Bubble Sort**
- **Time Complexity**: O(n²) worst and average case, O(n) best case
- **Space Complexity**: O(1)
- **How it works**: Repeatedly steps through the list, compares adjacent elements, and swaps them if they're in the wrong order. The pass through the list is repeated until the list is sorted.
- **Optimization**: Includes early termination if no swaps occur in a pass

### 2. **Selection Sort**
- **Time Complexity**: O(n²) for all cases
- **Space Complexity**: O(1)
- **How it works**: Divides the array into sorted and unsorted regions. Repeatedly finds the minimum element from the unsorted region and places it at the beginning of the sorted region.
- **Characteristic**: Makes fewer swaps compared to bubble sort

### 3. **Insertion Sort**
- **Time Complexity**: O(n²) worst and average case, O(n) best case
- **Space Complexity**: O(1)
- **How it works**: Builds the final sorted array one item at a time. Picks each element and inserts it into its correct position in the already sorted portion.
- **Best for**: Small datasets or nearly sorted data

### 4. **Merge Sort**
- **Time Complexity**: O(n log n) for all cases
- **Space Complexity**: O(n)
- **How it works**: Divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves.
- **Characteristic**: Consistently efficient regardless of input data distribution

## 📊 Program Flow

```
START
  ↓
Get N (number of elements) from user
  ↓
Generate N random integers in range [1, 1000]
  ↓
Display sorting algorithm menu:
  1. Bubble Sort
  2. Selection Sort
  3. Insertion Sort
  4. Merge Sort
  ↓
Get user's choice
  ↓
Display array BEFORE sorting
  ↓
Reset comparison and swap counters
  ↓
Apply selected sorting algorithm
  ↓
Display array AFTER sorting
  ↓
Display performance statistics:
  - Total Comparisons
  - Total Swaps/Operations
  ↓
END
```

## 💡 Key Features

1. **Dynamic Memory Allocation**: Uses `malloc()` to allocate memory based on user input
2. **Performance Tracking**: Global counters track comparisons and swaps in real-time
3. **User-Friendly Interface**: Clean, formatted output with box-drawing characters
4. **Smart Display**: Shows first and last 50 elements for large arrays (>100 elements)
5. **Memory Management**: Properly frees allocated memory before program termination
6. **Input Validation**: Checks for positive number input

## 🔍 Performance Metrics

### Comparisons
- Number of times two elements are compared
- Tracked in all four algorithms

### Swaps/Operations
- **Bubble, Selection, Insertion Sort**: Actual element swaps
- **Merge Sort**: Array copy operations (since it doesn't use traditional swaps)

## 📝 Sample Execution

```
╔═══════════════════════════════════════════════════════════╗
║     SORTING ALGORITHM COMPARISON & ANALYSIS TOOL          ║
╚═══════════════════════════════════════════════════════════╝

Enter the number of random integers to generate (N): 10

╔═══════════════════════════════════════════════════════════╗
║              CHOOSE A SORTING ALGORITHM                   ║
╠═══════════════════════════════════════════════════════════╣
║  1. Bubble Sort                                           ║
║  2. Selection Sort                                        ║
║  3. Insertion Sort                                        ║
║  4. Merge Sort                                            ║
╚═══════════════════════════════════════════════════════════╝

Enter your choice (1-4): 1

═══════════════════════════════════════════════════════════
ARRAY BEFORE SORTING:
═══════════════════════════════════════════════════════════
 634  782  123  891  456  234  789  567  345  901 

═══════════════════════════════════════════════════════════
SORTING IN PROGRESS...
═══════════════════════════════════════════════════════════
Algorithm: Bubble Sort

═══════════════════════════════════════════════════════════
ARRAY AFTER SORTING:
═══════════════════════════════════════════════════════════
 123  234  345  456  567  634  782  789  891  901 

╔═══════════════════════════════════════════════════════════╗
║              PERFORMANCE STATISTICS                       ║
╠═══════════════════════════════════════════════════════════╣
║  Total Comparisons: 45                                    ║
║  Total Swaps:       22                                    ║
╚═══════════════════════════════════════════════════════════╝

Thank you for using the Sorting Algorithm Analyzer!
```

## 🧪 Testing Scenarios

### Test Case 1: Small Array (N = 5)
- **Input**: N = 5, Algorithm = Bubble Sort
- **Expected**: Complete before/after display with all statistics

### Test Case 2: Medium Array (N = 50)
- **Input**: N = 50, Algorithm = Merge Sort
- **Expected**: Full array display showing efficiency of O(n log n)

### Test Case 3: Large Array (N = 1000)
- **Input**: N = 1000, Algorithm = Selection Sort
- **Expected**: Truncated display (first 50 + last 50), high comparison count

### Test Case 4: Compare Algorithms
- **Same Dataset**: Generate once, test each algorithm
- **Expected**: Merge Sort should show best performance for large N

## 📈 Expected Performance Comparisons

For N = 100 random integers:

| Algorithm       | Comparisons | Swaps/Ops | Relative Speed |
|----------------|-------------|-----------|----------------|
| Bubble Sort    | ~4,950      | ~2,500    | Slowest        |
| Selection Sort | ~4,950      | ~100      | Slow           |
| Insertion Sort | ~2,500      | ~2,500    | Moderate       |
| Merge Sort     | ~664        | ~1,536    | Fastest        |

*Note: Values are approximate and vary based on initial array randomness*

## 🚀 Compilation and Execution

### Compile
```bash
gcc prog_8.c -o prog_8
```

### Run
```bash
./prog_8
```

### Example Run with Different Sizes
```bash
# Small dataset
./prog_8
# Enter: 10, then 1 (Bubble Sort)

# Medium dataset
./prog_8
# Enter: 100, then 4 (Merge Sort)

# Large dataset
./prog_8
# Enter: 5000, then 4 (Merge Sort)
```

## 💻 Code Structure

### Global Variables
- `comparisons`: Tracks total comparison operations
- `swaps`: Tracks total swap/copy operations

### Main Functions
1. `main()`: Program entry point, handles user interaction
2. `generateRandomNumbers()`: Creates random integers [1, 1000]
3. `printArray()`: Displays array with smart formatting
4. `resetCounters()`: Resets performance counters

### Sorting Functions
1. `bubbleSort()`: Implements optimized bubble sort
2. `selectionSort()`: Implements selection sort
3. `insertionSort()`: Implements insertion sort
4. `mergeSort()`: Implements merge sort (recursive)
5. `merge()`: Helper function for merge sort

## 🎓 Learning Outcomes

1. **Algorithm Implementation**: Hands-on experience with classic sorting algorithms
2. **Performance Analysis**: Understanding time complexity through real metrics
3. **Memory Management**: Using dynamic memory allocation in C
4. **Code Organization**: Structured programming with functions
5. **User Interface**: Creating interactive command-line applications

## 🔧 Possible Enhancements

1. **Add More Algorithms**: Quick Sort, Heap Sort, Radix Sort
2. **Timing Analysis**: Add execution time measurement
3. **File I/O**: Save results to a file for analysis
4. **Visualization**: Show sorting steps for educational purposes
5. **Batch Testing**: Run multiple tests and generate comparison reports
6. **Custom Range**: Allow user to specify min/max range for random numbers

## ⚠️ Important Notes

- The program uses `rand()` seeded with `time(NULL)` for randomization
- For very large N (>100,000), merge sort is recommended
- Memory is dynamically allocated; ensure sufficient system memory
- All algorithms are implemented with in-place sorting except merge sort
- Performance metrics help understand practical algorithm efficiency

## 📚 References

- Cormen, T. H., et al. "Introduction to Algorithms" (CLRS)
- Sedgewick, R. "Algorithms in C"
- Knuth, D. E. "The Art of Computer Programming, Vol. 3: Sorting and Searching"

---

**Author**: DSA Assignment  
**Program**: prog_8.c  
**Documentation**: doc_8.md  
**Date**: February 2026
