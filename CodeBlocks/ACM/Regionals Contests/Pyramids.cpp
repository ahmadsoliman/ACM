#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

#define INF 1000000000

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

int dp[1000020], sumHigh[200], sumLow[200];

int recur(int c){
    if(c==0) return dp[c]=0;
    //if(c<sumHigh[2]&&c<sumLow[3]) return INF;
    if(dp[c]!=-1) return dp[c];

    int minv=INF;
    for(int i=181; i>1; i--){
        if(sumHigh[i]<=c) minv = min(minv, 1+recur(c-sumHigh[i]));
        if(i>2 && sumLow[i]<=c) minv = min(minv, 1+recur(c-sumLow[i]));
    }
    return dp[c]=minv;
}

char tmp[100];
vector<iii> sums;
string finans;

void recons(int c, int i, int res, string ans){
    if(c==0) {
        if(finans.size()) return;
        finans=ans;
    }
    for(; i<sums.size(); i++){
        if(c>=sums[i].first && dp[c-sums[i].first]<=res){
            sprintf(tmp, " %d%c", sums[i].second.first, (sums[i].second.second)?'H':'L');
            recons(c-sums[i].first, i+1, res-1, ans+tmp);
            if(finans.size()) return;
        }
    }
}

int main(){
    sumHigh[0]=0;
    sumLow[0]=0;
    sumHigh[1]=1;
    sumLow[1]=1;
    for(int i=2; i<182; i++){
        sumHigh[i]=sumHigh[i-1]+i*i;
        sumLow[i]=sumLow[i-2]+i*i;
        sums.pb(iii(sumHigh[i], ii(i, 1)));
        if(i>2) sums.pb(iii(sumLow[i], ii(i, 0)));
    }
    sort(sums.rbegin(), sums.rend());
    memset(dp, -1, sizeof dp);
    int c, kase=1;
    while(scanf("%d", &c)){
        if(!c) break;
        int res = recur(c);
        if(c>=INF) printf("Case %d: impossible\n", kase++);
        else {
            printf("Case %d:", kase++);
            finans="";

            while(finans.size()==0 && res<8)
                recons(c, 0, res-1, ""), res++;

            if(finans.size()) printf("%s\n", finans.c_str());
            else printf(" impossible\n");
        }
    }
    return 0;
}
