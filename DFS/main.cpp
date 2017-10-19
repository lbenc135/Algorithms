#include <iostream>
#include <stack>
using namespace std;

bool DFS(int s, int e);

int susjedstvo[100][100];
bool visited[100];
int n, e;

int main()
{
    cin >> n >> e;
    for(int i=0;i<e;i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        susjedstvo[a][b] = d;
    }
    int s, f;
    cin >> s >> f;

    cout << DFS(s, f);
}

bool DFS(int s, int e)
{
    stack<int> st;
    st.push(s);

    while(!st.empty())
    {
        int t = st.top();
        st.pop();
        if(t==e)
            return true;
        for(int i=1;i<=n;i++)
            if(susjedstvo[t][i]!=0 && !visited[i])
            {
                st.push(i);
                visited[i]=true;
            }

    }
    return false;
}
