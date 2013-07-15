#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, done, arr[16], dp[16][32770], dp2[16][32770], shift[16];

int recur(int last, int bm){
    if(bm==done){
        dp2[last][bm]=1;
        return dp[last][bm] = arr[last];
    }
    if(dp[last][bm]!=-1)
        return dp[last][bm];
    int j,c, maxV=0, curV;
    for(j=0; j<n-1; j++) {
        if(!(bm & shift[j])){
            curV = abs(arr[j+1]-arr[last])+recur(j+1, bm|shift[j]);
            if(curV>maxV) maxV = curV;
        }
    }
    for(j=0,c=0; j<n-1; j++) {
        if(!(bm & shift[j])){
            curV = abs(arr[j+1]-arr[last])+dp[j+1][bm|shift[j]];
            if(curV==maxV) c+=dp2[j+1][bm|shift[j]];
        }
    }
    dp2[last][bm] = c;
    return dp[last][bm] = maxV;
}

int main(){
    int i,v;
    for(i=0; i<16; i++) shift[i]=(1<<i);
    while(scanf("%d", &n)>0) {
        if(n==0)
            break;
        done=0;
        for(i=0; i<n; i++) {done<<=1; done|=1;};
        n++;
        for(i=1; i<n; i++) scanf("%d", &arr[i]);
        memset(dp, -1, sizeof dp);
        v = recur(0,0) + 2*(n-1);
        printf("%d %d\n", v, dp2[0][0]);
    }
    return 0;
}
