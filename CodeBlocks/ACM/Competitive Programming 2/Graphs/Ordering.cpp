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
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char in[10000], in2[5];

int graph[25][25];
map<char, int> cti;
map<int, char> itc;
int n, par[25];

vector<int> sol;
int cnt=0;

void recur(int node, int bm){
    if(bm == (1<<n)-1){
        cnt++;
        printf("%c", itc[sol[0]]);
        for(int i=1; i<sol.size(); i++){
            printf(" %c", itc[sol[i]]);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<n; i++){
        if(!(bm&(1<<i))){
            bool doable=true;
            for(int j=0; j<n && doable; j++) if(bm&(1<<j)) doable &= !graph[i][j];
            if(!doable) continue;
            sol.push_back(i);
            recur(i, bm|(1<<i));
            sol.pop_back();
        }
    }
}

int vis[25], rounds;
int checkCycle(int node){
    if(vis[node]==rounds) return 1;
    if(vis[node]) return 0;
    vis[node]=rounds;
    for(int i=0; i<n; i++) if(graph[node][i] && checkCycle(i)) return 1;
    return 0;
}

vector<char> vars;

int main(){
    int t;
    sscanf(gets(in), "%d", &t);

    while(t--){
        memset(par, 0, sizeof par);
        memset(graph, 0, sizeof graph);
        cti.clear();
        itc.clear();
        vars.clear();
        n=0;

        gets(in);
        while(string(in)=="") gets(in);
        char* p = strtok(in, " ");
        while(p!=NULL){
            sscanf(p, "%s", in2);
            vars.push_back(in2[0]);
            p = strtok(NULL, " ");
        }
        sort(vars.begin(), vars.end());
        for(int i=0; i<vars.size(); i++) {
            itc[n]=vars[i];
            cti[vars[i]]=n++;
        }

        gets(in);
        while(string(in)=="") gets(in);
        p = strtok(in, " ");
        while(p!=NULL){
            sscanf(p, "%s", in2);
            graph[cti[in2[0]]][cti[in2[2]]]=1;
            par[cti[in2[2]]]=1;
            p = strtok(NULL, " ");
        }

        memset(vis, 0, sizeof vis);
        rounds=1;
        bool cyclic=false;
        for(int i=0; i<n && !cyclic; i++) if(vis[i]==0) cyclic|=checkCycle(i), rounds++;
        if(cyclic){
            printf("NO\n");
            if(t)
                printf("\n");
            continue;
        }

        for(int i=0; i<n; i++) {
            sol.clear();
            sol.push_back(i);
            if(!par[i]) recur(i, (1<<i));
        }
        if(cnt==0) printf("NO\n");
        if(t)
            printf("\n");
    }

    return 0;
}
