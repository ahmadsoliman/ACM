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

#define pb push_back

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

int n, halfn, dists[25][25];

int countBits(int i){
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int recur(int back, int node, int bm, int half){
    if(back==0){
        if(bm==(1<<n)-1) return dists[node][n-1]+recur(1, n-1, 1|(1<<(n-1)), half);

        int visn=countBits(bm)-2;

        int minv=1000000000;
        for(int i=0; i<n; i++){
            if(!(bm&(1<<i))){
                minv = min(minv, dists[node][i]+recur(back, i, bm|(1<<i), (visn<halfn)?half|(1<<i):half));
            }
        }
        return minv;
    }else{
        if(bm==(1<<n)-1) return dists[node][0];

        int visn=countBits(half);

        int minv=1000000000;
        if(visn>0){
            for(int i=0; i<n; i++){
                if(half&(1<<i)){
                    minv = min(minv, dists[node][i]+recur(back, i, bm|(1<<i), half&(~(1<<i))));
                }
            }
        }else{
            for(int i=0; i<n; i++){
                if(!(bm&(1<<i))){
                    minv = min(minv, dists[node][i]+recur(back, i, bm|(1<<i), 0));
                }
            }
        }
        return minv;
    }
}

int main(){
    int m, kase=1;
    int u,v,w;

    while(scanf("%d %d", &n, &m)>0){
        halfn=(n-2)/2;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) dists[i][j]=1000000000;

        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            dists[u][v]=dists[v][u]=w;
        }

        for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dists[i][j]=min(dists[i][j], dists[i][k]+dists[k][j]);

        printf("Case %d: %d\n", kase++, recur(0, 0, 1|(1<<(n-1)), 0));
    }

    return 0;
}











