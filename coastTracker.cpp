#include <iostream>
#include <cstdio>

using namespace std;

int i, j, k;
int xi[10], yi[10], si[10];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

void coastTracker(int d, int x, int y)
{
    int tx, ty;

    for(i = d+5, j = 0; j < 8; j++, i++)
    {
        i = (i+8)%8;
        tx = x+dx[i], ty = y+dy[i];
        for(k = 0; k < 8; k++)
        {
            if(xi[k] == tx && yi[k] == ty && si[k] == 1)
                break;
        }
        if(k != 8)
        {
            cout << i << endl;
            break;
        }
    }
}
int main()
{
    int x, y, d;

    while(cin>>x>>y>>d)
    {
        for(i = 0; i < 8; i++)
            cin>>xi[i]>>yi[i]>>si[i];
        coastTracker(d, x, y);
    }
    return 0;
}
