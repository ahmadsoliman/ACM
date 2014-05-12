/*
ID: ahmadad1
PROG: transform
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

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> ii;
typedef pair<vvc, ii> state;

char in[100];

vvc rotate90(vvc g){
    vvc r(g.size(), vc(g.size()));
    for(int i=0; i<g.size(); i++){
        for(int j=0; j<g.size(); j++){
            r[j][g.size()-1-i]=g[i][j];
        }
    }
    return r;
}

vvc reflectHorizontal(vvc g){
    vvc r(g.size(), vc(g.size()));
    for(int i=0; i<g.size(); i++){
        for(int j=0; j<g.size(); j++){
            r[i][j]=g[i][g.size()-1-j];
        }
    }
    return r;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int n, i,j;

    scanf("%d", &n);
    vvc cur(n), dest(n);

    for(i=0; i<n; i++) scanf("%s", in), cur[i]=vc(in, in+n);
    for(i=0; i<n; i++) scanf("%s", in), dest[i]=vc(in, in+n);
/*
cur = rotate90(cur);
cur = rotate90(cur);

for(i=0; i<n; i++){
    for(j=0; j<n; j++) printf("%c", cur[i][j]);
    printf("\n");
}
*/
    queue<state> q;
    q.push(state(cur, ii(0, 6)));

    while(!q.empty()){
        state s = q.front(); q.pop();
        if(s.second.first>=5) break;
        if(s.second.first>0&&s.first==dest) {printf("%d\n", s.second.second); return 0;}

        vvc ns=rotate90(s.first);
        q.push(state(ns, ii(s.second.first+1, ((s.second.first==0)?1:5))));

        ns=rotate90(ns);
        q.push(state(ns, ii(s.second.first+1, ((s.second.first==0)?2:5))));

        ns=rotate90(ns);
        q.push(state(ns, ii(s.second.first+1, ((s.second.first==0)?3:5))));

        ns=reflectHorizontal(s.first);
        q.push(state(ns, ii(s.second.first+1, ((s.second.first==0)?4:5))));
    }
    if(cur==dest) printf("6\n");
    else printf("7\n");

    return 0;
}
/*

*/
