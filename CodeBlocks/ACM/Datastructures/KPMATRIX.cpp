#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

int mat[300][300], dp[300][300];
int n,m;

int lb(int j, int key){
    int begin=1, end=n;
    while(begin < end) {
        // Find the median value between the iterators
        int Middle = (begin + end) / 2;

        // Re-adjust the iterators based on the median value
        if(dp[Middle][j] == key){
            end = Middle;
        }else if(dp[Middle][j] > key){
            end = Middle;
        }else{
            begin = Middle + 1;
        }
    }

    return begin;
}

int main(){
    int a,b;
    scanf("%d %d", &n, &m);

    n++, m++;
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    scanf("%d %d", &a, &b);

    memset(dp, 0, sizeof dp);

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i][j];
        }
    }
    int cnt=0;
    for(int i=1; i<n; i++)
    for(int j=1; j<m; j++){
        if(dp[i][j]<a) continue;
        if(dp[i][j]==a) cnt++;
        else if(dp[i][j]<=b){
            int v = dp[i][j]-a;
            int x = lower_bound(dp[i]+1, dp[i]+m, v)-(dp[i]+1);
            int y = lb(j, v)-1;
            printf("%d %d\n", x, y);
            cnt += (i-x+1)*(j-y+1)-1;
        }else{
            int vl = dp[i][j]-a;
            int xl = lower_bound(dp[i]+1, dp[i]+m, vl)-(dp[i]+1);
            int yl = lb(j, vl);
            int vu = dp[i][j]-b;
            int xu = lower_bound(dp[i]+1, dp[i]+m, vu)-(dp[i]+1);
            int yu = lb(j, vu);
            cnt += (xu-xl+1)*(yu-yl+1);
        }
    }
    printf("%d\n", cnt);

    return 0;
}
