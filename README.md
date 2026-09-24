# Online Bookstore ISBN Management — BST vs Linear Search

Data Structures & Algorithms Assignment: implementing and analysing a Binary
Search Tree (BST) for ISBN storage/search, compared against Linear Search.

## Problem Statement
An online bookstore stores ISBN keys: `45, 20, 60, 10, 30, 50, 70, 25, 55`.

- **(a)** Build a BST by inserting the ISBNs in the given order; display Inorder,
  Preorder and Postorder traversals.
- **(b)** Search for `25`, `55`, and `90` using BST Search and Linear Search;
  record the number of comparisons for each.
- **(c)** Analyse how tree shape/height affects search performance, compare
  observed vs theoretical complexity, and conclude which method is preferable.

## Repository Contents

| File                     | Description                                              |
|--------------------------|-----------------------------------------------------------|
| `bst_bookstore.c`         | C source: BST insert, traversals, BST search, linear search (with comparison counters) |
| `input.txt`               | Input data used (insertion order + search keys)           |
| `output.txt`              | Captured program output from execution                    |
| `trace_table.md`          | Step-by-step trace tables for construction and both searches |
| `comparison_table.md`     | Side-by-side comparison of BST vs Linear Search comparisons |
| `complexity_analysis.md`  | Time & space complexity analysis (best/avg/worst case)     |
| `conclusion.md`           | Final conclusion and recommendation                        |

## How to Compile & Run

```bash
gcc -o bst_bookstore bst_bookstore.c -Wall
./bst_bookstore
```

## Sample Output

```
================= PART (a): BST CONSTRUCTION =================
Insertion order : 45 20 60 10 30 50 70 25 55

Inorder Traversal   : 10 20 25 30 45 50 55 60 70
Preorder Traversal  : 45 20 10 30 25 60 50 55 70
Postorder Traversal : 10 25 30 20 55 50 70 60 45

Height of BST (edges): 3
Number of nodes       : 9

================= PART (b): SEARCH COMPARISON =================
Key        BST Found?      BST Comps       Linear Found?   Linear Comps
25         Yes             4               Yes             8
55         Yes             4               Yes             9
90         No              3               No              9
```

## Summary of Findings
See `complexity_analysis.md`, `comparison_table.md`, and `conclusion.md` for
full details. In short: for this insertion order the BST is nearly balanced
(height 3 on 9 nodes), so BST search needed only 3–4 comparisons versus 8–9
for linear search — matching the theoretical O(log n) vs O(n) gap.

## Uploading to GitHub

From inside this project folder:

```bash
git init
git add .
git commit -m "BST vs Linear Search assignment: bookstore ISBN management"
git branch -M main
git remote add origin https://github.com/<your-username>/<your-repo-name>.git
git push -u origin main
```

(Create the empty repository first on github.com, then run the commands
above with your own GitHub username and repository name.)
