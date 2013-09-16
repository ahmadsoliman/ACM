#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

#define min(x,y) (((x)<(y))?(x):(y))

char s1[55], s2[55];
int n, n1, n2, dp[55][55], vis[55][55], kase;

int recur(int i, int j){
    if(i==n1&&j==n2)
        return 0;
    if(i==n1)
        return n2-j;
    if(j==n2)
        return n1-i;
    if(vis[i][j]==kase)
        return dp[i][j];
    vis[i][j]=kase;
    if(s1[i]==s2[j]){
        int a=recur(i+1,j+1),b=1+recur(i+1, j),c=1+recur(i,j+1);
        return dp[i][j] = min(a,min(b,c));
    }else{
        int a=recur(i+1, j),b=recur(i,j+1), c=recur(i+1,j+1);
        return dp[i][j] = 1+min(a,min(b,c));
    }
}

int mat[505][505];
vi g[505];
char words[505][55];

int main(){
    kase=1;
    int i,j,k, edist, res, cur;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;

        for(i=0; i<n; i++) {
            scanf("%s", words[i]);
            g[i].clear();
        }

        memset(mat, 0, sizeof mat);
        for(i=0; i<n; i++){
            strcpy(s1, words[i]);
            n1=strlen(s1);
            for(j=i+1; j<n; j++){
                strcpy(s2, words[j]);
                n2=strlen(s2);
                edist=recur(0,0);
                if(edist==1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                    mat[i][j]=1;
                    mat[j][i]=1;
                }
                kase++;
            }
        }
        kase++;

        res=0;
        for(i=0; i<n; i++){
            map<int, int> dist;
            dist[i]=0;

            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(k=0; k<g[u].size(); k++){
                    if(!dist.count(g[u][k])){
                        dist[g[u][k]] = dist[u]+1;
                        q.push(g[u][k]);
                    }
                }
            }

            for(j=0; j<n; j++){
                cur = dist[j];
                if(dist.count(j) && cur>res) res=cur;
            }
        }

        printf("%d\n", res+1);
    }
    return 0;
}
/*
cot sat scat cat

4
cat
cot
scat
sat


3
ahmad
ahmed
zizo
3
ahmad
ahmed
zizo
*/

