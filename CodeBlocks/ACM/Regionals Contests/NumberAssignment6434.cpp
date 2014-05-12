#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define INF 1000000000

using namespace std;

int n, dp[105][105];
vector<int> nums;

int recur(int i, int m){
    if(i==n){
        if(m==0) return 0;
        return INF;
    }
    if(m==0) return INF;
    if(dp[i][m]!=-1) return dp[i][m];

    int minv=recur(i+1, m-1), cur;
    for(int j=i+1; j<n; j++){
        cur = nums[i]-nums[j]+recur(j+1, m-1);
        minv=min(minv, cur);
    }
    return dp[i][m]=minv;
}

int main(){
    int t, i,j,k, m, kase=1;
    scanf("%d", &t);
    while(t--){
        nums.clear();
        scanf("%d %d", &n, &m);
        for(i=0; i<n; i++){
            scanf("%d", &k);
            nums.push_back(k);
        }
        sort(nums.rbegin(), nums.rend());
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %d\n", kase++, recur(0,m));
    }
    return 0;
}
