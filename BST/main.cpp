#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int num;
    struct node *left;
    struct node *right;
    node(int x) {
        num = x;
        left = right = NULL;
    }
    node() {}
} root;
typedef node* BSTree;

bool treeContains(int x, BSTree n)
{
    if(n==NULL) return false;
    if(x==n->num) return true;
    if(x < n->num)
        return treeContains(x, n->left);
    else
        return treeContains(x, n->right);
}

node* treeInsert(int x, node *n)
{
    if(n==NULL)
    {
        n=new node(x);
        return n;
    }
    else if(x < n->num)
        n->left = treeInsert(x, n->left);
    else if(x > n->num)
        n->right = treeInsert(x, n->right);
    return n;
}

int deleteMin(BSTree *n)
{
    BSTree tree = *n;
    int minval;
    if(tree->left==NULL)
    {
        minval = tree->num;
        tree = tree->right;
    }
    else
        minval = deleteMin(&tree->left);
    *n = tree;
    return minval;
}

void treeDelete(int x, BSTree *n)
{
    BSTree tree = *n;
    if(tree==NULL) return;
    if(x < tree->num)
        treeDelete(x, &tree->left);
    else if(x > tree->num)
        treeDelete(x, &tree->right);
    else if(tree->left==NULL && tree->right==NULL)
    {
        free(tree);
        tree=NULL;
    }
    else
    {
        if(tree->left==NULL)
            tree=tree->right;
        else if(tree->right==NULL)
            tree=tree->left;
        else
            tree->num=deleteMin(&tree->right);
    }
    *n = tree;
}

void treePrint(node *n)
{
    if(n==NULL) return;
    if(n->left!=NULL)
        treePrint(n->left);
    cout << n->num << " ";
    if(n->right!=NULL)
        treePrint(n->right);
}

int main()
{
    BSTree rt = &root;
    root.num = 10;
    treeInsert(12, &root);
    treeInsert(1, &root);
    treeInsert(126, &root);
    treeInsert(52, &root);
    treeInsert(3, &root);
    cout << treeContains(1, rt) << endl;
    treeDelete(1, &rt);
    cout << treeContains(1, rt) << endl;
    treePrint(&root);
}
