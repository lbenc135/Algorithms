#include <iostream>

using namespace std;

int main()
{
    int a=5, b=10;
    cout << a << " " << b << endl;

    a^=b;
    b^=a;
    a^=b;

    cout << a << " " << b;
}
