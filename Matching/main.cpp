#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 310

int n, m, k, rj;
int bio[MAXN], par[MAXN];

vector<int> v[MAXN];

int upari(int x)
{
    bio[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int cura=v[x][i];
        if(par[cura]==-1 || !bio[par[cura]] && upari(par[cura]))
        {
            par[cura]=x;
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d %d",&n, &m, &k);
    for(int i=0;i<k;i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
    }
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;i++)
    {
        memset(bio, 0, sizeof(bio));
        rj+=upari(i);
    }
    printf("%d\n",rj);
    return 0;
}
