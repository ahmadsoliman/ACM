#include <stdio.h>
#include <stdlib.h>
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
typedef pair<double,int> di;

#define INF 10000
#define EPS 1e-8

int k, n, c[105], v[105], visdp[250][550][1005];

di dp[250][550][1005];

di recur(int i, int last, int b){
    if(i==k) return dp[i][last][b]=di(0.0, b);
    if(i>k || b==0) return dp[i][last][b]=di(-INF, 0);

    if(visdp[i][last][b]) return dp[i][last][b];

    di cur, maxv(-1, -1);
    for(int j=1; j<=n; j++){
        if(c[j]<=b && j!=last) {
            cur = recur(i+1, j, b-c[j]);
            cur.first += v[j];
            if(cur.first>maxv.first || fabs(cur.first-maxv.first)<EPS) {
                if(fabs(cur.first-maxv.first)<EPS) {
                    if(cur.second > maxv.second) maxv=cur;
                }else maxv=cur;
            }
            if(i<k-1 && 2*c[j]<=b){
                cur = recur(i+2, j, b-2*c[j]);
                cur.first += 1.5*v[j];
                if(cur.first>maxv.first || fabs(cur.first-maxv.first)<EPS) {
                    if(fabs(cur.first-maxv.first)<EPS) {
                        if(cur.second>maxv.second) maxv=cur;
                    }else maxv=cur;
                }
            }
        }
    }
    visdp[i][last][b]=1;
    return dp[i][last][b]=maxv;
}

vi ans;

void reconstruct(int i, int last, int b){
    if(i>=k) return;

    int choice=0, level=0;

    di cur, maxv(-1, -1);
    for(int j=1; j<=n; j++){
        if(c[j]<=b && j!=last) {
            cur = dp[i+1][j][b-c[j]];
            cur.first += v[j];
            if(cur.first>maxv.first || fabs(cur.first-maxv.first)<EPS) {
                if(fabs(cur.first-maxv.first)<EPS) {
                    if(cur.second > maxv.second) { maxv=cur; choice=j; level=0; }
                }else { maxv=cur; choice=j; level=0; }
            }
            if(i<k-1 && 2*c[j]<=b){
                cur = dp[i+2][j][b-2*c[j]];
                cur.first += 1.5*v[j];
                if(cur.first>maxv.first || fabs(cur.first-maxv.first)<EPS) {
                    if(fabs(cur.first-maxv.first)<EPS) {
                        if(cur.second>maxv.second) { maxv=cur; choice=j; level=1; }
                    }else { maxv=cur; choice=j; level=1; }
                }
            }
        }
    }
    ans.push_back(choice);
    if(level==0) reconstruct(i+1, choice, b-c[choice]);
    else { ans.push_back(choice); reconstruct(i+2, choice, b-2*c[choice]); }
}

int main(){
    int m, i,j,l, found, entered=0;
    while(scanf("%d %d %d", &k, &n, &m)>0){
        if(k==0&&n==0&&m==0) return 0;
        if(entered) printf("\n");
        else entered=1;

        for(i=1; i<=n; i++) scanf("%d %d", &c[i], &v[i]);

        memset(visdp, 0, sizeof visdp);
        di tmp(-INF, 0);
        for(l=0; l<=k; l++){
            for(i=0; i<=n; i++)
                for(j=0; j<=m; j++) dp[l][i][j]=tmp;
        }
        recur(0,0,m);

        found=0;
        for(i=0; i<=n; i++){
            for(j=m; j>=0; j--){
                if(fabs(dp[k][i][j].first)<EPS){
                    found=1; break;
                }
            }
            if(found) break;
        }

        if(!found){
            printf("0.0\n");
        }else{
            printf("%.1lf\n", dp[0][0][m]);
            ans.clear();
            reconstruct(0,0,m);
            for(i=0; i<ans.size(); i++) {
                printf("%d", ans[i]);
                if(i<k-1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
