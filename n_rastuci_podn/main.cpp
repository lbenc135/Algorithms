#include <iostream>
using namespace std;

#define MAXN 1000000

int best[MAXN];
int niz[MAXN], n;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> niz[i];

    int j, sol=0;
    for(int i=0;i<n;i++)
    {
        best[i]=100000000;
        for(j=0;best[j]<niz[i];j++)
            ;
        best[j]=niz[i];
        sol=max(sol, j+1);
    }
    cout << sol;
}
