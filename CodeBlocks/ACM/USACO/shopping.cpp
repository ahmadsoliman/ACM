/*j ID: ahmadad1
PROG: shopping
LANG: C++
*/
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
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

struct offer{
    int p;
    vi code, cnt;
};

offer offers[105];
int n,s, cnt[10], code[10], p[10];

map<int, int> cti;

map<vi, int> dp;

int recur(vi left){
    for(int i=0; i<n; i++){
        if(left[i]>0) break;
        if(i==n-1) return 0;
    }

    if(dp.find(left)!=dp.end()) return dp[left];

    int minv=1000000000;
    for(int i=0; i<n; i++){
        for(int j=1; j<=left[i]; j++) {
            left[i]-=j;
            minv=min(minv, p[i]*j+recur(left));
            left[i]+=j;
        }
    }

    for(int i=0; i<s; i++){
        int f=1;
        for(int j=0; j<offers[i].code.size(); j++){
            if(cti.find(offers[i].code[j])==cti.end() || left[cti[offers[i].code[j]]]<offers[i].cnt[j]) {f=0; break;}
        }
        if(!f) continue;
        vi left2=left;
        for(int j=0; j<offers[i].code.size(); j++){
            left2[cti[offers[i].code[j]]]-=offers[i].cnt[j];
        }
        minv = min(minv, offers[i].p+recur(left2));
    }
    return dp[left]=minv;
}

int main() {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);

    int i,j,k;

    scanf("%d", &s);
    for(i=0; i<s; i++){
        scanf("%d", &k);
        offers[i].code=vi(k);
        offers[i].cnt=vi(k);
        for(j=0; j<k; j++) scanf("%d %d", &offers[i].code[j], &offers[i].cnt[j]);
        scanf("%d", &offers[i].p);
    }
    vi cnt2;
    scanf("%d", &n);
    for(i=0; i<n; i++) {

        scanf("%d %d %d", &code[i], &cnt[i], &p[i]);
        cnt2.push_back(cnt[i]);
        cti.insert(make_pair(code[i],i));
    }
    if(cnt2.size()==0) printf("0\n");
    else printf("%d\n", recur(cnt2));


    return 0;
}





