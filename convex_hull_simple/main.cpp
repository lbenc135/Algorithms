#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int x, y;

    bool operator<(const point &p) const
    {
        if(x!=p.x) return x<p.x;
        else return y<p.y;
    }
};

int n;
vector<point> p, sol;

int orient(point o, point a, point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

void convex()
{
    int k=0;
    sort(p.begin(), p.end());
    sol.resize(2*n);

    for(int i=0;i<n;i++)
    {
        while(k>=2 && orient(sol[k-2], sol[k-1], p[i])<=0) k--;
        sol[k++]=p[i];
    }

    int t=k+1;
    for(int i=n-2;i>=0;i--)
    {
        while(k>=t && orient(sol[k-2], sol[k-1], p[i])<=0) k--;
        sol[k++]=p[i];
    }

    sol.resize(k-1);
}

int main()
{
    scanf("%i", &n);
    p.resize(n);
    for(int i=0;i<n;i++)
        scanf("%i %i", &p[i].x, &p[i].y);

    convex();

    for(int i=0;i<sol.size();i++)
        printf("\n%i %i", sol[i].x, sol[i].y);
}
