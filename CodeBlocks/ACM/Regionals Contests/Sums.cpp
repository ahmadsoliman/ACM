#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>

typedef long long ll;

using namespace std;

ll dp[10005][3];

vector<int> graph[10005];
vector<int> graphT[10005];
int val[10005], n;

ll recur(int node, int taken){
    if(dp[node][taken]!=-1) return dp[node][taken];

    if(graph[node].size()==0) {
        if(taken) return dp[node][taken]=val[node];
        return dp[node][taken]=max(val[node], 0);
    }
    if(taken){
        int sumTaken=val[node];
        for(int i=0; i<graph[node].size(); i++){
            sumTaken+=recur(graph[node][i], taken);
        }
        return dp[node][taken]=sumTaken;
    }else{
        int sumTaken=val[node], sumNot=0;
        for(int i=0; i<graph[node].size(); i++){
            sumTaken+=recur(graph[node][i], 1);
            sumNot+=recur(graph[node][i], 0);
        }
        return dp[node][taken]=max(sumTaken, sumNot);
    }
}

std::ostringstream res;

void recons(int node, int taken){
    if(graph[node].size()==0) {
        if(taken) res << (node+1) << " ";
        else if(val[node]>0) res << (node+1) << " ";
        return;
    }
    if(taken){
        res << (node+1) << " ";
        for(int i=0; i<graph[node].size(); i++){
            recons(graph[node][i], taken);
        }
    }else{
        int sumTaken=val[node], sumNot=0;
        for(int i=0; i<graph[node].size(); i++){
            sumTaken+=dp[graph[node][i]][1];
            sumNot+=dp[graph[node][i]][0];
        }
        if(sumTaken>sumNot){
            res << (node+1) << " ";
            for(int i=0; i<graph[node].size(); i++){
                recons(graph[node][i], 1);
            }
        }else{
            for(int i=0; i<graph[node].size(); i++){
                recons(graph[node][i], 0);
            }
        }
    }
}

int main(){
    freopen("icecream.in","r",stdin);
    freopen("icecream.out","w",stdout);
    memset(dp, -1, sizeof dp);
    int m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &val[i]);
    int a,b;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        graphT[b-1].push_back(a-1);
    }
    int sum=0;
    for(int i=0; i<n; i++){
        if(graphT[i].size()==0) sum+=recur(i, 0);
    }
    printf("%d\n", sum);
    for(int i=0; i<n; i++){
        if(graphT[i].size()==0) recons(i, 0);
    }
    printf("%s\n", res.str().c_str());
    return 0;
}
