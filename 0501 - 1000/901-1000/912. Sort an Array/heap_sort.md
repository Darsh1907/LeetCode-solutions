## Why Heap Sort is the Best Solution 🌟

### Time Complexity ⏳:
Heap Sort runs in O(n log n) time in all cases (best, average, and worst), making it consistent and reliable.

### Space Complexity 💾:
It sorts the array in-place, using only a constant amount of extra space (O(1)), which is beneficial when working with large data sets.

### Performance 🚀:
Heap Sort does not suffer from the worst-case performance issues like Quick Sort, which can degrade to O(n²) in the worst case. It is a robust choice for sorting arrays with guaranteed performance.

### Versatility 🌍:
It can be easily adapted to find the k-th largest or smallest element in an array, making it a versatile sorting technique.

### Approach 🛠️

Build the Max-Heap:

- Start from the last non-leaf node and heapify each node up to the root. This transforms the array into a max-heap.

Extract Elements from the Heap:

- Swap the root (largest element) with the last element of the heap. Reduce the heap size by one and heapify the root to maintain the max-heap property.
- Repeat this step until the heap size is reduced to one.
