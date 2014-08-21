#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int sum[35], ot1, ot2, n, cnts[35], cost1[35][25], cost2[35][25], dp[35][305];

int recur(int i, int t1){
    if(i==n) return dp[i][t1]=0;
    int t2 = ot2-(sum[i]-(ot1-t1));
    if(dp[i][t1]!=-1) return dp[i][t1];

    int minv=1000000000;
    for(int j=0; j<=min(cnts[i], t1); j++){
        if(cnts[i]-j>t2) continue;
        minv = min(minv, cost1[i][j]+cost2[i][cnts[i]-j]+recur(i+1, t1-j));
    }
    return dp[i][t1]=minv;
}

int main() {
    int t1,t2,k,minj,minv,curv;

    while(scanf("%d %d", &t1, &t2)){
        if(t1==0 && t2==0) break;
        ot1=t1, ot2=t2;
        memset(sum, 0, sizeof sum);
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &k);
            cnts[i]=k;
            sum[i+1]=sum[i]+k;
            for(int j=0; j<k; j++) scanf("%d", &cost1[i][j+1]);
            for(int j=0; j<k; j++) scanf("%d", &cost2[i][j+1]);
        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0, t1));

        for(int i=0; i<n; i++){
            minj=0, minv=1000000000;
            t2 = ot2-(sum[i]-(ot1-t1));
            for(int j=0; j<=min(cnts[i], t1); j++){
                if(cnts[i]-j>t2) continue;
                curv = cost1[i][j]+cost2[i][cnts[i]-j]+dp[i+1][t1-j];
                if(curv<minv){
                    minv=curv;
                    minj=j;
                }
            }
            t1-=minj;
            t2-=cnts[i]-minj;
            printf("%d", minj);
            if(i<n-1) printf(" ");
        }
        printf("\n\n");
    }
    return 0;

}
