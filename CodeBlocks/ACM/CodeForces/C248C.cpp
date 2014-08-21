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
typedef vector<iii> viii;
typedef vector<vii> vvii;

char in[100];

char colors[5]={'R','G','B','Y','W'};

vi cntC[10], cntT[10];

vii nums;

vector<int> gc[105],gt[105];

int vis[105];

void dfs(int node){
    if(vis[node]) return;
    vis[node]=1;
    for(int i=0; i<gc[node].size(); i++) dfs(gc[node][i]);
}

void dfs2(int node){
    if(vis[node]) return;
    vis[node]=1;
    for(int i=0; i<gt[node].size(); i++) dfs(gt[node][i]);
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", in);
        int clr;
        for(int j=0; j<5; j++) if(colors[j]==in[0]) clr=j;
        cntC[clr].push_back(i);
        cntT[in[1]-'1'].push_back(i);
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<cntC[i].size(); j++){
            for(int k=j+1; k<cntC[i].size(); k++){
                gc[cntC[i][j]].push_back(cntC[i][k]);
                gc[cntC[i][k]].push_back(cntC[i][j]);
            }
        }
        for(int j=0; j<cntT[i].size(); j++){
            for(int k=j+1; k<cntT[i].size(); k++){
                gt[cntT[i][j]].push_back(cntT[i][k]);
                gt[cntT[i][k]].push_back(cntT[i][j]);
            }
        }
    }
    int maxv=0;
    memset(vis, 0, sizeof vis);
    int cnt=0;
    for(int i=0; i<n; i++) if(!vis[i]) dfs(i), cnt++;
    maxv=max(maxv,cnt);

    memset(vis, 0, sizeof vis);
    cnt=0;
    for(int i=0; i<n; i++) if(!vis[i]) dfs2(i), cnt++;
    maxv=max(maxv,cnt);

    printf("%d\n", maxv-1);


    return 0;

}
