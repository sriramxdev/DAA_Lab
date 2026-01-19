# Data Structures and Algorithms (DAA) - 5th Semester

This repository contains all programs completed during the 5th semester of B.Tech (CSE + AIML) for the Design and Analysis of Algorithms (DAA) course.

## Time and Space Complexity Table

### Searching Algorithms

| Algorithm | Best Case Time | Average Case Time | Worst Case Time | Space Complexity |
|-----------|---------------|-------------------|-----------------|------------------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Recursive Linear Search | O(1) | O(n) | O(n) | O(n) |
| Recursive Binary Search | O(1) | O(log n) | O(log n) | O(log n) |

### Sorting Algorithms

| Algorithm | Best Case Time | Average Case Time | Worst Case Time | Space Complexity | Stable |
|-----------|---------------|-------------------|-----------------|------------------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(k) | Yes |
| Radix Sort | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) | Yes |

*Note: k = range of input, d = number of digits*

### Knapsack Problems

| Algorithm | Time Complexity | Space Complexity | Approach |
|-----------|----------------|------------------|----------|
| 0/1 Knapsack (DP) | O(n × W) | O(n × W) | Dynamic Programming |
| Fractional Knapsack | O(n log n) | O(1) | Greedy Algorithm |

*Note: n = number of items, W = capacity of knapsack*

### String Matching Algorithms

| Algorithm | Best Case Time | Average Case Time | Worst Case Time | Space Complexity | Preprocessing Time |
|-----------|---------------|-------------------|-----------------|------------------|-------------------|
| Naive String Matching | O(n) | O(n × m) | O(n × m) | O(1) | O(1) |
| KMP Algorithm | O(n) | O(n) | O(n) | O(m) | O(m) |

*Note: n = length of text, m = length of pattern*

### Dynamic Programming Algorithms

| Algorithm | Time Complexity | Space Complexity | Approach |
|-----------|----------------|------------------|----------|
| Matrix Chain Multiplication (MCM) | O(n³) | O(n²) | Dynamic Programming |
| Longest Common Subsequence (LCS) | O(m × n) | O(m × n) | Dynamic Programming |

*Note: For LCS, m and n are lengths of the two sequences*