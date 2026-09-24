# Comparison Table: BST Search vs Linear Search

| Search Key | Found? | BST Comparisons | Linear Search Comparisons | Difference | Faster Method |
|:----------:|:------:|:----------------:|:-------------------------:|:----------:|:--------------|
| 25         | Yes    | 4                 | 8                          | 4 fewer    | BST           |
| 55         | Yes    | 4                 | 9                          | 5 fewer    | BST           |
| 90         | No     | 3                 | 9                          | 6 fewer    | BST           |

**Average comparisons:** BST = (4+4+3)/3 = **3.67**, Linear Search = (8+9+9)/3 = **8.67**

## Theoretical vs Observed Complexity

| Metric                         | Theoretical (Big-O)                         | Observed for n = 9 keys |
|---------------------------------|----------------------------------------------|--------------------------|
| BST Search – Best case          | O(1)                                          | 1 (if key at root)       |
| BST Search – Average/Worst case | O(h), h = height of tree (O(log n) if balanced, O(n) if skewed) | h = 3 → worst possible comparisons = h+1 = 4 (matches observed 4) |
| Linear Search – Best case        | O(1)                                          | 1 (if key at index 0)   |
| Linear Search – Average case     | O(n/2)                                        | ≈ 4.5                    |
| Linear Search – Worst case       | O(n)                                          | 9 (matches observed 8–9) |

The observed values (4, 4, 3 for BST vs 8, 9, 9 for linear search) line up closely with theory: since the tree built from this insertion order has height 3 on 9 nodes (close to the ideal ⌊log₂9⌋ = 3), BST search comparisons stay bounded by h+1 = 4, while linear search must, in the worst case, walk through nearly all n = 9 elements.
