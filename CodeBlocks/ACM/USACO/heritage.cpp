/*j ID: ahmadad1
PROG: heritage
LANG: C++
*/
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
typedef long long ll;

char in[100], pre[100];
int n;
int vis[100];

vi tree[100];

void recur(int node, string in, string pre){
    if(in.size()==0 || node>=n || n<0) return;

    //printf("%d %s %s\n", node, in.c_str(), pre.c_str());

    int r;
    for(r=0; r<in.size(); r++) if(in[r]==pre[0]) break;

    string leftin="", leftpre="", rightin="", rightpre="";

    for(int i=0; i<r; i++) leftin+=in[i], leftpre+=pre[i+1];
    if(leftin.size()) {
        tree[node].push_back(node+1);
        recur(node+1, leftin, leftpre);
    }

    for(int i=r+1; i<in.size(); i++) rightin+=in[i], rightpre+=pre[i];
    if(rightin.size()) {
        tree[node].push_back(node+leftin.size()+1);
        recur(node+leftin.size()+1, rightin, rightpre);
    }
}

void post(int cur){
    if(vis[cur]) return;
    vis[cur]=1;
    if(cur<0 || cur>=n) return;
    for(int i=0; i<tree[cur].size(); i++) post(tree[cur][i]);
    printf("%c", pre[cur]);
}

int main() {
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);

    int i,j,k;

    scanf("%s", in);
    scanf("%s", pre);

    n=strlen(in);
    memset(vis, 0 , sizeof vis);

    recur(0, in, pre);

    for(i=0; i<n; i++){
        //reverse(tree[i].begin(), tree[i].end());

        /*printf("%d: ", i);
        for(j=0; j<tree[i].size(); j++) printf("%d ", tree[i][j]);
        printf("\n");*/
    }

    memset(vis, 0 , sizeof vis);
    post(0);
    printf("\n");

    return 0;
}





