#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef vector<int> vi;

map<vi, int> vii;
map<vi, int>::iterator it;

vi graph[100000];

int vis[100000];

int dfs(int node, int end){
    if(node==end) return 1;
    if(vis[node]) return 0;
    vis[node]=1;
    for(int i=0; i<graph[node].size(); i++) if(dfs(graph[node][i], end)) return 1;
    return 0;
}

int main(){
    int i,j,k, n, start,end, ind, p,q, kase=1;
    vi v;

    while(scanf("%d", &n)>0){
        if(n==0) return 0;

        for(i=0; i<10000; i++) graph[i].clear();
        vii.clear();
        ind=0;

        v.clear();
        for(i=0; i<n; i++){
            scanf("%d", &k);
            v.push_back(k);
        }
        it = vii.find(v);
        if(it==vii.end()) start=ind, vii.insert(make_pair(v, ind++));
        else start=it->second;

        v.clear();
        for(i=0; i<n; i++){
            scanf("%d", &k);
            v.push_back(k);
        }
        it = vii.find(v);
        if(it==vii.end()) end=ind, vii.insert(make_pair(v, ind++));
        else end=it->second;

        while(scanf("%d", &k)>0){
            if(k==-1) break;

            v.clear();
            v.push_back(k);
            for(i=1; i<n; i++){
                scanf("%d", &k);
                v.push_back(k);
            }
            it = vii.find(v);
            if(it==vii.end()) p=ind, vii.insert(make_pair(v, ind++));
            else p=it->second;

            v.clear();
            for(i=0; i<n; i++){
                scanf("%d", &k);
                v.push_back(k);
            }
            it = vii.find(v);
            if(it==vii.end()) q=ind, vii.insert(make_pair(v, ind++));
            else q=it->second;

            graph[p].push_back(q);
            graph[q].push_back(p);
        }

        memset(vis, 0, sizeof vis);
        if(dfs(start, end)) printf("Maze #%d can be travelled\n", kase++);
        else printf("Maze #%d cannot be travelled\n", kase++);
    }
    return 0;
}
