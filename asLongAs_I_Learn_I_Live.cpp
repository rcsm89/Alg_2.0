#include <iostream>
#include <cstdio>

using namespace std;

int g[105][105], gt[105], v[105], cases = 0;

void read(int m, int x, int y)
{
    while(m--)
    {
        cin>>x>>y;
        g[x][gt[x]++] = y;
    }
}

void learning()
{
    int nd = 0, learn = 0, i, j, w;
    while(true)
    {
        learn += v[nd];
        w = 0;
        for(i = 0; i < gt[nd]; i++)
        {
            if(v[g[nd][i]] > w)
                j = g[nd][i], w = v[j];
        }
        if(w == 0) break;
        nd = j;
    }
    cout<<"Case "<< ++cases << ": " << learn << " " << nd << endl;
}

int main()
{
    int t;

    int i, j, n, m, x, y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i = 0; i < n; i++)
        {
            cin>>v[i];
            gt[i] = 0;
        }
        read(m, x, y);
        learning();
    }
    return 0;
}