#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int n, e;
int g[100][100];
bool visited[100];
int parent[100];

int dfs(int s, int f)
{
    fill(visited, visited+n+1, 0);
    fill(parent, parent+n+1, -1);

    int minp=1000000;
    bool found=false;
    stack<int> q;
    q.push(s);
    while(!q.empty())
    {
        int tr=q.top();
        q.pop();

        if(parent[tr]!=-1 && g[parent[tr]][tr]<minp)
            minp=g[parent[tr]][tr];
        if(tr==f) { found=1; break; }

        visited[tr]=1;
        for(int i=1;i<=n;i++)
        {
            if(g[tr][i]>0 && !visited[i])
            {
                q.push(i);
                parent[i]=tr;
                visited[i]=1;
            }
        }
    }
    if(found)
        return minp;
    return 0;
}

void oduzmi(int n, int x)
{
    if(parent[n]!=-1)
    {
        g[parent[n]][n]-=x;
        oduzmi(parent[n], x);
    }
}

int max_flow(int s, int f)
{
    int max_protok=0;
    while(true)
    {
        int ret=dfs(s, f);
        if(ret==0) break;

        max_protok+=ret;
        oduzmi(f, ret);
    }
    return max_protok;
}

int main()
{
    scanf("%i %i", &n, &e);
    for(int i=0;i<e;i++)
    {
        int u, v, p;
        scanf("%i %i %i", &u, &v, &p);
        g[u][v]=p;
    }
    int s, f;
    scanf("%i %i", &s, &f);

    printf("%i\n", max_flow(s, f));
}
