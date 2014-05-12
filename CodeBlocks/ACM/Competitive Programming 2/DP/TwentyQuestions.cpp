#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <string>
#include <bitset>

using namespace std;

#define INF 1000000000

typedef pair<int, bitset<128> > bi;

int m, n, cur, res;
char nums[150][15];
bi dp[12][1<<11];

bi recur(int i, int bm){
    if(i==m) return bi(0, bitset<128>());

    if(dp[i][bm].first!=-1) return dp[i][bm];

    bi a=recur(i+1, bm), b=recur(i+1, bm|(1<<i));

    b.first+=1;
    for(int j=0; j<n; j++){
        if(cur!=j && nums[j][i]!=nums[cur][i]) b.second[j]=1;
    }

    int f1=a.second.count(), f2=b.second.count();

    if(f1==n-1) res=min(res, a.first);
    if(f2==n-1) res=min(res, b.first);

    if(f1==f2){
        if(a.first<=b.first) return dp[i][bm]=a;
        return dp[i][bm]=b;
    }

    if(f1>f2) return dp[i][bm]=a;
    return dp[i][bm]=b;
}

int main(){
    int i,j,k, maxv;
    bitset<128> e;

    while(scanf("%d %d", &m, &n)>0){
        if(m==0 && n==0) return 0;


        for(i=0; i<n; i++) scanf("%s", nums[i]);

        maxv=0;
        for(i=0; i<n; i++) {
            cur=i;
            res=INF;
            for(j=0; j<m; j++) for(k=0; k<(1<<m); k++) dp[j][k]=bi(-1, e);
            recur(0, 0);
            maxv=max(maxv, res);
        }
        printf("%d\n", maxv);
    }

    return 0;
}
;
