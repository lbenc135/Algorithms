#include<iostream>
#include <set>
#define NIL -1
using namespace std;

bool graf[100][100];
int V, B;
bool visited[100];
int otkriven[100];
int roditelj[100];
int najmanje[100];
set <int> arttocke;

void DFS(int u)
{
    static int time = 0;

    // broj djece u DFS stablu
    int children = 0;

    // oznacimo da smo posjetili trenutni vrh
    visited[u] = true;

    // inicijaliziramo polja otkriven i najmanje
    otkriven[u] = najmanje[u] = ++time;

    // prolazimo po svim susjednim vrhovima od u
    for (int i = 1; i <= V; i++)
    {
        if(graf[u][i])
            //ako jos nismo posjetili
            if (!visited[i])
            {
                children++;
                roditelj[i] = u;
                DFS(i);
                //provjerimo ima li podstablo s korijenom i vezu s pretkom od u
                najmanje[u]  = min(najmanje[u], najmanje[i]);

                // u je artikulacijska tocka u sljedecim slucajevima

                // (1) u je korijen DFS stabla i ima barem 2 djeteta
                if (roditelj[u] == NIL && children > 1)
                   arttocke.insert(u);

                // (2) u nije korijen i vrijednost najmanje[i] od jednog njegovog djeteta je vece od otkriven[u]
                if (roditelj[u] != NIL && najmanje[i] >= otkriven[u])
                   arttocke.insert(u);
            }
            else if (i != roditelj[u])
                najmanje[u]  = min(najmanje[u], otkriven[i]);
    }
}

void artikulacijske()
{
    for (int i = 1; i <= V; i++)
        roditelj[i] = NIL;
    for (int i = 1; i <= V; i++)
        if (visited[i] == false)
            DFS(i);

    // ispis tocaka
    set<int>::iterator it;
    for (it=arttocke.begin(); it!=arttocke.end(); ++it)
        cout << *it << ' ';
}

int main()
{
    cin>>V>>B;
    for(int i=0; i<B;i++)
    {
        int x,y;
        cin>>x>>y;
        graf[x][y]=true;
        graf[y][x]=true;
    }
    artikulacijske();
    return 0;
}
