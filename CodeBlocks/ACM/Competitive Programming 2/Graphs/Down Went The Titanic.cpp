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
int graph[2100][2100];
int vis[2100], ps[2100];

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

#define inboard(x,y) (x>=0&&y>=0&&x<r&&y<c)

char in[100];
int brd[50][50], iceNum[50][50];

char syms[5]={'*','~','.','@','#'};
const int PERSON=0, WATER=1, ICE=2, BERG=3, WOOD=4, dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

int main(){
    int r,c,p,icen;

    while(scanf("%d %d %d", &r, &c, &p)>0){
        icen=0;
        for(int i=0; i<r; i++){
            scanf("%s", in);
            for(int j=0; j<c; j++)
            for(int k=0; k<5; k++)
                if(in[j]==syms[k]) {
                    brd[i][j]=k;
                    if(brd[i][j]==ICE){
                        iceNum[i][j]=icen++;
                    }
                    break;
                }
        }

        memset(graph, 0, sizeof graph);
        n = 2 + r*c + 2*icen;

        // src = 0, sink=n-1

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int u = 1+i*c+j;

                if(brd[i][j]==WATER) continue;
                if(brd[i][j]==PERSON) graph[0][u]=1;
                if(brd[i][j]==WOOD) graph[u][n-1]=p;
                if(brd[i][j]==ICE) graph[1+c*r+2*iceNum[i][j]][1+c*r+2*iceNum[i][j]+1]=1, u=1+c*r+2*iceNum[i][j]+1;

                for(int k=0; k<4; k++){
                    int x=i+dx[k], y=j+dy[k];
                    if(!inboard(x,y)) continue;
                    if(brd[x][y]==WATER||brd[x][y]==PERSON) continue;

                    int v = 1+x*c+y;
                    if(brd[x][y]==ICE) v = 1+c*r+2*iceNum[x][y];
                    graph[u][v]=1000000000;
                }
            }
        }
        printf("%d\n", maxFlow(0,n-1));
    }

    return 0;
}
