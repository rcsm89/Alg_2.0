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

int pd(int a, int b)
{
    if(b-a==1) return 0;
    
    if(memo[a][b]!=-1) return memo[a][b];

    int x=1000000;

    for(int i=a+1;i<b;i++)
        x=min(v[b]-v[a]+pd(a,i)+pd(i,b),x);

    return memo[a][b]=x;
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
