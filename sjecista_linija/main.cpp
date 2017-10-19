#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// definiramo strukturu tocka s x i y koordinatama  (xk, yk)
typedef struct {
        int xk,yk;
        }tocka;
// poredano ovako da se dogadaji s istim x-om sortiraju na ovaj nacin
enum tip_dogadjaja
{
    DOGADJAJ_KRAJ,
    DOGADJAJ_VERTIKALA,
    DOGADJAJ_POCETAK
};
// definiramo dogadaj
struct dogadjaj
{
    tip_dogadjaja tip;
    int x;
    int line;        // index pojedine linije u vektoru linije

    // definiramo i operator usporedivanja koji sortira prvo po x-u, a onda po tipu
    bool operator <(const dogadjaj &b) const
    {
        if (x != b.x) return x < b.x;
        else return tip < b.tip;
    }
};
// definiramo liniju gdje je (x1,y1) pocetna, a (x2,y2) zavrsna tocka
struct line
{
    int x1, y1, x2, y2;
};

/* funkcija koja vraca sva sjecista horizontalnih i vertikalnih linija u obliku
 vektora. Linije uzimamo bez rubnih tocaka i za svaku liniju mora biti
 x1 <= x2 i y1 <= y2.*/

 vector<tocka> sjecista(const vector<line> &linije)
{
    int L = linije.size();
    vector<dogadjaj> dogadjaji;
    vector<tocka> rjesenje;

    // Y koordinate aktivnih linija
    multiset<int> aktivne;
    // konvertiramo linije u dogadaje
    for (int i = 0; i < L; i++)
    {
        //ako su razlicite y koordinate, znamo da se radi o vertikalnoj liniji
        if (linije[i].y1 != linije[i].y2)
        {
            dogadjaj temp;
            temp.tip = DOGADJAJ_VERTIKALA;
            temp.x = linije[i].x1;
            temp.line = i;
            dogadjaji.push_back(temp);
        }
        /*ako su razlicite x koordinate, znamo da se radi o horizontalnoj liniji
         i zabiljezimo pocetnu i zavrsnu tocku kao zasebne dogadaje
        */
        else if (linije[i].x1 != linije[i].x2)
        {
            dogadjaj temp1;
            temp1.tip = DOGADJAJ_POCETAK;
            temp1.x = linije[i].x1;
            temp1.line = i;
            dogadjaji.push_back(temp1);

            dogadjaj temp2;
            temp2.tip = DOGADJAJ_KRAJ;
            temp2.x = linije[i].x2;
            temp2.line = i;
            dogadjaji.push_back(temp2);
        }
    }

    // sortiramo dogadaje po x-u
    sort(dogadjaji.begin(), dogadjaji.end());

    // prolazimo kroz dogadaje, horizontalne linije dodajemo u multiskup aktivne
    for (vector<dogadjaj>::const_iterator e = dogadjaji.begin(); e != dogadjaji.end(); ++e)
    {
        switch (e->tip)
        {
        case DOGADJAJ_POCETAK:
            aktivne.insert(linije[e->line].y1);
            break;
        case DOGADJAJ_KRAJ:
            aktivne.erase(aktivne.find(linije[e->line].y1));
            break;
        case DOGADJAJ_VERTIKALA:
            {
                /*ako smo dosli do vertikalne linije, onda prodemo po svim
                 y koordinatama trenutno aktivnih horizontalnih linija*/
                multiset<int>::const_iterator first, last, i;
                first = aktivne.upper_bound(linije[e->line].y1);
                last = aktivne.lower_bound(linije[e->line].y2);
                for (i = first; i != last; ++i)
                {
                    /*tocka sjecista ima istu x koordinatu kao trenutna
                    vertikalna linija, a y koordinatu kao trenutna horizontalna
                     linija*/
                    tocka A;
                    A.xk = e->x;
                    A.yk = *i;
                    rjesenje.push_back(A);
                }
            }
            break;
        }
    }

    return rjesenje;
}
int main()
{
    int n, x1,y1, x2, y2;
    vector<line>linije;
    vector<tocka>rjesenje;
    line ln;

    cin>> n;
    for(int i=0;i<n;i++)
    {
        cin>>ln.x1>>ln.y1>>ln.x2>>ln.y2;
        linije.push_back(ln);
    }

    rjesenje=sjecista(linije);
    cout<<"sjecista"<<endl;
    for(int i=0;i<rjesenje.size();i++)
         cout<<rjesenje[i].xk<<" "<<rjesenje[i].yk<<endl;
    return 0;
}
