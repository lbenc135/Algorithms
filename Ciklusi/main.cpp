#include <cstdio>
using namespace std;

int n, e;
bool mat[100][100];
bool visited[100];

bool DFS(int a, int r)
{
    visited[a]=1;
    for(int i=1;i<=n;i++)
    {
        if(mat[a][i] && visited[i] && r!=i) return true;
        else if(mat[a][i] && !visited[i]) return DFS(i, a);
    }
    return false;
}

int main()
{
    int a, b;
    scanf("%i %i", &n, &e);
    for(int i=0;i<e;i++)
    {
        scanf("%i %i", &a, &b);
        mat[a][b]=mat[b][a]=1;
    }
    if(DFS(1, -1)) printf("Ima ciklus!");
    else printf("Nema ciklus!");
}
