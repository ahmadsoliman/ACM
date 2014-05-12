#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <string>

using namespace std;

#define INF 1000000000

int n;

char in[100], in2[100];

map<string, int> nti;
map<string, int>::iterator it;

vector<int> graph[205], roots;
int hasp[205], bribe[205], sizes[205];

int dfs(int node){
    sizes[node] = 1;
    for (int i=0;i<graph[node].size();i++)
        sizes[node]+=dfs(graph[node][i]);
    return sizes[node];
}

int mind(int i, int m);

int recur2(int i, int j, int m){
    if(m<=0) return 0;
    if(j==graph[i].size()) return INF;

    int ind=graph[i][j], minv=INF, cur;
    for(int k=0; k<=sizes[ind]; k++){
        cur = mind(ind, k)+recur2(i, j+1, m-k);
        minv=min(minv, cur);
    }
    return minv;
}

int mind(int i, int m){
    if(m<=0) return 0;
    return min(bribe[i], recur2(i, 0, m));
}

int recur(int i, int m){
    if(m<=0) return 0;
    if(i==roots.size()) return INF;

    int ind=roots[i], minv=INF, cur;
    for(int j=0; j<=sizes[ind]; j++){
        cur = mind(ind, j)+recur(i+1, m-j);
        minv=min(minv, cur);
    }
    return minv;
}

int main(){
    int i,j,k, m, ind, u, v;
    while(1){
        gets(in2);
        if(in2[0]=='#') return 0;
        sscanf(in2, "%d %d", &n, &m);
        ind=0;
        memset(hasp, 0, sizeof hasp);
        for(i=0; i<n; i++) graph[i].clear();
        nti.clear();

        for(i=0; i<n; i++){
            gets(in);
printf("a7a0");
            char *p=strtok(in, " ");

printf("a7a1");
            if((it=nti.find(p))==nti.end()) u=ind, nti.insert(make_pair(p, ind++));
            u = it->second;
printf("a7a2");
            p=strtok(NULL, " ");
            sscanf(p, "%d", &bribe[u]);
printf("a7a3");
            p=strtok(NULL, " ");
            while(p!=NULL){
                if((it=nti.find(p))==nti.end()) v=ind, nti.insert(make_pair(p, ind++));
                v = it->second;
                graph[u].push_back(v);
                hasp[v]=1;
                p=strtok(NULL, " ");
            }
        }
        roots.clear();
        for (i=0;i<n;i++){
            if (!hasp[i]){
                dfs(i);
                roots.push_back(i);
            }
        }
        printf("%d\n", recur(0, m));
    }
    return 0;
}
/*
3 2
Aland 10
Boland 20 Aland
Coland 15
#
*/
