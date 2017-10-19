#include <cstdio>
#include <list>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct ovca {int index, x, y;};

ovca stado[100001];
bool polje[20001][20001];

int orijentacija(ovca p, ovca q, ovca r)
{
    return (q.x-p.x)*(r.y-q.y)-(q.y-p.y)*(r.x-q.x);
}

double dist(ovca a, ovca b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

bool compare(ovca o1, ovca o2)
{
    int orient=orijentacija(stado[0], o1, o2);
    if(orient==0) return dist(stado[0], o1)<=dist(stado[0], o2);
    else if(orient>0) return true;
    else return false;
}

void zamjena(ovca &o1, ovca &o2)
{
    ovca temp;
    temp=o1;
    o1=o2;
    o2=temp;
}

void ljuska(int n)
{
    if(n==1) {printf("0.00\n1\n\n"); return;}

    int miny=stado[0].y, minx=stado[0].x, it=0;
    for(int i=1;i<n;i++)
    {
        if(stado[i].y<miny) {miny=stado[i].y; minx=stado[i].x; it=i;}
        else if(stado[i].y==miny && stado[i].x<minx) {miny=stado[i].y; minx=stado[i].x; it=i;}
    }
    zamjena(stado[0], stado[it]);
    if(n==2) {printf("%.2lf\n%i %i\n\n", 2*dist(stado[0], stado[1]), stado[0].index, stado[1].index); return;}
    if(n==3 && orijentacija(stado[0], stado[1], stado[2])==0)
    {
        printf("%.2lf\n%i %i\n\n", 2*dist(stado[0], stado[2]), stado[0].index, stado[2].index);
        return;
    }

    sort(stado+1, stado+n, compare);
    list<ovca> s;
    s.push_back(stado[0]); s.push_back(stado[1]); s.push_back(stado[2]);

    for(int i=3;i<n;i++)
    {
        list<ovca>::iterator druga=--(--s.end());
        while(s.size()>1 && orijentacija(*druga, s.back(), stado[i])!=1)
        {
            s.pop_back();
            druga--;
        }
        s.push_back(stado[i]);
    }

    double opseg=0;
    for(list<ovca>::iterator i=s.begin();i!=s.end();i++)
    {
        if(++i==s.end())
        {
            opseg+=dist(stado[0], s.back());
            i--;
        }
        else
        {
            ovca o=*i;
            i--;
            opseg+=dist(o, *i);
        }
    }
    printf("%.2lf\n", opseg);
    for(list<ovca>::iterator i=s.begin();i!=s.end();i++)
    {
        printf("%i ", (*i).index);
    }
    printf("\n\n");
}

int main()
{
    int t, n, od;
    scanf("%i", &t);
    while(t--)
    {
        od=1;
        scanf("%i", &n);
        for(int i=0;i<n;i++)
        {
            stado[i].index=i+od;
            scanf("%i %i", &stado[i].x, &stado[i].y);
            if(!polje[stado[i].x+10000][stado[i].y+10000])
                polje[stado[i].x+10000][stado[i].y+10000]=true;
            else {i--; n--; od++;}
        }
        ljuska(n);
        for(int i=0;i<n;i++)
            polje[stado[i].x+10000][stado[i].y+10000]=false;
    }
}
