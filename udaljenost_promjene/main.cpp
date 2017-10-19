#include <iostream>
#include <string>
using namespace std;

int ED(int i, int j);

string s1, s2;

int main()
{
    cin >> s1 >> s2;
    cout << ED(s1.length(), s2.length());
}

int ED(int i, int j)
{
    if(i==0) return j;
    if(j==0) return i;

    if(s1[i-1]==s2[j-1])
        return ED(i-1, j-1);
    else
        return min(ED(i-1, j)+1, min(ED(i, j-1)+1, ED(i-1, j-1)+1));
}
