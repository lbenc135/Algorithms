#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair<int,int>

void kruskal();
int findparent(int x);

int n, e, total=0;
vector<pair<int, edge > > g;
int parent[1000];

int main()
{
    int u, v, w;
    cin >> n >> e;
    for(int i=0;i<e;i++)
    {
        cin >> u >> v >> w;
        g.push_back(pair<int, edge >(w, edge(u, v)));
        parent[i+1]=i+1;
    }

    kruskal();

    cout << total;
}

void kruskal()
{
    int pu, pv;
    sort(g.begin(), g.end());
    for(int i=0;i<e;i++)
    {
        pu=findparent(g[i].second.first);
        pv=findparent(g[i].second.second);
        if(pu!=pv)
        {
            total+=g[i].first;
            parent[pu]=parent[pv];
        }
    }
}

int findparent(int x)
{
    if(x!=parent[x])
        parent[x] = findparent(parent[x]);
    return parent[x];
}
