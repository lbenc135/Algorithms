#include <cstdio>
using namespace std;

struct node {
    bool isEnd=false;
    node* child[26]={0};
};

int n;

void add(node *n, char *c)
{
    char l=*c-'a';
    if(n->child[l]==NULL)
        n->child[l]=new node;

    if(*(c+1)=='\0')
    {
        n->isEnd=1;
        return;
    }
    add(n->child[l], c+1);
}

bool find(node *n, char *c)
{
    if(*(c+1)=='\0')
        return n->isEnd;

    char l=*c-'a';
    if(n->child[l]==NULL) return false;
    return find(n->child[l], c+1);
}

int main()
{
    node root;
    char w[20];

    scanf("%i", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%s", &w);
        add(&root, w);
    }

    scanf("%s", &w);
    printf("%i\n", find(&root, w));
}
