#include <cstdio>
#include <cstdlib>

struct node
{
    int data;
    node *left, *right;
};

node* lca(node *root, int n1, int n2)
{
    while (root != 0)
    {
        if (root->data > n1 && root->data > n2)
           root = root->left;
        else if (root->data < n1 && root->data < n2)
           root = root->right;
        else break;
    }
    return root;
}

node* newNode(int data)
{
    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->left = n->right = 0;
    return n;
}

int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
}
