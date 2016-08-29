#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

#define N 101
#define G 1e9

using namespace std;
int C, S, Q, Case = 1;
int d[N][N];
int i, j, k;

int getInput()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' '&&c != '\n')
        n = n * 10 + c - '0';
    return n;
}

void getDecibel(int c1, int c2)
{
    for (i = 0; i < S; i++)
    {
        int decibel;
        c1 = getInput(), c2 = getInput(), decibel = getInput();
        d[c1][c2] = d[c2][c1] = decibel;
    }
}

void getMax()
{
    for (k = 1; k <= C; k++)
        for (i = 1; i <= C; i++)
            for (j = 1; j <= C; j++)
            {
                int maximo = max(d[i][k], d[k][j]);
                if (maximo < d[i][j])
                    d[j][i] = d[i][j] = maximo;
            }
}

void solve()
{
    if(Case==1)
        cout << "Case #" << Case++ << endl;
    else
        cout << "\nCase #" << Case++ << endl;
    //Case++;

    for (int i = 0; i < Q; i++)
    {
        int c1, c2;
        c1 = getInput(), c2 = getInput();

        if (d[c1][c2] != G)
            cout << d[c1][c2] << endl;
        else
            cout << "no path" << endl;
    }
}

void init()
{
    for (i = 0; i <= C; i++)
        for (j = 0; j <= C; j++)
            d[i][j] = G;
}
int main()
{

    while (C = getInput())
    {
        S = getInput();
        Q = getInput();

        init();
        int  c1, c2;
        getDecibel(c1, c2);

        getMax();
        solve();
    }
    return 0;
}
