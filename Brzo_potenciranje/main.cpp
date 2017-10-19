#include <iostream>
using namespace std;

int main()
{
    long long a, x=1;
    int n, r;
    cin >> a >> n;

    while(1)
    {
        r=n%2;
        n/=2;
        if(r==1) x*=a;
        if(n==0) break;
        a*=a;
    }

    cout << x;
}
