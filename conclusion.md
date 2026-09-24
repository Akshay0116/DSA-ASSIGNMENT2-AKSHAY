# Final Conclusion

1. **Tree shape depends on insertion order, not just on the key set.** Inserting {45, 20, 60, 10, 30, 50, 70, 25, 55} in this particular order produced a nicely balanced BST of height 3 (the theoretical minimum for 9 nodes, ⌊log₂9⌋ = 3). Had the same 9 ISBNs been inserted in already-sorted order (10,20,25,...,70), the BST would have degenerated into a linked list of height 8, and BST search would have cost as much as linear search.

2. **Observed comparisons confirm the theory.** BST search took only 3–4 comparisons for all three test keys (25, 55, 90), while linear search needed 8–9 comparisons for the same keys — consistent with O(log n) vs O(n) behavior.

3. **Recommendation for this dataset:** The **Binary Search Tree is the preferable structure** for the bookstore's ISBN lookup system, because:
   - It gives logarithmic-time search (here, at most h+1 = 4 comparisons vs up to n = 9 for linear search).
   - It also produces sorted output "for free" via inorder traversal (useful for listing ISBNs in order, range queries, etc.), which a plain array used only for linear search does not provide as conveniently once frequent insertions/deletions occur.
   - The extra memory cost (two pointers per node, O(n) total) is a small, worthwhile trade-off for the large gain in search speed as the bookstore's catalog (n) grows — the gap between O(log n) and O(n) widens sharply with scale, even though at n = 9 the absolute difference (a handful of comparisons) is small.

4. **Caveat:** This advantage holds only as long as the BST remains reasonably balanced. If ISBNs were inserted in sorted order (a realistic risk if a bookstore imports catalog data pre-sorted by ISBN), the plain BST would degrade to O(n) — in that scenario, a **self-balancing BST (AVL tree or Red-Black tree)** should be used instead to guarantee O(log n) performance regardless of insertion order.
