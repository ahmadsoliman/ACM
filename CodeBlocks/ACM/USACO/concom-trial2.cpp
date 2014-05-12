/*j ID: ahmadad1
PROG: concom
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, per[105][105], vis[105], val[105];

void dfs(int u){
    vis[u]=1;
    for(int i=1; i<=100; i++) val[i]+=per[u][i];
    for(int i=1; i<=100; i++) if(i!=u && !vis[i] && val[i]>50) dfs(i);
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    int i,j,k, trip, u,v,p;

    scanf("%d", &trip);

    n=0;
    memset(per, 0, sizeof per);
    for(i=0; i<trip; i++){
        scanf("%d %d %d", &u, &v, &p);
        per[u][v]=p;
    }

    for(i=1; i<=100; i++){
        memset(vis, 0, sizeof vis);
        memset(val, 0, sizeof val);

        dfs(i);

        for(j=1; j<=100; j++){
            if(i!=j && val[j]>50) printf("%d %d\n", i, j);
        }
    }

    return 0;
}
