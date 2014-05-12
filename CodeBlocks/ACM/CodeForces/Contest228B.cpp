#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char b[105][105];
bool vis[105][105];

int main(){
    int t, n, c, i,j,k;
    //scanf("%d", &t);
    //while(t--){
    scanf("%d", &n);


    for(i=0; i<n; i++){
        scanf("%s", b[i]);
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(b[i][j]=='#' && !vis[i][j]){
                if(i>n-3||j==0||j>n-2||vis[i+1][j-1]||vis[i+1][j]||vis[i+1][j+1]||vis[i+2][j]){
                    printf("NO\n");
                    return 0;
                }
                vis[i][j]=vis[i+1][j-1]=vis[i+1][j]=vis[i+1][j+1]=vis[i+2][j]=true;
            }
        }
    }

    printf("YES\n");
    return 0;
}
