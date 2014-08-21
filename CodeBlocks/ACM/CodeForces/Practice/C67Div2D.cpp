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
#define INF 4000000000000000000

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

vi nums[55];
int sets[251000];

ll sum[55], prefix[55], suffix[55], maxn[55], maxs[55];

int main() {
    int n, m, l,k;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%d", &l);
        while(l--) scanf("%d", &k), nums[i].pb(k);
    }
    for(int i=0; i<m; i++) scanf("%d", &sets[i]), sets[i]--;


    ll sum2, sum3;
    for(int i=0; i<n; i++){
        sum[i]=sum2=0;
        prefix[i]=suffix[i]=0;
        maxn[i]=-INF;
        maxs[i]=0;
        sum3=0;
        for(int j=0, k=nums[i].size()-1; j<nums[i].size(); j++, k--){
            sum[i]+=nums[i][j];
            sum2+=nums[i][k];
            prefix[i]=max(prefix[i], sum[i]);
            suffix[i]=max(suffix[i], sum2);
            maxn[i]=max(maxn[i], (ll)nums[i][j]);
            sum3+=nums[i][j];
            maxs[i]=max(maxs[i], sum3);
            if(sum3<0) sum3=0;
        }
    }

    ll res=-INF, sum4=0;
    for(int i=0; i<m; i++){
        k = sets[i];

        if(sum4+prefix[k]>0) res = max(res, sum4+prefix[k]);
        sum4 += sum[k];
        if(suffix[k]>0) sum4 = max(sum4, suffix[k]);
        res = max(res, sum4);
        if(sum4<0) sum4=0;

        res = max(res, maxn[k]);
        if(maxs[k]>0) res = max(res, maxs[k]);
    }
    printf("%lld\n", res);

    return 0;

}
/*
3 4
3 -1 -6 -2
2 -3 6
2 -5 -1
1 2 3 1
*/

