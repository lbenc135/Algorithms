#include <cstdio>
#include <cstring>
using namespace std;

int n, e;
bool g[100][100];
bool visited[100];

bool allVisited()
{
    for(int i=1;i<=n;i++)
        if(!visited[i]) return false;
    return true;
}

bool backtr(int a)
{
    visited[a]=true;
    if(allVisited() && g[a][1]) return true;
    for(int i=1;i<=n;i++)
    {
        if(g[a][i] && !visited[i])
            if(backtr(i)) return true;
    }
    visited[a]=false;
    return false;
}

int main()
{
    scanf("%i %i", &n, &e);
    int a, b;
    for(int i=0;i<e;i++)
    {
        scanf("%i %i", &a, &b);
        g[a][b]=g[b][a]=1;
    }

    if(backtr(1)) printf("Ima ciklus!");
    else printf("Nema ciklus!");
}
