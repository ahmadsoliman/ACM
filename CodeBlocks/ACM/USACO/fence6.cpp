/*j ID: ahmadad1
PROG: fence6
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

int lens[105], vis[105];
vector<int> e1[105], e2[105];

int main(){
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);

    int n;
    scanf("%d", &n);

    int m=0, u,v, par;
    int id, len, n1, n2;
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &id, &len, &n1, &n2);
        id--;
        lens[id]=len;

        for(int j=0; j<n1; j++) {
            scanf("%d", &v);
            v--;
            e1[id].push_back(v);
        }
        for(int j=0; j<n2; j++) {
            scanf("%d", &v);
            v--;
            e2[id].push_back(v);
        }
        sort(e1[id].begin(), e1[id].end());
        sort(e2[id].begin(), e2[id].end());
    }

    int minPerim=1000000000;
    for(int i=0; i<n; i++){

        memset(vis, 0, sizeof vis);
        priority_queue<iii, vector<iii>, greater<iii> > q;
        for(int j=0; j<e1[i].size(); j++) q.push(iii(0, ii(e1[i][j],i)));

        int dist=1000000000;
        while(!q.empty()){
            iii p = q.top(); q.pop();
            u = p.second.first;
            par = p.second.second;
            if(vis[u]) continue;
            vis[u]=1;

            if(binary_search(e2[i].begin(), e2[i].end(), u)){
                dist = min(dist, p.first+lens[u]);
            }

            if(binary_search(e1[u].begin(), e1[u].end(), par)){
                for(int j=0; j<e2[u].size(); j++){
                    if(e2[u][j]==i) continue;
                    q.push(iii(p.first+lens[u], ii(e2[u][j], u)));
                }
            }else{
                for(int j=0; j<e1[u].size(); j++){
                    if(e1[u][j]==i) continue;
                    q.push(iii(p.first+lens[u], ii(e1[u][j], u)));
                }
            }
        }
        dist += lens[i];
        minPerim = min(minPerim, dist);
    }

    printf("%d\n", minPerim);

    return 0;
}
