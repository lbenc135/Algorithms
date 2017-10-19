#include <iostream>
using namespace std;

int knapsack(int cc);

int w[10], v[10], n;
int stanje[100];

int main()
{
    int cc;
    cin >> cc >> n;
    for(int i=0;i<n;i++)
        cin >> w[i] >> v[i];

    cout << knapsack(cc);
}

int knapsack(int cc)
{
    if(stanje[cc]!=0) return stanje[cc];
    int maxv=0;

    for(int i=0;i<n;i++)
    {
        if(cc-w[i]>=0 && knapsack(cc-w[i])+v[i]>maxv)
            maxv=knapsack(cc-w[i])+v[i];
    }
    return stanje[cc]=maxv;
}
