#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back

vii doc;
vi conDoc;
vvii trees;

vvi g;

double dist(ii p1, ii p2){
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

vi vis;

int dfs(int node){
    if(vis[node]) return 0;
    vis[node]=1;
    if(conDoc[node]) return 1;

    for(int i=0; i<g[node].size(); i++){
        if(dfs(g[node][i])) return 1;
    }
    return 0;
}

int main(){
    int t, n,m,k,d, b, i,j,l,f, x,y, res;
    double dis;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &m, &k, &d);

        doc.clear();
        for(i=0; i<m; i++) {
            scanf("%d %d", &x, &y);
            doc.pb(ii(x,y));
        }

        trees=vvii(n);
        for(i=0; i<n; i++){
            scanf("%d", &b);
            for(j=0; j<b; j++){
                scanf("%d %d", &x, &y);
                trees[i].pb(ii(x,y));
            }
        }
        g=vvi(n);
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                for(l=0; l<trees[i].size(); l++){
                    for(f=0; f<trees[j].size(); f++){
                        dis = dist(trees[i][l], trees[j][f]);
                        if(dis<k || fabs(dis-k)<EPS){
                            g[i].pb(j);
                            g[j].pb(i);
                        }
                    }
                }
            }
        }
        conDoc=vi(n);
        for(i=0; i<n; i++){
            for(l=0; l<trees[i].size(); l++){
                for(j=0; j<m; j++){
                    dis = dist(trees[i][l], doc[j]);
                    if(dis<d || fabs(dis-d)<EPS){
                        conDoc[i]=1;
                        break;
                    }
                }
                if(conDoc[i]) break;
            }
        }
        vis=vi(n);
        res=dfs(0);
        if(res) printf("Tree can be saved :)\n");
        else printf("Tree can't be saved :(\n");
    }
    return 0;
}
