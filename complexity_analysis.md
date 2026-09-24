# Complexity Analysis

## 1. Binary Search Tree (BST)

### Time Complexity
| Operation        | Best Case | Average Case | Worst Case |
|-------------------|:---------:|:-------------:|:----------:|
| Insertion (1 key) | O(1)      | O(log n)       | O(n)       |
| Build tree (n keys)| O(n)     | O(n log n)     | O(n²)      |
| Search            | O(1)      | O(log n)       | O(n)       |
| Inorder/Preorder/Postorder traversal | O(n) | O(n) | O(n) |

- The **worst case O(n)** for insertion/search happens when keys arrive in sorted (or reverse-sorted) order, degrading the BST into a linked-list (a "skewed" tree of height n−1).
- The **average/best case O(log n)** happens when the tree stays reasonably balanced, i.e., height h ≈ log₂(n).
- For the given dataset (45, 20, 60, 10, 30, 50, 70, 25, 55), the insertion order happens to produce a fairly balanced tree: height = 3 for n = 9, which is exactly ⌊log₂ 9⌋ = 3 — the theoretical minimum possible height. This is why BST search performance for this dataset closely matches the *best-case/average-case* bound rather than the worst case.

### Space Complexity
- O(n) for storing n nodes (each node: 1 key + 2 pointers).
- O(h) additional space for the recursion stack during traversals/search if implemented recursively (O(log n) average, O(n) worst case). The search and insert in the code above are implemented **iteratively**, so they use only O(1) auxiliary space; traversals use O(h) recursion stack space.

## 2. Linear Search

### Time Complexity
| Case    | Comparisons |
|---------|:-----------:|
| Best    | O(1) — key at index 0 |
| Average | O(n/2) → O(n) |
| Worst   | O(n) — key at last position or absent |

### Space Complexity
- O(n) to store the array of n keys.
- O(1) auxiliary space for the search itself (just an index counter and comparison counter).

## 3. Key Insight — Why Shape/Height Matters for BST

The performance of BST search is governed entirely by the **height h** of the tree, not directly by the number of nodes n:
- **Balanced BST:** h ≈ ⌊log₂ n⌋ → search/insert = O(log n)
- **Skewed/degenerate BST** (e.g., inserting 10,20,25,30,45,50,55,60,70 in already-sorted order): h = n−1 → search/insert = O(n), no better than linear search, but with extra pointer-storage overhead.

For this assignment's specific insertion order, the tree happens to balance itself well (height 3 for 9 nodes), so BST search requires at most 4 comparisons versus up to 9 for linear search — demonstrating the log n vs n gap even at this small scale.
