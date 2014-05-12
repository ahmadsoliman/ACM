#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF 1000000000
#define inboard(x,y) ((x)>=0&&(x)<b.size()&&(y)>=0&&(y)<=b[0].size())

int ways, dx1[8]={1,-1,1,-1,-1,1,0,0}, dy1[8]={0,0,1,-1,1,-1,1,-1},
    dx2[8]={2,-2,2,-2,-2,2,0,0}, dy2[8]={0,0,2,-2,2,-2,2,-2};

map<pair<vvi, int> , int> dp;
map<pair<vvi, int> , int>::iterator it;

int recur(vvi b, int m){
    if(m==0){
        int c=0;
        for(int i=0; i<b.size(); i++) for(int j=0; j<b[0].size(); j++) c+=b[i][j];
        if(c==1) return 1;
        return 0;
    }
    pair<vvi, int> state=make_pair(b, m);
    if((it=dp.find(state))!=dp.end()) return it->second;
    vvi tmp;
    int c=0;
    for(int i=0; i<b.size(); i++) for(int j=0; j<b[0].size(); j++){
        if(b[i][j]==1){
            for(int k=0; k<8; k++){
                if(inboard(i+dx1[k], j+dy1[k]) && b[i+dx1[k]][j+dy1[k]]==1 &&
                   inboard(i+dx2[k], j+dy2[k]) && b[i+dx2[k]][j+dy2[k]]==0){
                        tmp=b;
                        tmp[i][j]=0;
                        tmp[i+dx1[k]][j+dy1[k]]=0;
                        tmp[i+dx2[k]][j+dy2[k]]=1;
                        c+=recur(tmp, m-1);
                   }
            }
        }
    }
    return dp[state]=c;
}

int main(){
    int kase=1, t, R,C, i,j,k, n, x,y;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &R, &C, &n);
        vvi b(R, vi(C));
        for(i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            b[x-1][y-1]=1;
        }
        ways=0; dp.clear();
        printf("Case %d: %d\n", kase++, recur(b, n-1));
    }
    return 0;
}

