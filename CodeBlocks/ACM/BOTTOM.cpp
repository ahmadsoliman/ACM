#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[5005], graphT[5005];
vector<int> bottom;
int vis[5005];
int order[5005];
int component[5005];
int lastSCC[5005];
int componentIdx ;
int orderIdx ;

void dfs1(int v){
    vis [v] = 1;
    int i;
    for(i=0; i<graph[v].size(); i++){
        if(!vis[graph[v][i]])
            dfs1(graph[v][i]);
    }
    order[orderIdx++] = v ;
}

void dfs2(int v){
    component[v] = componentIdx;
    int i;
    for(i=0; i<graphT[v].size(); i++){
        if(component[graphT[v][i]] == -1)
            dfs2(graphT[v][i]);
        else if(component[graphT[v][i]] != componentIdx)
            lastSCC[component[graphT[v][i]]] = 1;
    }
}

int main(){
    int v, e, i, j, t1, t2;
    while(1){
        scanf("%d", &v);
        if(v==0)break;
        scanf("%d", &e);

        for(i=0; i<v; i++){
            graph[i].clear();
            graphT[i].clear();
        }
        for(i=0; i<e; i++){
            scanf("%d %d", &t1, &t2);
            graph[t1-1].push_back(t2-1);
            graphT[t2-1].push_back(t1-1);
        }

        //first dfs
        memset(vis, 0, sizeof vis);
        memset(order, 0, sizeof order);
        orderIdx = 0;
        for(i=0; i<v; i++){
            if(!vis[i])
                dfs1(i);
        }

        memset(lastSCC, 0, sizeof lastSCC);
        memset(component, -1, sizeof component);
        componentIdx = -1;
        bottom.clear();

        //second DFS
        for(i= orderIdx-1; i>= 0; i--){
            if(component[order[i]]==-1){
                componentIdx++;
                dfs2(order[i]);
            }
        }
        for(i=0; i<=componentIdx; i++){
            if(lastSCC[i]==0){
                for(j=0; j<v; j++){
                    if(component[j]==i)
                        bottom.push_back(j);
                }
            }
        }

        sort(bottom.begin(), bottom.end());
        for(i=0; i<bottom.size(); i++){
            printf("%d", bottom[i]+1);
            if(i<bottom.size()-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
