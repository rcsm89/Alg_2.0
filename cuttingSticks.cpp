/*
 * cuttingSticks.cpp
 *
 *  Created on: 19 Jul 2016
 *      Author: ricardo
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int memo[52][52];
vector<int> cutStick;

int pd(int l, int r)
{
    int aux=0;
    int x=1000000;
    
    if(r-l==1) return 0;
    if(memo[l][r]!=-1) return memo[l][r];

    for(int i=l+1;i<r;i++){
        aux = cutStick[r]-cutStick[l]+pd(l,i)+pd(i,r);
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

        cutStick.clear();
        cutStick.push_back(0);
        for(int i=0;i<n;i++)
        {
            cin>>aux;
            cutStick.push_back(aux);
        }
        cutStick.push_back(L);

        for(int i = 0;i < 52;i++){
            for(int j = 0; j < 52; j++){
                memo[i][j] = -1;
            }
        }

        printf("The minimum cutting is %d.\n",pd(0,n+1));
    }
return 0;
}
