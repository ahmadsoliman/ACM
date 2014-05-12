#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF 1000000000

map<string, int> m;
char n[1000];
vector< vector < string > > d;
vvi g;

vi vis;

#define IMP -1
#define NOT 0
#define STARTED 1
#define DONE 2

int dfs(int u){
    if(vis[u]==IMP) return 0;
    if(vis[u]==STARTED) { vis[u]=IMP; return 0; }
    if(vis[u]==DONE) return 1;
    vis[u]=STARTED;
    for(int i=0; i<g[u].size(); i++){
        if(!dfs(g[u][i])) {vis[u]=IMP; return 0;}
    }
    vis[u]=DONE;
    return 1;
}

int main(){
    int i,j,k, u,v, cur, maxv, pc=0 ,cnt;
    string name;
    while(scanf("%s", n)>0){
        m[string(n)]=pc;
        d.push_back(vector<string>());
        while(scanf("%s", n)>0){
            if(strcmp(n, "0")==0) break;
            name = string(n);
            //if(find(d[pc].begin(), d[pc].end(), name)==d[pc].end())
                d[pc].push_back(name);
        }
        pc++;
    }

    vis = vi(pc, NOT);
    map<string,int>::iterator it;
    g = vvi(pc);
    for(i=0; i<pc; i++){
        for(j=0; j<d[i].size(); j++){
            if((it = m.find(string(d[i][j])))==m.end()) { vis[i]=IMP; continue; }
            //if(find(g[i].begin(), g[i].end(), it->second)!=g[i].end()) continue;
            g[i].push_back(it->second);
        }
    }
    cnt=0;
    for(i=0; i<pc; i++) if(dfs(i)) cnt++;
    printf("%d\n", cnt);
    return 0;
}
/*
a b c b 0
b c 0
c 0
d e f 0
e f 0
f e 0
g h 0
*/
