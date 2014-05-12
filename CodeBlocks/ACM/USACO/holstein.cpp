/*j ID: ahmadad1
PROG: holstein
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vi v;
vvi feeds;

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    int n,m, i,j,k, f, cnt;

    scanf("%d", &n);

    for(i=0; i<n; i++) scanf("%d", &k), v.push_back(k);

    scanf("%d", &m);

    for(i=0; i<m; i++) {
        feeds.push_back(vi());
        for(j=0; j<n; j++) scanf("%d", &k), feeds.back().push_back(k);
    }

    vii res;

    for(int bm=0; bm<(1<<m); bm++){
        vi cur = v;

        cnt=0;
        for(i=0; i<m; i++){
            if(!(bm&(1<<i))) continue;
            cnt++;
            for(j=0; j<n; j++) cur[j]-=feeds[i][j];
        }
        f=1;
        for(j=0; j<n; j++) if(cur[j]>0) { f=0; break; }
        if(f){
            res.push_back(ii(cnt, bm));
        }
    }

    sort(res.begin(), res.end());

    printf("%d", res[0].first);
    for(i=0; i<m; i++){
        if(res[0].second&(1<<i)) printf(" %d", i+1);
    }
    printf("\n");

    return 0;
}
