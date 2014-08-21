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

vector<ii> f[5000];

int main() {
    int n, v,k,u;
    scanf("%d %d", &n, &v);

    int maxd=0;
    for(int i=0; i<n; i++){
        scanf("%d %d", &k, &u);
        f[k].push_back(ii(0,u));
        maxd=max(maxd, k);
    }
    maxd+=2;
    int sum=0;
    for(int i=0; i<maxd; i++) {
        int left=v;
        sort(f[i].rbegin(), f[i].rend());
        for(int j=0; j<f[i].size(); j++){
            if(left>=f[i][j].second){
                sum+=f[i][j].second;
                left-=f[i][j].second;
            }else{
                sum+=left;
                if(f[i][j].first==0) f[i+1].push_back(ii(1, f[i][j].second-left));
                left=0;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
