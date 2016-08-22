#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct _point_{
    int i;
    int j;
}Point;

int col, row;
int Maze[300][300];
const int directions[][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void newMaze(string line, int beg)
{
    for (int j = 0; line[j]; ++j) {
        int k = beg * 3, l = j * 3;
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                Maze[k+x][l+y] = 0;
        if (line[j] == '\\') {
            Maze[k][l] = 1;
            Maze[k+1][l+1] = 1;
            Maze[k+2][l+2] = 1;
        }
        else {
            Maze[k][l+2] = 1;
            Maze[k+1][l+1] = 1;
            Maze[k+2][l] = 1;
        }
    }
}

bool findCycles(int i, int j, int &longest)
{
    queue<Point> Q;
    Q.push({i,j});
    int length = 1;
    bool isCycle = 1;
    Point cur, nxt;
    while (!Q.empty()) {
        length++;
        cur = Q.front();
        Q.pop();

        for (int x = 0; x < 4; ++x) {
            nxt.i = cur.i + directions[x][0];
            nxt.j = cur.j + directions[x][1];
            if (nxt.i < 0 || nxt.j < 0 || nxt.i >= row || nxt.j >= col) {
                isCycle = 0;
                continue;
            }
            if (Maze[nxt.i][nxt.j] == 0) {
                Maze[nxt.i][nxt.j] = 1;
                Q.push(nxt);
            }
        }
    }
    if (isCycle == 0) return 0;
    if (longest < length) longest = length;
    return 1;
}

int main()
{
    int maze = 1;
    char line[100];
    int numOfCycles;
    int longest;
    
    while (cin>>col>>row) {
        if(!col || !row) break;
        for (int i = 0; i < row; ++i){
            cin>>line;
            newMaze(line, i);
        }
        
        row *= 3;
        col *= 3;
        numOfCycles = 0;
        longest = 0;
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (Maze[i][j] == 0)
                    if (findCycles(i, j, longest))
                        numOfCycles++;
        printf("Maze #%d:\n", maze++);

        if (numOfCycles)
            printf("%d Cycles; the longest has length %d.\n", numOfCycles, longest/3);
        else 
            printf("There are no cycles.\n");
    }

    return 0;
}
