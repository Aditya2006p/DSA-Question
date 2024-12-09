# C Search and Sort Algorithms

This repository contains C programs that implement various **search algorithms** and **sorting techniques**. The key algorithms implemented include:

- **Linear Search**
- **Binary Search**
- **Sorting Algorithms**:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort

These algorithms are demonstrated through user-friendly C programs that allow input of an array of elements and perform either **Linear Search** or **Binary Search** on them. The program also provides sorting methods and allows sorting the array before performing a Binary Search.

---

## Features

1. **Linear Search**: 
   - Scans through the entire array to find the target element.
   - Time Complexity: O(n), where `n` is the number of elements in the array.
   - Space Complexity: O(1).

2. **Binary Search**:
   - Works on **sorted arrays** and repeatedly divides the array in half to locate the target element.
   - Time Complexity: O(log n), where `n` is the number of elements in the array.
   - Space Complexity: O(1).
   - The program automatically sorts the array if Binary Search is selected.

3. **Sorting Algorithms**:
   - **Bubble Sort**: Repeatedly compares adjacent elements and swaps them if they are in the wrong order.
   - **Selection Sort**: Repeatedly selects the smallest (or largest) element and swaps it into the correct position.
   - **Insertion Sort**: Builds the sorted array one element at a time.
   - **Merge Sort**: Divides the array into halves and merges them back in sorted order.
   - **Quick Sort**: Selects a pivot element and partitions the array around the pivot.

---

## Prerequisites

Before running the program, make sure you have:
- A C compiler installed (e.g., GCC).
- Basic understanding of sorting and searching algorithms.

---

## How to Run

### Clone the repository:

To use the program, first clone the repository to your local machine:
```bash
git clone https://github.com/your-username/your-repository-name.git
