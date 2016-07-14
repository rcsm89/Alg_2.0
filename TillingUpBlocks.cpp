#include <stdio.h>
int n;
int tiles[101][101];
int memo[101][101];

int pd(int l, int m) {
    if(l==0 || m==0) return 0;
    if(l==1&&m==1) return tiles[1][1];
    if(memo[l][m]!=-1) return memo[l][m];
    
    int aux1 = pd(l-1, m);
    int aux2 = pd(l,m-1);
    int max = aux1>aux2 ? aux1 : aux2;

    return memo[l][m] = max + tiles[l][m];
}

int main() {
    while(1) {
        scanf("%d", &n);
        if(n==0) break;
        
        for(int i=1; i<=100; i++) {
            for(int j=1; j<=100; j++) {
                tiles[i][j] = 0;
                memo[i][j] = -1;
            }
        }

        for(int i=0; i<n; i++) {
            int t1, t2;
            scanf("%d%d", &t1, &t2);
            tiles[t1][t2]++;
        }
        printf("%d\n", pd(100,100) );
    }
    
    printf("*\n");
    
    return(0);
}
