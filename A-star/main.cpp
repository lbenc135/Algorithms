#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct cvor {
    int x, y, px=-1, py;
    int g=0, h=0, f=0;
};

vector<cvor> q;
vector<cvor> starts;

int findF() {
    int mini;
    unsigned minf=1000000000;
    for(int i=0;i<q.size();i++)
        if(q[i].f<minf) {minf = q[i].f; mini=i;}
    return mini;
}

int findG(int x, int y)
{
    for(int i=q.size()-1;i>0;i--)
        if(q[i].x==x && q[i].y==y) return i;
}

int a,b;

int main()
{
    bool found, foundany=false, foundall=true, corner=false;
    int iter[16]={1,-1,0,0,1,-1,1,-1,  0,0,1,-1,1,-1,-1,1};
    cvor start, finish;
    cin >> a >> b;
    int opened[a][b], closed[a][b];
    char polje[a][b];
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
        {
            cin >> polje[i][j];
            if(polje[i][j]=='S') {start.x=i; start.y=j; starts.push_back(start);}
            if(polje[i][j]=='F') {finish.x=i; finish.y=j;}
        }

    int start_s=clock();

    cvor susjed;
    int x2, y2, it;
    for(int g=0;g<starts.size();g++)
    {
        q.erase(q.begin(), q.end());
        q.push_back(starts[g]);
        found=false;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                opened[i][j]=0; closed[i][j]=0;
            }
        polje[q[0].x][q[0].y]='S';
        while(found!=true)
        {
            it=findF();
            if(q[it].f==10000000) {foundall=false; break;}
            int x=q[it].x, y=q[it].y;
            closed[x][y] = 1;
            corner=false;
            for(int i=0;i<8;i++)
            {
                if(corner==true && i>3) break;
                susjed = q[it];
                x2=x+iter[i];
                y2=y+iter[i+8];
                if(x2<0 || y2<0 || x2>=a || y2>=b) continue;
                susjed.x=x2; susjed.y=y2;
                if(polje[x2][y2]=='#' && i<4) corner=true;
                if(opened[x2][y2]==0 && closed[x2][y2]==0 && polje[x2][y2]!='#')
                    {susjed.h = 10*(abs(x2-finish.x)+abs(y2-finish.y)); if(susjed.h==0) {found=true; foundany=true; break;}
                    susjed.px=x; susjed.py=y; susjed.g+=i<4?10:14; susjed.f=susjed.g+susjed.h;
                    q.push_back(susjed); opened[x2][y2]=1;}
                else if(opened[x2][y2]==1) {
                    int sus = findG(x2, y2);
                    if(q[it].g+(i<4?10:14)>=q[sus].g) continue;
                    else
                        {q[sus].g=q[it].g+(i<4?10:14); q[sus].f=q[sus].g+q[sus].h; q[sus].px=x; q[sus].py=y;}
                }
            }
            q[it].f=10000000;
        }
        while(q[it].px!=-1)
        {
            polje[q[it].x][q[it].y]='o';
            q[it]=q[findG(q[it].px, q[it].py)];
        }
    }

    int stop_s=clock();

    cout << endl;
    if(foundany==true)
    {
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
                cout << polje[i][j];
            cout << endl;
        }
        cout << endl;
        if(foundall==true) cout << "Found all paths!" << endl;
        else cout << "Some paths could not be found!" << endl;
    }
    else cout << "Path(s) not found!";

    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
}
