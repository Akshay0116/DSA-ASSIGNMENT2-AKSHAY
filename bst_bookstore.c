/* ==========================================================================
   Online Bookstore ISBN Management using Binary Search Tree (BST)
   --------------------------------------------------------------------------
   a) Build BST by inserting ISBN keys in given order
      Display Inorder, Preorder, Postorder traversals
   b) Search for 25, 55, 90 using:
        - BST Search   (with comparison count)
        - Linear Search on the same keys stored in an array (insertion order)
      Record number of comparisons for each search
   ========================================================================== */

#include <stdio.h>
#include <stdlib.h>

/* ---------- BST Node ---------- */
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

/* ---------- Create a new BST node ---------- */
Node* newNode(int key) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

/* ---------- Insert a key into BST (iterative, also counts comparisons) ---------- */
Node* insert(Node *root, int key) {
    if (root == NULL) return newNode(key);
    Node *cur = root;
    while (1) {
        if (key < cur->key) {
            if (cur->left == NULL) { cur->left = newNode(key); break; }
            cur = cur->left;
        } else if (key > cur->key) {
            if (cur->right == NULL) { cur->right = newNode(key); break; }
            cur = cur->right;
        } else {
            break; /* duplicate, ignore */
        }
    }
    return root;
}

/* ---------- Traversals ---------- */
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

/* ---------- Height of BST (number of edges on longest path) ---------- */
int height(Node *root) {
    if (root == NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

/* ---------- BST Search with comparison counter ---------- */
Node* bstSearch(Node *root, int key, int *comparisons) {
    Node *cur = root;
    *comparisons = 0;
    while (cur != NULL) {
        (*comparisons)++;
        if (key == cur->key) return cur;
        else if (key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    return NULL; /* not found */
}

/* ---------- Linear Search with comparison counter ---------- */
int linearSearch(int arr[], int n, int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) return i; /* index found */
    }
    return -1; /* not found */
}

int main() {
    int keys[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    int n = sizeof(keys) / sizeof(keys[0]);

    /* ---------- a) Build the BST ---------- */
    Node *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("================= PART (a): BST CONSTRUCTION =================\n");
    printf("Insertion order : ");
    for (int i = 0; i < n; i++) printf("%d ", keys[i]);
    printf("\n\n");

    printf("Inorder Traversal   : ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal  : ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal : ");
    postorder(root);
    printf("\n");

    printf("\nHeight of BST (edges): %d\n", height(root));
    printf("Number of nodes       : %d\n", n);

    /* ---------- b) Search comparisons ---------- */
    int searchKeys[] = {25, 55, 90};
    int m = sizeof(searchKeys) / sizeof(searchKeys[0]);

    printf("\n================= PART (b): SEARCH COMPARISON =================\n");
    printf("%-10s %-15s %-15s %-15s %-15s\n",
           "Key", "BST Found?", "BST Comps", "Linear Found?", "Linear Comps");

    for (int i = 0; i < m; i++) {
        int key = searchKeys[i];
        int bComp = 0, lComp = 0;

        Node *res = bstSearch(root, key, &bComp);
        int idx = linearSearch(keys, n, key, &lComp);

        printf("%-10d %-15s %-15d %-15s %-15d\n",
               key,
               (res != NULL) ? "Yes" : "No",
               bComp,
               (idx != -1) ? "Yes" : "No",
               lComp);
    }

    return 0;
}
