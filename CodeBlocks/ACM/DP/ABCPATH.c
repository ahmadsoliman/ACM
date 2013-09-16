#include <stdio.h>
#include <string.h>

int H,W, arr[51][51], dp[51][51];

int recur(int i, int j){
    int cur, res=0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i<H-1&&arr[i][j]==arr[i+1][j]-1){
        cur=recur(i+1,j);
        if(cur>res)res=cur;
    }
    if(j<W-1&&arr[i][j]==arr[i][j+1]-1){
        cur=recur(i,j+1);
        if(cur>res)res=cur;
    }
    if(i>0&&arr[i][j]==arr[i-1][j]-1){
        cur=recur(i-1,j);
        if(cur>res)res=cur;
    }
    if(j>0&&arr[i][j]==arr[i][j-1]-1){
        cur=recur(i,j-1);
        if(cur>res)res=cur;
    }

    if(i<H-1&&j<W-1&&arr[i][j]==arr[i+1][j+1]-1){
        cur=recur(i+1,j+1);
        if(cur>res)res=cur;
    }
    if(i<H-1&&j>0&&arr[i][j]==arr[i+1][j-1]-1){
        cur=recur(i+1,j-1);
        if(cur>res)res=cur;
    }
    if(i>0&&j<W-1&&arr[i][j]==arr[i-1][j+1]-1){
        cur=recur(i-1,j+1);
        if(cur>res)res=cur;
    }
    if(i>0&&j>0&&arr[i][j]==arr[i-1][j-1]-1){
        cur=recur(i-1,j-1);
        if(cur>res)res=cur;
    }
    return dp[i][j] = res+1;
}

char s[55];

int main(){
    int i,j, kase=1, res,cur;
    while(1){
        scanf("%d", &H);
        scanf("%d", &W);
        if(H==0&&W==0) return 0;
        for(i=0;i<H;i++){
            scanf("%s", &s);
            for(j=0;j<W;j++) {
                arr[i][j]=s[j]-'A';
            }
        }

        memset(dp, -1, sizeof dp);
        res=0;
        for(i=0;i<H;i++)
        for(j=0;j<W;j++) {
            if(arr[i][j]==0){
                cur = recur(i,j);
                if(cur>res) res=cur;
            }
        }
        printf("Case %d: %d\n", kase++, res);
    }
    return 0;
}
