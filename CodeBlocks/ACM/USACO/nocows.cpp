/*j ID: ahmadad1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

int dp[205][105];
bool vis[205][105];

int recur(int n, int k){
    if(n==1 || k==1) return n==1&&k==1;

    if(vis[n][k]) return dp[n][k];

    long long sum=0;
    int rest=n-1;

    for(int i=1; i<rest; i+=2){
        sum += recur(i, k-1)*recur(rest-i, k-1);

        for(int j=1; j<k-1; j++){
            sum += recur(i, j)*recur(rest-i, k-1);
            sum += recur(i, k-1)*recur(rest-i, j);
        }
    }
    vis[n][k]=1;
    return dp[n][k]=sum%9901;
}

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    int i,j, n,k;

    scanf("%d %d", &n, &k);
    printf("%d\n", recur(n, k));

    return 0;
}
