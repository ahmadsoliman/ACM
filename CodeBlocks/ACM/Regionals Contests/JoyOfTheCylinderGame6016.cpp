#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 100000000

int n,m,k, grid[1005][1005], dp[1005][1005];

int recur(int i, int j){
    if(i==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int cur, maxv=-INF, dist;
    for(int l=0; l<m; l++){
        dist = 1 + min(abs(j-l), m-abs(j-j));
        if(dist<=k){
            cur = grid[i][j]+recur(i+1, l);
            if(cur>maxv) {
                maxv=cur;
            }
        }
    }
    return dp[i][j]=maxv;
}

vi ans;
void recons(int i, int j){
    if(i==n) return;
    int cur, maxv=-INF, dist,p=-1;
    for(int l=0; l<m; l++){
        dist = 1 + min(abs(j-l), m-abs(j-j));
        if(dist<=k){
            cur = grid[i][j]+dp[i+1][l];
            if(cur>maxv) {
                maxv=cur;
                p=l;
            }
        }
    }
    ans.push_back(p);
    recons(i+1, p);
}

int main(){
    int t, i,j, cur, maxv, maxi;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                scanf("%d", &grid[i][j]);
            }
        }
        memset(dp, -1, sizeof dp);
        ans.clear();
        maxv=-INF;
        for(i=0; i<m; i++){
            cur = recur(0, i);
            if(cur>maxv) { maxv=cur; maxi=i; }
        }
        ans.push_back(maxi);
        recons(0, maxi);
        printf("%d", maxv);
        for(i=0; i<n; i++) printf(" %d", ans[i]+1);
        printf("\n");
    }
    return 0;
}
