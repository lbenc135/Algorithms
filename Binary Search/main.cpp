#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int niz[10];

int bs_low(int a)
{
    int l=0, m, h=n;
    while(l<h)
    {
        m=(l+h)/2;
        if(niz[m]>=a) h=m;
        else l=m+1;
    }
    return niz[l]==a?l:-1;
}

int bs_high(int a)
{
    int l=0, m, h=n;
    while(l<h)
    {
        m=(l+h)/2;
        if(niz[m]>a) h=m;
        else l=m+1;
    }
    return niz[l-1]==a?l-1:-1;
}

int main()
{
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%i", &niz[i]);
    int a;
    scanf("%i", &a);

    sort(niz, niz+n);
    for(int i=0;i<n;i++)
        printf("%i ", niz[i]);

    printf("\nlow: %i", bs_low(a));
    printf("\nhigh: %i", bs_high(a));
}
