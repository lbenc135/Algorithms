#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

double closest();

typedef struct {
    int x, y;
} tocka;

tocka t1, t2;
int n;
vector<tocka> r;

int main()
{
    tocka t;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> t.x >> t.y;
        r.push_back(t);
    }

    cout << closest() << endl;

    cout << t1.x << " " << t1.y << endl << t2.x << " " << t2.y;
}

struct usporediY
{
    bool operator()(const tocka &a, const tocka &b) const
    {
        if (a.y != b.y)
            return a.y < b.y;
        else
            return a.x < b.x;
    }
};

struct usporediX
{
    bool operator()(const tocka &a, const tocka &b) const
    {
        if (a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    }
};

double distan(tocka a, tocka b)
{
    return pow(a.x-b.x, 2)+pow(a.y-b.y, 2);
}

double closest()
{
    sort(r.begin(), r.end(), usporediX());
    int rep=0;
    set<tocka, usporediY> aktivne;
    double h=1000000000;
    for(int i=0;i<n;i++)
    {
        while(r[i].x-r[rep].x>h)
        {
            aktivne.erase(r[rep]);
            rep++;
        }

        set<tocka, usporediY>::const_iterator y1, y2;
        tocka lijeva, desna;
        lijeva.x = -1000000;
        desna.x = 1000000;
        lijeva.y = r[i].y-h;
        desna.y = r[i].y+h;

        y1 = lower_bound(aktivne.begin(), aktivne.end(), lijeva, usporediY());
        y2 = upper_bound(aktivne.begin(), aktivne.end(), desna, usporediY());

        for(set<tocka, usporediY>::const_iterator j=y1; j!=y2; j++)
        {
            double dist=distan(r[i], *j);
            if(dist<h)
            {
                h=dist;
                t1 = r[i]; t2 = *j;
            }
        }

        aktivne.insert(r[i]);
    }
    return h;
}
