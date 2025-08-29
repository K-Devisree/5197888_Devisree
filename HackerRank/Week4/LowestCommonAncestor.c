Question: Lowest Common Ancestor
You are given pointer to the root of the binary search tree and two values  and . You need to return the lowest common ancestor (LCA) of  and  in the binary search tree.

Solution:
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int data) {
    if(root == NULL) {
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        return n;
    } else {
        if(data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

struct node* lca(struct node* root, int v1, int v2) {
    if(root->data > v1 && root->data > v2) return lca(root->left, v1, v2);
    if(root->data < v1 && root->data < v2) return lca(root->right, v1, v2);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    struct node* root = NULL;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    struct node* ans = lca(root, v1, v2);
    printf("%d\n", ans->data);
    return 0;
}
