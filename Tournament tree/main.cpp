#include <iostream>
using namespace std;

#define MAXN 1048576 //2^20

int t[MAXN];
int n, N=1;

void add(int v, int pos)
{
    pos+=N;
    for(;pos>0;pos/=2)
        t[pos]+=v;
}

int query(int a, int b, int lo, int hi, int r=1)
{
    if(a<=lo && b>=hi) return t[r];
    if(b<lo || a>hi) return 0;
    return  query(a, b, lo, (lo+hi)/2, r*2) +
            query(a, b, (lo+hi)/2+1, hi, r*2+1);
}

int main()
{
    cin >> n;
    while(N<n) N*=2;
    int a;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        add(a, i);
    }
    cout << query(0, n-1, 0, N-1);
}
