#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int arr[105][105], dp[105][105], h, w;

int recur(int i, int j){
    if(i==h)return 0;
    if(dp[i][j]>-1)return dp[i][j];
    int a=0,b=0,c=0;
    if(j>0)a=recur(i+1, j-1);
    b=recur(i+1, j);
    if(j<w-1)c=recur(i+1, j+1);
    return dp[i][j]=arr[i][j]+max(a,max(b,c));
}

int main(){
    int t,i,j,curV,maxV;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &h, &w);
        for(i=0; i<h; i++)
            for(j=0; j<w; j++)
                scanf("%d", &arr[i][j]);

        maxV=0;
        for(j=0; j<w; j++){
            curV=recur(0,j);
            if(curV>maxV)maxV=curV;
        }
        printf("%d\n", maxV);
    }
    return 0;
}
