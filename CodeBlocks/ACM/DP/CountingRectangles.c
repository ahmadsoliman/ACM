#include <stdio.h>
#include <string.h>
#include <math.h>

int grid[105][105];
char in[105];

int main(){
    int n,m, i,j,k,l, s,c;
    memset(grid, 0, sizeof grid);
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        scanf("%d", &m);
        for(i=1; i<=n; i++){
            scanf("%s", in);
            for(j=1; j<=m; j++){
                grid[i][j]=(in[j-1]-'0')+grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }
        c=0;
        for(i=1; i<=n; i++)
        for(j=i; j<=n; j++)
        for(k=1; k<=m; k++)
        for(l=k; l<=m; l++){
            s = grid[j][l]-grid[j][k-1]-grid[i-1][l]+grid[i-1][k-1];
            if(s==(j-i+1)*(l-k+1)) c++;
        }

        printf("%d\n", c);
    }
    return 0;
}
