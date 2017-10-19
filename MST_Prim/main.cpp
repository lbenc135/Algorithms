/*
	Algoritam: Minimum Spanning Tree( Prim method )
	Autor: Frane Roje
	DUMP 2009
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define p_int pair < int, int >

int N, M;
int graf[100][100] = { 0 };
bool u_stablu[100] = { false };
priority_queue< p_int, vector < p_int >, greater < p_int > > Q;

//U priority_queue se sprema pair < int, int >, prvi clan je tezina brida
//drugi clan je sam cvor u koji vodi taj brid. Brid iz kojeg smo dosli nije
//nam interesantan :-)

int mst_prim()
{
	Q.push( make_pair( 0, 0 ) );

	int spojeno = 0;
	int cijena = 0;
	while( spojeno < N )
	{
		p_int cvor = Q.top(); Q.pop();

		if( u_stablu[ cvor.second ] == false )
		{
			cijena += cvor.first;
			u_stablu[ cvor.second ] = true;

			for( int i = 0; i < N; ++i )
				if( graf[ cvor.second ][i] > 0 && u_stablu[i]== false )
					Q.push( make_pair( graf[ cvor.second ][i], i ) );

			spojeno++;
		}
	}

	return cijena;
}

int main()
{
	cin >> N >> M;
	for( int i = 0; i < M; ++i )
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;

		graf[x][y] = graf[y][x] = z;
	}

	int cijena = mst_prim();
	cout << "Cijena mst-a: " << cijena << endl;
	return 0;
}
