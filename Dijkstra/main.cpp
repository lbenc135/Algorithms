#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define edge pair<int,int>
#define node edge

int n, e;                                  // N of vertices, edges
int d[100];
bool visited[100];
vector< edge > g[100];

int dijkstra(int s, int f)
{
    fill(d, d+n+1, 1000000);
    d[s]=0;

    priority_queue<node, vector<node >, greater<node > > q;
    q.push(node(0, s));
    while(!q.empty())
    {
        node tr=q.top();
        q.pop();
        int t=tr.second;
        if(visited[t]) continue;
        visited[t]=1;

        int sz=g[t].size();
        for(int i=0;i<sz;i++)
        {
            int v=g[t][i].first;
            int w=g[t][i].second;
            if(d[v]>d[t]+w)
            {
                d[v]=d[t]+w;
                q.push(node(w, v));
            }
        }
    }

    return d[f];
}

int main()
{
    scanf("%i %i", &n, &e);
    for(int i=0;i<e;i++)
    {
        int u, v, w;
        scanf("%i %i %i", &u, &v, &w);
        g[u].push_back(edge(v, w));
    }
    int s, f;                              // Start, finish node
    scanf("%i %i", &s, &f);

    printf("%i\n", dijkstra(s, f));
}
