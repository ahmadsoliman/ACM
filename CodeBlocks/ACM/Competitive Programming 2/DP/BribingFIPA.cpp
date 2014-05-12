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

char in[1000000], in2[1000000];

map<string, int> nti;
map<string, int>::iterator it;

vector<int> graph[205], roots;
int hasp[205], bribe[205], sizes[205];
int dp1[205][205], dp2[205][205], dp3[205][205][205];

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

    if(dp3[i][j][m]!=-1) return dp3[i][j][m];

    for(int k=0; k<=sizes[ind]; k++){
        cur = mind(ind, k)+recur2(i, j+1, m-k);
        minv=min(minv, cur);
    }
    return dp3[i][j][m]=minv;
}

int mind(int i, int m){
    if(m<=0) return dp2[i][m]=0;
    if(dp2[i][m]!=-1) return dp2[i][m];
    dp2[i][m]=INF;
    return dp2[i][m]=min(bribe[i], recur2(i, 0, m));
}

int recur(int i, int m){
    if(m<=0) return 0;
    if(i==roots.size()) return INF;

    if(dp1[i][m]!=-1) return dp1[i][m];

    int ind=roots[i], minv=INF, cur;

    for(int j=0; j<=sizes[ind]; j++){
        cur = mind(ind, j)+recur(i+1, m-j);
        minv=min(minv, cur);
    }
    return dp1[i][m]=minv;
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

        char * p;
        for(i=0; i<n; i++){
            gets(in);
            p=strtok(in, " ");
            if((it=nti.find(p))==nti.end()) u=ind, nti.insert(make_pair(p, ind++));
            else u = it->second;

            p=strtok(NULL, " ");
            sscanf(p, "%d", &bribe[u]);

            p=strtok(NULL, " ");
            while(p!=NULL){
                if((it=nti.find(p))==nti.end()) v=ind, nti.insert(make_pair(p, ind++));
                else v = it->second;
                graph[u].push_back(v);
                hasp[v]=1;
                p=strtok(NULL, " ");
            }
        }

        roots.clear();
        for (i=0;i<n;i++){
            if (hasp[i]==0){
                dfs(i);
                roots.push_back(i);
            }
        }

        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);

        memset(dp3, -1, sizeof dp3);
        for(i=0; i<n; i++) {
            for(j=0; j<=sizes[i]; j++) mind(i, j);//, printf("%d ", dp2[i][j]);
            //printf("\n");
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

10 6
A 200 B C D
B 10 E F
C 20 G
D 100 H I J
E 50
F 40
G 30
H 5
I 5
J 5

*/
