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

int n;
int graph[110][110];
int vis[110], ps[110];

int maxFlow(int src, int sink){
    int flow=0, cnt=0, u,v, par;
    while(1){
        memset(vis, 0, sizeof vis);
        memset(ps, 0, sizeof ps);
        priority_queue<iii> q;
        q.push(iii(2000000000, ii(src,-1)));
        int maxflow=0;
        while(!q.empty()){
            iii p = q.top(); q.pop();
            u = p.second.first;
            par = p.second.second;
            if(vis[u]) continue;
            vis[u]=1;
            ps[u]=par;
            if(u==sink){
                maxflow=p.first;
                break;
            }
            for(int i=0; i<n; i++){
                if(graph[u][i]>0){
                    q.push(iii(min(p.first, graph[u][i]), ii(i, u)));
                }
            }
        }
        if(maxflow==0) break;
        v = sink;
        while(ps[v]!=-1){
            u = ps[v];
            graph[u][v]-=maxflow;
            graph[v][u]+=maxflow;
            v = u;
        }
        cnt++;
        flow+=maxflow;
    }
    return flow;
}

char in[10000], p1[10000], p2[10000];
char appsc[1000];
string comps[1000];
vector<int> appsOfComp[15];

int main(){
    bool done;
    while(gets(in)){
        memset(graph, 0, sizeof graph);
        for(int i=0; i<11; i++) appsOfComp[i].clear();

        int apps = 0;
        done=true;
        do{
            if(string(in)=="") {done=false; break;}
            sscanf(in, "%s %s", p1, p2);

            int cnt = p1[1]-'0';
            while(cnt--) appsc[apps]=p1[0], comps[apps++]=p2;
        }while(gets(in));

        n = 12 + apps;
        for(int i=0; i<apps; i++){
            graph[0][1+i]=1;
            for(int j=0; j<comps[i].size(); j++){
                graph[1+i][1+apps+comps[i][j]-'0']=1;
                appsOfComp[comps[i][j]-'0'].push_back(i);
            }
        }
        for(int i=0; i<10; i++) graph[1+apps+i][n-1]=1;

        int flow = maxFlow(0, n-1);
        if(flow<apps) printf("!\n");
        else{
            for(int i=0; i<10; i++) {
                if(graph[1+apps+i][n-1]) printf("_");
                else{
                    for(int j=0; j<appsOfComp[i].size(); j++){
                        if(graph[1+appsOfComp[i][j]][1+apps+i]==0) printf("%c", appsc[appsOfComp[i][j]]);
                    }
                }
            }
            printf("\n");
        }
        if(done) break;
    }


    return 0;
}



