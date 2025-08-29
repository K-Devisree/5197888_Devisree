Question:Tree:Preorder Traversal
Complete the preorder function in the editor below, which has  parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

Solution:

void preOrder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
//full code
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* insertNode(struct Node* root, int value) {
    if (!root) {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->val = value;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    if (value <= root->val) root->left = insertNode(root->left, value);
    else root->right = insertNode(root->right, value);
    return root;
}

void preOrderTraversal(struct Node* root) {
    if (!root) return;
    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    int n, x;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insertNode(root, x);
    }
    preOrderTraversal(root);
    return 0;
}
