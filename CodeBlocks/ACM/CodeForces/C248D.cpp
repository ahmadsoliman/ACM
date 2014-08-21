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

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<double> ps;

map<ii, dd> dp;

dd getdp(int i, double cur, bool &found){
    cur *= 1000000000;
    int curi=round(cur);
    map<ii,dd>::iterator it = dp.find(ii(i,curi));
    if(it==dp.end()) {found = false; return dd(-1,-1); }
    found = true;
    return it->second;
}

void savedp(int i, double cur, dd ans){
    cur *= 1000000000;
    int curi=round(cur);
    dp[ii(i,curi)]=ans;
}

dd recur(int i, double cur){
    if(i==ps.size()) return dd(0,1);

    bool f;
    dd ans = getdp(i,cur,f);
    if(f) return ans;

    dd dnttake=recur(i+1, cur), take=recur(i+1, cur*(1-ps[i]));

    take.first += ps[i]*cur*take.second;
    take.second *= (1-ps[i]);

    ans = max(dnttake, take);
    savedp(i,cur,ans);
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    ps = vector<double>(n);
    for(int i=0; i<n; i++){
        scanf("%lf", &ps[i]);
    }
    sort(ps.begin(), ps.end());

    printf("%.9lf\n", recur(0,1).first);

    return 0;

}
