/*
  532 - Dungeon Master
  UVa Online Judge
  Ricardo Marques
  26/08/2016
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct _EDGE_
{
    int l,r,c;
} edge;


int L,R,C;
int visit[30][30][30];
int posX[6]= {0,0,0,-1,0,1};
int posY[6]= {0,0,-1,0,1,0};
int posL[6]= {1,-1,0,0,0,0};


bool isValidPos(int l, int r, int c, vector<vector<vector<char> > > *graph)
{
    if(l<L && l>=0)
    {
        if(r<R && r>=0)
        {
            if(c<C && c>=0)
            {
                if(graph->at(l)[r][c]=='.'||graph->at(l)[r][c]=='E')
                    return true;
                return false;
            }
        }
    }
    else
        return false;
}

int bfs(edge begin, edge end, vector<vector<vector<char> > > *graph)
{
    queue<edge> s;
    s.push(begin);
    visit[begin.l][begin.r][begin.c]=0;
    while (s.empty() == false)
    {
        edge top = s.front();
        s.pop();
        if(end.l==top.l && end.r==top.r && end.c==top.c)
            return visit[top.l][top.r][top.c];
        for (int i = 0; i < 6; ++i)
        {
            int newl=top.l+posL[i],newr=top.r+posX[i],newc=top.c+posY[i];
            if(isValidPos(newl,newr,newc,graph))
            {
                if(visit[newl][newr][newc]==-1)
                {
                    visit[newl][newr][newc]=visit[top.l][top.r][top.c]+1;
                    edge node = {newl,newr,newc};
                    s.push(node);
                }
            }
        }
    }
    return -1;
}

int main()
{
    char position;
    edge begin,end;

    while(cin>>L>>R>>C)
    {
        if(L==0 && R==0 && C==0)
            exit(0);

        memset (visit,-1,sizeof(visit));
        vector<vector<vector<char> > > graph;
        for (int i = 0; i < L; ++i)
        {
            vector< vector<char> > degree;
            for (int j = 0; j < R; ++j)
            {
                vector<char> line;
                for (int k = 0; k < C; ++k)
                {
                    cin>>position;
                    if(position=='S')
                    {
                        begin.l=i;
                        begin.r=j;
                        begin.c=k;
                    }
                    else if(position=='E')
                    {
                        end.l=i;
                        end.r=j;
                        end.c=k;
                    }
                    line.push_back(position);
                }
                degree.push_back(line);
            }
            graph.push_back(degree);
        }
        int result = bfs(begin,end,&graph);
        if(result == -1)
            cout<<"Trapped!"<<endl;
        else
            cout<<"Escaped in " << result << " minute(s)." << endl;
    }

    return 0;
}
