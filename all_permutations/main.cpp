#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char s[20]={0};
    cin >> s;
    cout << s << endl;
    while(next_permutation(s, s+n))
        cout << s << endl;
}
