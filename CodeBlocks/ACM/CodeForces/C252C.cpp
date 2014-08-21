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

vector<ii> res;
int n,m;
int vis[500][500];

int recur(int k, int dir, int x, int y, int d){
    if(d==0) return x*m+y * ((dir==0)?-1:1);
    if(!dir && y==m) return recur(k, !dir, x+1, y-1, d);
    if(dir && y==-1) return recur(k, !dir, x+1, 0, d);
    if(vis[x][y]){
        if(!dir) return recur(k, dir, x, y+1, d);
        else return recur(k, dir, x, y-1, d);
    }
    vis[x][y]=1;
    res.push_back(ii(x,y));
    if(!dir) return recur(k, dir, x, y+1, d-1);
    else return recur(k, dir, x, y-1, d-1);
}

int main() {
    int k;
    scanf("%d %d %d", &n, &m, &k);
    int last=0;
    for(int i=0; i<k-1; i++){
        res.clear();
        int dir = last>0;
        if(last<0) last*=-1;
        int x = last/m, y=last%m;
        last = recur(i, dir, x, y, 2);
        printf("%d", res.size());
        for(int j=0; j<res.size(); j++) printf(" %d %d", res[j].first+1, res[j].second+1);
        printf("\n");
    }
    int dir = last>0;
    if(last<0) last*=-1;
    int x = last/m, y=last%m;
    res.clear();
    recur(k-1, dir,x,y, n*m-2*(k-1));
    printf("%d", res.size());
    for(int j=0; j<res.size(); j++) printf(" %d %d", res[j].first+1, res[j].second+1);
    printf("\n");

    return 0;
}
