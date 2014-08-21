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

char in[200],n;

int dp[105][105];

int recur(int i, int last){
    if(i==n) return dp[i][last+1]=0;
    if(dp[i][last+1]!=-1) return dp[i][last+1];
    if(last==-1) return dp[i][last+1]=max(recur(i+1, last), 1+recur(i+1, i));
    if(in[i]>=in[last]) return dp[i][last+1]=max(recur(i+1, last), 1+recur(i+1, i));
    return dp[i][last+1]=recur(i+1, last);
}

vector<string> res;

void recons(int i, int last, string cur){
    if(i==n) {
        res.pb(cur);
        return;
    }
    int leave=dp[i+1][last+1], take=-1;
    if(last==-1 || in[i]>=in[last]) take=1+dp[i+1][i+1];
    if(leave==take) {
        recons(i+1, last, cur);
        recons(i+1, i, cur+in[i]);
    }else if(leave>take) recons(i+1, last, cur);
    else recons(i+1, i, cur+in[i]);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", in);
        n=strlen(in);
        memset(dp, -1, sizeof dp);
        recur(0,-1);
        res.clear();
        recons(0,-1,"");
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++){
            printf("%s\n", res[i].c_str());
        }
        printf("\n");
    }
    return 0;

}
