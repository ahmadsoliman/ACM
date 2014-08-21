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

int nums[3010], vis[3010], nodeCnt[3010], fp, n;
vector<int> graph[3010];

vector<int> cycleNodes[3010];

int cycles;

void dfs(int node){
    if(vis[node]) return;
    vis[node]=cycles;
    nodeCnt[cycles]++;
    cycleNodes[cycles].push_back(node);
    for(int i=0; i<graph[node].size(); i++) dfs(graph[node][i]);
}

void newCycles(){
    for(int i=0; i<n; i++) graph[i].clear(), cycleNodes[i].clear();
    for(int i=0; i<n; i++) {
        graph[i].push_back(nums[i]);
    }

    memset(vis, 0, sizeof vis);
    memset(nodeCnt, 0, sizeof nodeCnt);
    cycles=1;
    for(int i=0; i<n; i++) if(!vis[i]) dfs(i), cycles++;


    fp=0;
    for(int i=1; i<cycles; i++) fp+=nodeCnt[i]-1, sort(cycleNodes[i].begin(), cycleNodes[i].end());
}

vii res;

int main() {
    int m;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        nums[i]--;
    }
    scanf("%d", &m);

    newCycles();

    if(fp==m){
    }else if(fp<m){
        while(m-fp>0){
            for(int i=0; i<n && m-fp>0; i++){
                int v=-1;
                for(int j=0; j<n; j++) if(vis[j]!=vis[i]) {v=j; break;}
                if(v!=-1){
                    res.push_back(ii(nums[i], nums[v]));
                    if(res.back().first>res.back().second) swap(res.back().first, res.back().second);
                    swap(nums[i],nums[v]);
                }else break;

                newCycles();
            }
        }
    }else{
        while(fp-m>0){
            for(int i=0; i<n && fp-m>0; i++){
                if(nodeCnt[vis[i]]>1){
                    int v=-1;
                    for(int j=0; j<n; j++) if(vis[j]==vis[i] && j!=i) {v=j; break;}
                    if(v!=-1){
                        res.push_back(ii(nums[i], nums[v]));
                        if(res.back().first>res.back().second) swap(res.back().first, res.back().second);
                        swap(nums[i],nums[v]);
                    }else break;
                }
                newCycles();
            }
        }
    }
    printf("%d\n", res.size());
    if(res.size()){
        printf("%d %d", res[0].first+1, res[0].second+1);
        for(int i=1; i<res.size(); i++) printf(" %d %d", res[i].first+1, res[i].second+1);
        printf("\n");
    }

    return 0;
}
