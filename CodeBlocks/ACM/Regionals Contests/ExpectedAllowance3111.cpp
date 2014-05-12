#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > dp;

int main(){
    int n,m,k, i,j,l,s, mn;
    double res;

    while(scanf("%d %d %d", &n, &m, &k)>0){
        if(n==0 && m==0 && k==0) return 0;

        dp = vector<vector<int> >(n*m+2, vector<int>(n+2));

        dp[0][0]=1;
        for(i=1; i<=n*m; i++){
            for(j=1; j<=n; j++){
                dp[i][j]=0;
                for(s=1; s<=m; s++){
                    if(i<s) break;
                    dp[i][j]+=dp[i-s][j-1];
                }
            }
        }
        res=0;
        mn = pow(m, n);
        for(i=1; i<=n*m; i++){
            s=max(1, i-k);
            res+=(1.0*dp[i][n]/mn)*s;
        }
        printf("%.8lf\n", res);
    }
    return 0;
}
