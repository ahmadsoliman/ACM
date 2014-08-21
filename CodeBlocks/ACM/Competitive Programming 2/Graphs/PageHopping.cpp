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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int g[105][105];

int main() {
    int u,v,n,kase=1;

    while(scanf("%d %d", &u, &v)>0){
        if(u==0&&v==0) break;

        for(int i=0; i<100; i++) for(int j=0; j<100; j++) g[i][j]=1000000000;

        g[u-1][v-1]=1;
        while(scanf("%d %d", &u, &v)>0){
            if(u==0&&v==0) break;
            g[u-1][v-1]=1;
        }
        for(int k=0; k<100; k++)
        for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            if(g[i][k]+g[k][j]<g[i][j]) g[i][j]=g[i][k]+g[k][j];

        int sum=0,cnt=0;
        for(int i=0; i<100; i++)
        for(int j=0; j<100; j++){
            if(g[i][j]>=1000000000||i==j) continue;
            sum+=g[i][j];
            cnt++;
        }
        printf("Case %d: average length between pages = %.3lf clicks\n", kase++, (1.0*sum/cnt));

    }

    return 0;

}
