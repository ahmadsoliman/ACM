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
#define INF 1000000000

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

int nums[550], m, dp[550];

vector<int> sets[550];
bool canEnd[550][550];

/*
8
1 2 3 2 5 1 3 4

6
1 2 6 3 5 4
1 2 6 3 4

*/

int calc(int x, int y){
    int cnt=sets[x].size()-1, side;

    vi cur=sets[x++];
    while(x<=y){
        cnt+=sets[x].size()-1;
        side=(cur[0]>sets[x][0]);
        for(int i=0,j=0; i<cur.size()||j<sets[x].size(); ){
            if(i==cur.size()) {
                if(!side) cnt++;
                break;
            }
            if(i==cur.size()) {
                if(side) cnt++;
                break;
            }
            if(cur[i]<sets[x][j]){
                i++;
                if(side) cnt++;
                side = 0;
            }else{
                j++;
                if(!side) cnt++;
                side = 1;
            }
        }
        cur.insert(cur.end(), sets[x].begin(), sets[x].end());
        sort(cur.begin(), cur.end());
        x++;
    }
    return cnt;
}

int recur(int i){
    if(i==m) return 0;
    if(dp[i]!=-1) return dp[i];
    int minv=INF;
    for(int j=i; j<m; j++){
        if(canEnd[i][j]) minv=min(minv, calc(i,j)+recur(j+1));
    }
    return dp[i]=minv;
}

set<int> tmp;

int main() {
    int n, maxv;

    while(scanf("%d", &n)>0){

        for(int i=0; i<n; i++){
            scanf("%d", &nums[i]);
            sets[i].clear();
        }
        m=0;
        for(int i=0; i<n; i++){
            if(sets[m].empty() || sets[m].back()<nums[i]) sets[m].pb(nums[i]);
            else sets[++m].pb(nums[i]);
        }
        m++;

        bool flag;
        memset(canEnd, false, sizeof canEnd);
        for(int i=0; i<m; i++){
            tmp.clear();
            flag=true;
            maxv=sets[i].back();
            for(int j=i; j<m; j++){
                for(int k=0; k<sets[j].size(); k++){
                    if(tmp.find(sets[j][k])==tmp.end()) tmp.insert(sets[j][k]);
                    else{
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
                maxv = max(maxv, sets[j].back());
                if(maxv==tmp.size()) canEnd[i][j]=1;
            }
        }
        memset(dp, -1, sizeof dp);
//        printf("%d\n", calc(0, 2));
        int res = recur(0);
        if(res>=INF) printf("impossible\n");
        else printf("%d\n", res);
    }

    return 0;

}
