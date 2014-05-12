#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

string words[100005], p;
char in[300005];

vector<int> tree[100005];

int zfn[100005];

/* P , pattern preprocess */
void kmpPreprocess() {
    int i=0, j=-1;
    zfn[0]=-1;
    while(i<p.size()){
        while(j>=0 && p[i]!=p[j]) j=zfn[j];
        i++; j++;
        zfn[i]=j;
    }
}

long long cnt;

void dfs(int node, int j){
    string cur = words[node];
    int i=0;
    while(i<cur.size()) {
        while(j>=0 && cur[i]!=p[j]) j=zfn[j];
        i++; j++;
        if(j==p.size()) {
            cnt++;
            j=zfn[j];
        }
    }
    for(int i=0; i<tree[node].size(); i++) dfs(tree[node][i], j);
}

int main(){
    int n, par;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d %s", &par, in);
        words[i]=in;
        tree[par-1].push_back(i);
    }

    scanf("%s", in);
    p=in;
    kmpPreprocess();

    words[0]="";
    cnt=0;
    dfs(0, 0);
    printf("%I64d\n", cnt);
    return 0;
}
