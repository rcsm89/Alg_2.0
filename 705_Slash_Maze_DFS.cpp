#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int row, col, boundary, sum;
int Maze[300][300], visit[300][300];
const int moves[4][2] = {{1, 0}, {-1, 0}, {0 , 1}, {0, -1}};

int createMaze()
{
    char ch;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>ch;
            if (ch == '\\')
            {
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                    {
                        if (x == y)
                            Maze[i * 3 + x][j * 3 + y] = 1;
                        else
                            Maze[i * 3 + x][j * 3 + y] = 0;
                    }
            }
            else
            {
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                    {
                        if (x + y == 2)
                            Maze[i * 3 + x][j * 3 + y] = 1;
                        else
                            Maze[i * 3 + x][j * 3 + y] = 0;
                    }
            }
        }
    }
}

void DFS(int a, int b)
{
    visit[a][b] = 1;
    sum++;
    int p, q;
    for (int i = 0; i < 4; i++)
    {
        p = a + moves[i][0];
        q = b + moves[i][1];
        if (p < 0 || p >= row) continue;
        if (q < 0 || q >= col) continue;
        if (Maze[p][q] || visit[p][q])	continue;
        if (p == 0 || p == row - 1 || q == 0 || q == col - 1)
            boundary = 1;
        DFS(p, q);
    }
}
int main()
{
    int mazes, longest, cont = 1;
    while (cin>>col>>row)
    {
    	if(!col || !row)
			break;
        memset(Maze, 0, sizeof(Maze));
        memset(visit, 0, sizeof(visit));
        mazes = longest = 0;

        createMaze();
        row *= 3;
        col *= 3;

        for (int i = 1; i < row - 1; i++)
            for (int j = 1; j < col - 1; j++)
            {
                if (visit[i][j] || Maze[i][j])
                    continue;
                sum = boundary = 0;
                DFS(i, j);
                if (!boundary)
                {
                    mazes++;
                    if (longest < sum)
                        longest = sum;
                }
            }

		cout<<"Maze #"<< cont++ << ":" << endl;
        if (mazes)
            cout<< mazes <<" Cycles; the longest has length "<< longest/3 << ".\n\n" << endl;
        else
			cout << "There are no cycles.\n\n";
    }
}
