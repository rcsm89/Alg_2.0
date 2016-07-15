/*
 * cuttingSticks.cpp
 *
 *  Created on: 14 Jul 2016
 *      Author: ricardo
 */
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int memo[52][52];
vector<int> v;

int pd(int l, int r)
{
    int aux=0;
    int x=1000000;
    if(r-l==1) return 0;
    if(memo[l][r]!=-1) return memo[l][r];

    for(int i=l+1;i<r;i++){
        aux = v[r]-v[l]+pd(l,i)+pd(i,r);
        aux<=x?x=aux:x;
    }
    return memo[l][r]=x;
}

int main()
{
    int L, n, aux;

    while(1)
    {
        scanf("%d", &L);
        if(L==0) break;

        scanf("%d", &n);

        v.clear();
        v.push_back(0);
        for(int i=0;i<n;i++)
        {
            cin>>aux;
            v.push_back(aux);
        }
        v.push_back(L);

        for(int i = 0;i < 52;i++){
            for(int j = 0; j < 52; j++){
                memo[i][j] = -1;
            }
        }

        printf("The minimum cutting is %d.\n",pd(0,n+1));
    }
    return 0;
}
