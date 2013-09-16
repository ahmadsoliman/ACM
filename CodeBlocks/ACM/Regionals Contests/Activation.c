#include <stdio.h>

int vis[2005][2005], n,m,k, countAll, countRes, kase;
double dp[2005][2005], p1, p2, p3, p4;

double recur(int i, int rest, int depth){
    if(depth==0){
        countAll++;
        //if(i<k) return 1;
        //else
            return 0;
    }
    //if(vis[i][rest]==kase)
     //   return dp[i][rest];

    if(i==0)
        dp[i][rest] = (p2*recur(rest, 0, depth-1) + p4*((i<k)?1:0))/(1.0-p1);
    else
        dp[i][rest] = (p2*recur(i-1, rest+1, depth-1) + p3*recur(i-1, rest, depth-1) + p4*((i<k)?1:0))/(1.0-p1);

    vis[i][rest] = kase;
    return dp[i][rest];
}

int main(){
    kase=0;
    while(scanf("%d %d %d %lf %lf %lf %lf", &n, &m, &k, &p1, &p2, &p3, &p4)>0){
        countAll=countRes=0;
        printf("%.5lf\n",  recur(m, n-m, 16));
        kase++;
    }
    return 0;
}
