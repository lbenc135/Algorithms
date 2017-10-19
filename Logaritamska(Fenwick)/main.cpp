#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

#define MAXNUM 30001
#define BAS 3137
#define ull unsigned long long

pair<ull, int> p[MAXNUM];
ull B[22]={1, BAS};
int f[MAXNUM];
int n, m[MAXNUM];

int zadnjibit(int x)
{
    return x&-x;
}

ull suma(int x)
{
    ull zbroj=0;
    for(;x>0;x-=zadnjibit(x))
        zbroj+=f[x];
    return zbroj;
}

void povecaj(int x, int v)
{
    for(;x<n;x+=zadnjibit(x))
        f[x]+=v;
}

ull gethash(char s[])
{
    int l = strlen(s);
    ull h=0;
    for(int i=0;i<l;i++)
        h+=s[i]*B[i];
    return h;
}

void init()
{
    for(int i=2;i<=21;i++)
        B[i]=B[i-1]*BAS;
}

int BS(ull a)
{
    int l=0, m, h=n;
    while(l<h)
    {
        m=(l+h)/2;
        if(p[m].first==a)
            return m;
        else if(p[m].first>a)
            h=m;
        else
            l=m+1;
    }
    return 0;
}

int main()
{
    init();
    int t;
    char b[22], str[MAXNUM][22];
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i", &n);
        for(int i=0;i<n;i++)
            scanf("%s", &str[i]);
        for(int i=0;i<n;i++)
        {
            scanf("%s", &b);
            p[i].first=gethash(b);
            p[i].second=i+1;
        }
        sort(p, p+n);
        for(int i=0;i<n;i++)
        {
            m[i]=p[BS(gethash(str[i]))].second;
        }

        long long rez=0;
        for(int i=n-1;i>=0;i--)
        {
            rez+=suma(m[i]-1);
            povecaj(m[i], 1);
        }
        printf("%lli\n", rez);
        memset(f, 0, sizeof(f));
    }
}
