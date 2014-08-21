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
vector<ii> graph[60005];
int vis[60005], ps[60005];

int getw(int u, int v){
    for(int i=0; i<graph[u].size(); i++) if(graph[u][i].first==v) return graph[u][i].second;
    return 0;
}

void updatew(int u, int v, int w){
    for(int i=0; i<graph[u].size(); i++)
        if(graph[u][i].first==v) { graph[u][i].second=w; return; }
    graph[u].push_back(ii(v,w));
}

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
            for(int i=0; i<graph[u].size(); i++){
                if(graph[u][i].second>0){
                    q.push(iii(min(p.first, graph[u][i].second), ii(graph[u][i].first, u)));
                }
            }
        }
        if(maxflow==0) break;
        v = sink;
        while(ps[v]!=-1){
            u = ps[v];
            int uv = getw(u,v), vu = getw(v,u);
            updatew(u,v,uv-maxflow);
            updatew(v,u,vu+maxflow);
            v = u;
        }
        cnt++;
        flow+=maxflow;
    }
    return flow;
}

int mv[105], ms[105], me[105];
int times[60000];

int main(){
    int kase=1, sum;
    int nm, m, maxt;
    while(scanf("%d", &nm)){
        if(nm==0) break;
        scanf("%d", &m);

        vector<ii> ranges;

        sum=0;
        maxt=0;
        for(int i=0; i<nm; i++) {
            scanf("%d %d %d", &mv[i], &ms[i], &me[i]);
            maxt = max(maxt, me[i]);
            sum+=mv[i];
            ranges.push_back(ii(ms[i], me[i]));
        }
        maxt++;

        sort(ranges.begin(), ranges.end());

        vector<vector<int> > tmp;
        vector<int> tmp2;
        tmp2.push_back(ranges[0].first);
        tmp2.push_back(ranges[0].second);
        tmp.push_back(tmp2);
        tmp2.clear();
        tmp2.push_back(ranges[0].second);
        for(int i=1; i<ranges.size(); i++){
            if(ranges[i].first>=tmp2.back()) { tmp.push_back(vector<int>()); tmp2.push_back(ranges[i].second); }
            tmp.back().push_back(ranges[i].first);
            tmp.back().push_back(ranges[i].second);
            tmp2.back()=max(tmp2.back(), ranges[i].second);
        }
        ranges.clear();
        for(int i=0; i<tmp.size(); i++){
            sort(tmp[i].begin(), tmp[i].end());
            for(int j=0; j<tmp[i].size()-1; j++){
                if(tmp[i][j]==tmp[i][j+1]) continue;
                ranges.push_back(ii(tmp[i][j], tmp[i][j+1]));
            }
        }
//        ranges.back().second++;
//        printf("%d\n", tmp.size());
//        for(int i=0; i<ranges.size(); i++) printf("%d %d\n", ranges[i].first, ranges[i].second);

        n = 2 + ranges.size() + nm;

        for(int i=0; i<n; i++) graph[i].clear();
        for(int i=0; i<ranges.size(); i++) graph[0].push_back(ii(1+i,m*(ranges[i].second-ranges[i].first)));

        for(int i=0; i<nm; i++) {
            graph[1+ranges.size()+i].push_back(ii(n-1,mv[i]));
            for(int j=0; j<ranges.size(); j++){
                if(ranges[j].first>=ms[i] && ranges[j].second<=me[i]){
//                    printf("%d %d : %d %d %d\n", i, j, ranges[j].first, ranges[j].second, ranges[j].second - ranges[j].first);
                    graph[1+j].push_back(ii(1+ranges.size()+i, ranges[j].second-ranges[j].first));
                }
            }
        }

        memset(times, 0, sizeof times);
        int flow = maxFlow(0,n-1);
//        printf("%d\n", flow);
        if(flow<sum) printf("Case %d: No\n", kase++);
        else{
            printf("Case %d: Yes\n", kase++);
            for(int i=0; i<nm; i++){
                vector<ii> tmp;
                for(int j=0; j<ranges.size(); j++){
                    if(ranges[j].first>=ms[i] && ranges[j].second<=me[i]){
                        int w = ranges[j].second-ranges[j].first-getw(1+j, 1+ranges.size()+i);
//                        printf("%d %d : %d %d\n", i, w, ranges[j].first, ranges[j].second);
                        if(w>0){
                            int start = ranges[j].first;
                            while(times[start]>=m) start++;

                            for(int k=start; k<start+w; k++) times[k]++;

                            if(tmp.empty() || tmp.back().second<start) tmp.push_back(ii(start, start+w));
                            else tmp.back().second = start+w;
                        }
                    }
                }

                printf("%d", tmp.size());
                for(int j=0; j<tmp.size(); j++) printf(" (%d,%d)", tmp[j].first, tmp[j].second);
                printf("\n");
            }
        }
    }
    return 0;
}
