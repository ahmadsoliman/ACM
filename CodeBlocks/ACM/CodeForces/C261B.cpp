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

ll nCk[201000][3];

int a[200010];
vi v;
map<int, int> m;

int main() {
    memset(nCk, 0, sizeof nCk);
    for(int i=1; i<1010; i++){
        for(int j=0; j<3; j++){
            if(j==0||j==i) {nCk[i][j]=1; continue;}
            nCk[i][j] = nCk[i-1][j-1] + nCk[i-1][j];
        }
    }

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);

    int maxd=a[n-1]-a[0];

    for(int i=0; i<n; i++){
        if(m.find(a[i])==m.end()) v.push_back(a[i]), m[a[i]]=1;
        else m[a[i]]++;
    }

    ll noways;
    if(maxd==0) noways = nCk[m[v[0]]][2];
    else noways = (ll)m[v[0]]*m[v[0]+maxd];

    printf("%d %I64d\n", maxd, noways);

    return 0;

}
