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
int graph[1010][1010];
int vis[1010], ps[1010];

int maxFlow(){
    int flow=0, cnt=0, u,v, par;
    while(1){
        memset(vis, 0, sizeof vis);
        memset(ps, 0, sizeof ps);
        priority_queue<iii> q;
        q.push(iii(2000000000, ii(0,-1)));
        int maxflow=0;
        while(!q.empty()){
            iii p = q.top(); q.pop();
            u = p.second.first;
            par = p.second.second;
            if(vis[u]) continue;
            vis[u]=1;
            ps[u]=par;
            if(u==n-1){
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
        v = n-1;
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

vector<int> composeWords(vector<string> cubes, vector<string> words){
    vector<int> res;
    for(int i=0; i<words.size(); i++){
        memset(graph, 0, sizeof graph);
        n = 2 + words[i].size() + 7*cubes.size();

        for(int j=0; j<words[i].size(); j++){
            graph[0][1+j]=1;

            for(int k=0; k<cubes.size(); k++){
                graph[1+words[i].size()+6*cubes.size()+k][n-1]=1;
                for(int l=0; l<cubes[k].size(); l++){
                    graph[1+words[i].size()+6*k+l][1+words[i].size()+6*cubes.size()+k]=1;
                    if(words[i][j]==cubes[k][l])
                        graph[1+j][1+words[i].size()+6*k+l]=1;
                }
            }
        }

        int left=0;
        for(int j=0; j<words[i].size(); j++) left+=graph[0][j+1];
        printf("%d\n", left);
        if(left==0) res.push_back(i);
    }
    return res;
}
int main(){}
