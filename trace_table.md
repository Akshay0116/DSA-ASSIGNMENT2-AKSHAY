# Trace Tables

## Trace Table 1: BST Construction (Insertion Order: 45, 20, 60, 10, 30, 50, 70, 25, 55)

| Step | Key Inserted | Path Compared (node → decision)                  | Comparisons | Tree Shape After Insertion (parent → new node) |
|------|-------------|---------------------------------------------------|:-----------:|-------------------------------------------------|
| 1    | 45          | (root empty)                                       | 0           | 45 becomes root                                 |
| 2    | 20          | 45 (20<45→L)                                        | 1           | 20 inserted as **left** child of 45              |
| 3    | 60          | 45 (60>45→R)                                        | 1           | 60 inserted as **right** child of 45             |
| 4    | 10          | 45(10<45→L) → 20(10<20→L)                           | 2           | 10 inserted as **left** child of 20              |
| 5    | 30          | 45(30<45→L) → 20(30>20→R)                           | 2           | 30 inserted as **right** child of 20             |
| 6    | 50          | 45(50>45→R) → 60(50<60→L)                           | 2           | 50 inserted as **left** child of 60              |
| 7    | 70          | 45(70>45→R) → 60(70>60→R)                           | 2           | 70 inserted as **right** child of 60             |
| 8    | 25          | 45(25<45→L) → 20(25>20→R) → 30(25<30→L)             | 3           | 25 inserted as **left** child of 30              |
| 9    | 55          | 45(55>45→R) → 60(55<60→L) → 50(55>50→R)             | 3           | 55 inserted as **right** child of 50             |

**Total comparisons for building the tree = 0+1+1+2+2+2+2+3+3 = 16**

### Resulting Tree Structure

```
                    45
                 /      \
               20         60
              /  \       /   \
            10    30   50     70
                  /       \
                25         55
```

- Inorder   : 10 20 25 30 45 50 55 60 70   (sorted order ✔)
- Preorder  : 45 20 10 30 25 60 50 55 70
- Postorder : 10 25 30 20 55 50 70 60 45
- Height (edges) = 3, Nodes = 9

---

## Trace Table 2: BST Search

### Search key = 25
| Step | Current Node | Comparison        | Action           |
|------|-------------|--------------------|------------------|
| 1    | 45          | 25 < 45            | go left → 20     |
| 2    | 20          | 25 > 20            | go right → 30    |
| 3    | 30          | 25 < 30            | go left → 25     |
| 4    | 25          | 25 == 25           | **Found**        |

**Comparisons = 4**

### Search key = 55
| Step | Current Node | Comparison        | Action           |
|------|-------------|--------------------|------------------|
| 1    | 45          | 55 > 45            | go right → 60    |
| 2    | 60          | 55 < 60            | go left → 50     |
| 3    | 50          | 55 > 50            | go right → 55    |
| 4    | 55          | 55 == 55           | **Found**        |

**Comparisons = 4**

### Search key = 90
| Step | Current Node | Comparison        | Action           |
|------|-------------|--------------------|------------------|
| 1    | 45          | 90 > 45            | go right → 60    |
| 2    | 60          | 90 > 60            | go right → 70    |
| 3    | 70          | 90 > 70            | go right → NULL  |

**Comparisons = 3, Not Found**

---

## Trace Table 3: Linear Search (array in insertion order)
`arr = [45, 20, 60, 10, 30, 50, 70, 25, 55]` (indices 0–8)

### Search key = 25
| Step (i) | arr[i] | Comparison | Match? |
|----------|--------|------------|--------|
| 0        | 45     | 25≠45      | No     |
| 1        | 20     | 25≠20      | No     |
| 2        | 60     | 25≠60      | No     |
| 3        | 10     | 25≠10      | No     |
| 4        | 30     | 25≠30      | No     |
| 5        | 50     | 25≠50      | No     |
| 6        | 70     | 25≠70      | No     |
| 7        | 25     | 25=25      | **Yes**|

**Comparisons = 8**

### Search key = 55
| Step (i) | arr[i] | Comparison | Match? |
|----------|--------|------------|--------|
| 0        | 45     | No | |
| 1        | 20     | No | |
| 2        | 60     | No | |
| 3        | 10     | No | |
| 4        | 30     | No | |
| 5        | 50     | No | |
| 6        | 70     | No | |
| 7        | 25     | No | |
| 8        | 55     | **Yes** | |

**Comparisons = 9**

### Search key = 90
All 9 elements scanned, no match found.
**Comparisons = 9, Not Found**
