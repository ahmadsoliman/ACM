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

int graph[100][100], vis[100], cycles;
bool cyclic;
char in[100];

void dfs(int node, int par, int e){
//    printf("%d %d\n", node, par);
    if(vis[node]==cycles && !e) { cyclic=true; return; }
    if(vis[node]) return;
    vis[node]=cycles;
    if(e) {
        for(int i=0; i<52; i++)
            if(graph[node][i])
                dfs(i, node, !e);
    } else{
        if(node%2==0) dfs(node+1, node, !e);
        else dfs(node-1, node, !e);
    }
}

int main(){
    int n;
    while(scanf("%d", &n)>0){
        memset(graph, 0, sizeof graph);
        for(int i=0; i<n; i++){
            scanf("%s", in);
            for(int j=0; j<8; j+=2){
                if(in[j]=='0') continue;
                for(int k=0; k<8; k+=2){
                    if(in[k]=='0' || j==k) continue;
//                    printf("%d %d\n", 2*(in[j]-'A')+((in[j+1]=='+')?0:1),2*(in[k]-'A')+((in[k+1]=='+')?0:1));
                    graph[2*(in[j]-'A')+((in[j+1]=='+')?0:1)][2*(in[k]-'A')+((in[k+1]=='+')?0:1)]=1;
                    graph[2*(in[k]-'A')+((in[k+1]=='+')?0:1)][2*(in[j]-'A')+((in[j+1]=='+')?0:1)]=1;
                }
            }
        }
        memset(vis, 0, sizeof vis);
        cyclic=false;
        cycles=1;
        for(int i=0; !cyclic && i<52; i++){
            if(vis[i]==0) { dfs(i, -1, 0), cycles++; }
        }
        if(cyclic) printf("unbounded\n");
        else printf("bounded\n");
    }
    return 0;
}

/*
3
A+00A+A+ 00B+D+A- B-C+00C+
1
K+K-Q+Q-
1
K+K-K+K+
*/
