/*j ID: ahmadad1
PROG: ratios
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

int g[3], v[3][3];

int main() {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);

    int i,j,r, k;

    for(i=0; i<3; i++) scanf("%d", &g[i]);
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &v[i][j]);
        }
    }
    if(g[0]==0&&g[1]==0&&g[2]==0){
        printf("0 0 0 1\n");
        return 0;
    }
    int sum, m[3], f, cur, mins=1000000, res[4];
    for(i=0; i<101; i++){
        for(j=0; j<101; j++){
            for(k=0; k<101; k++){
                sum=i+j+k;
                if(sum==0) continue;
                f=1;
                for(r=0; r<3; r++){
                    cur=i*v[0][r]+j*v[1][r]+k*v[2][r];
                    if(cur<g[r] || (!g[r] && cur) || (g[r] && cur%g[r]!=0)) {f=0; break;}
                    m[r]=((g[r]!=0)?(cur/g[r]):0);
                }
                if(!f) continue;
                if((m[0]==m[1]||!m[0]||!m[1])&&(m[1]==m[2]||!m[1]||!m[2]) && sum<mins){
                    mins=sum;
                    res[0]=i, res[1]=j, res[2]=k, res[3]=m[0]|m[1]|m[2];
                }
            }
        }
    }
    if(mins==1000000) printf("NONE\n");
    else {
        printf("%d", res[0]);
        for(i=1; i<4; i++) printf(" %d", res[i]);
        printf("\n");
    }

    return 0;
}


