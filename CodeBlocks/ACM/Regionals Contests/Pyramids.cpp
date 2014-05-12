#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

#define INF 1000000000

using namespace std;

int dp[7][1000002], sumHigh[200], sumLow[200];

int recur(int c, int last){
    if(dp[last][c]!=-1) return dp[last][c];

    if(c==0) return dp[last][c]=0;

    int minv=INF, v;
    for(int i=last-1; i>1; i--){
        if(sumHigh[i]<=c) {
            v = recur(c-sumHigh[i], i);
            if(v!=INF) {
                minv=min(minv, 1+v);
            }
        }
        if(sumLow[i]<=c && i>2) {
            v = recur(c-sumLow[i], i);
            if(v!=INF) {
                minv=min(minv, 1+v);
            }
        }
    }
    return dp[last][c]=minv;
}

void recons(int c, int last){
    if(c==0) return;

    int minv=INF, v, base, left;
    bool up;
    for(int i=last-1; i>1; i--){
        if(sumHigh[i]<=c) {
            v = dp[i][c-sumHigh[i]];
            if(v!=INF) {
                if(1+v<minv){
                    up=true;
                    base=i;
                    left = c-sumHigh[i];
                }
                minv=min(minv, 1+v);
            }
        }
        if(sumLow[i]<=c && i>2) {
            v = dp[i][c-sumLow[i]];
            if(v!=INF) {
                if(1+v<minv){
                    up=false;
                    base=i;
                    left = c-sumLow[i];
                }
                minv=min(minv, 1+v);
            }
        }
    }
    printf(" %d%c", base, ((up)?'H':'L'));
    recons(left, base);
}

int main(){
    sumHigh[0]=0;
    sumLow[0]=0;
    sumHigh[1]=1;
    sumLow[1]=1;
    for(int i=2; i<182; i++){
        sumHigh[i]=sumHigh[i-1]+i*i;
        sumLow[i]=sumLow[i-2]+i*i;
    }
    memset(dp, -1, sizeof dp);

    int c, kase=1;
    while(scanf("%d", &c)){
        if(!c) break;
        if(recur(c, 183)==INF) printf("Case %d: impossible\n", kase++);
        else {
            printf("Case %d:", kase++);
            recons(c, 183);
            printf("\n");
        }
    }
    return 0;
}
