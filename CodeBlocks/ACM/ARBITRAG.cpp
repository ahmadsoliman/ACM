#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

char in[1010];
map< string, int> names;
double g[35][35];

int main(){
    int n, m, i,j,k,l, u,v, res, kase=1;
    double w;

    while(scanf("%d", &n)){
        if(n==0) return 0;
        for(i=0; i<n; i++){
            scanf("%s", in);
            names[string(in)]=i;
            for(j=0; j<n; j++) g[i][j]=-1;
        }
        scanf("%d", &m);
        for(i=0; i<m; i++){
            scanf("%s", in);
            u = names[string(in)];
            scanf("%lf", &w);
            scanf("%s", in);
            v = names[string(in)];
            g[u][v]=w;
        }
        for(k=0; k<n; k++){
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    g[i][j]=max(g[i][j], g[i][k]*g[k][j]);
                }
            }
        }
        res=0;
        for(i=0; i<n; i++){
            if(g[i][i]-1>1e-8) { res=1; break; }
        }
        if(res) printf("Case %d: Yes\n", kase++);
        else printf("Case %d: No\n", kase++);
    }

    return 0;
}
