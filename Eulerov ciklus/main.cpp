#include <cstdio>
#include <cstring>
using namespace std;

int n, e;
bool g[100][100];

bool allVisited()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(g[i][j]) return false;
    return true;
}

int backtr(int a, int b)
{
    g[a][b]=g[b][a]=0;
    if(allVisited())
    {
        g[a][b]=g[b][a]=1;
        if(b==1) return 2;
        else return 1;
    }
    for(int i=1;i<=n;i++)
    {
        if(g[b][i])
        {
            int r=backtr(b, i);
            if(r)
            {
                g[a][b]=g[b][a]=1;
                return r;
            }
        }
    }
    g[a][b]=g[b][a]=1;
    return 0;
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

    int rez=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(g[i][j])
            {
                int r=backtr(i, j);
                if(r==2) rez=2;
                else if(r==1 && rez==0) rez=1;
            }
        }
    if(rez==2) printf("Ima ciklus!");
    else if(rez==1) printf("Ima staza!");
    else printf("Nema ciklus!");
}
