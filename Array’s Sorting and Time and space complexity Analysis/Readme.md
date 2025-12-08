# Sorting Algorithms Analysis

## Insertion Sort

### How it Works
- Builds the sorted array one element at a time
- Takes each element and inserts it into its correct position in the sorted portion
- Like sorting playing cards in your hand

### Time Complexity
- **Best Case**: O(n) - when array is already sorted
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - when array is reverse sorted

### Space Complexity
- O(1) - sorts in place, no extra space needed

### When to Use
- Small datasets (< 50 elements)
- Nearly sorted data
- When you need a stable sort
- When simplicity matters

---

## Bubble Sort

### How it Works
- Repeatedly steps through the list
- Compares adjacent elements and swaps them if they're in wrong order
- Largest elements "bubble up" to the end

### Time Complexity
- **Best Case**: O(n) - with optimization, when already sorted
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

### Space Complexity
- O(1) - sorts in place

### When to Use
- Educational purposes (easy to understand)
- Very small datasets
- Generally NOT recommended for production use

---

## Selection Sort

### How it Works
- Divides array into sorted and unsorted portions
- Repeatedly finds the minimum element from unsorted portion
- Moves it to the end of sorted portion

### Time Complexity
- **Best Case**: O(n²)
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

### Space Complexity
- O(1) - sorts in place

### When to Use
- When memory writes are costly (minimum number of swaps)
- Small datasets
- When simplicity is preferred over efficiency

---

## Quick Comparison

| Algorithm      | Best    | Average | Worst   | Stable? |
|---------------|---------|---------|---------|---------|
| Insertion Sort| O(n)    | O(n²)   | O(n²)   | Yes     |
| Bubble Sort   | O(n)    | O(n²)   | O(n²)   | Yes     |
| Selection Sort| O(n²)   | O(n²)   | O(n²)   | No      |

## Bottom Line

- **Insertion Sort**: Best of the three for small/nearly sorted data
- **Bubble Sort**: Mostly educational, rarely used in practice
- **Selection Sort**: Use when minimizing swaps matters

For larger datasets, use O(n log n) algorithms like Merge Sort or Quick Sort instead.