#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int fam[410], sz[110], took[410];
vector<int> g[410];
pair<int, int> lens[410];

int main(){
    int t, n, m, i, j, s, u, v, len, maxpair;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(i=0; i<n; i++) {
            scanf("%d", &fam[i]);
            g[i].clear();
        }
        for(i=0; i<m; i++) scanf("%d", &sz[i]);
        sort(sz, sz+m);
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                s = fam[i]+fam[j];
                if(binary_search (sz, sz+m, s)){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        for(i=0; i<n; i++) lens[i]=make_pair(g[i].size(), i);
        sort(lens, lens+n);

        memset(took, 0, sizeof took);
        maxpair=0;
        for(i=0; i<n; i++) {
            u=lens[i].second;
            if(!took[u]){
                len=-1;
                for(j=0; j<g[u].size(); j++){
                    if((len==-1 || g[g[u][j]].size()<=len) && !took[g[u][j]]){
                        len = g[g[u][j]].size();
                        v = g[u][j];
                    }
                }
                if(len!=-1){
                    took[u]=took[v]=1;
                    maxpair++;
                }
            }
        }
        printf("%d\n", maxpair);
    }
    return 0;
/*
2
6 4
1 2 3 4 4 5
6 9 3 5
5 4
1 2 3 4 5
6 9 3 5
*/
