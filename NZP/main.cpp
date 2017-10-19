#include <iostream>
#include <string>
using namespace std;

string nzp(int i, int j);

string stanje[100][100];
string s1, s2;

int main()
{
	cin >> s1 >> s2;

	cout << nzp(s1.length(), s2.length());
}

string nzp(int i, int j)
{
    if(i==0 || j==0) return "";
    if(stanje[i][j]!="") return stanje[i][j];

    if(s1[i-1]==s2[j-1])
        stanje[i][j] = nzp(i-1, j-1) + s1[i-1];
    else
    {
        if(nzp(i-1, j).length() > nzp(i, j-1).length())
            stanje[i][j] = nzp(i-1, j);
        else stanje[i][j] = nzp(i, j-1);
    }
    return stanje[i][j];
}
