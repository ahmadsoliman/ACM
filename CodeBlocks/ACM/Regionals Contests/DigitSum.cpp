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


vi v;

ll recur(int i, ll x, ll y, int z){
    if(i==v.size()) {
        if(z) return min(recur(i, x*10, y, z-1), recur(i, x, y*10, z-1));
        if(x==0||y==0) return 1000000000000000000ll;
        return x+y;
    }
    ll minv = min(recur(i+1, x*10+v[i], y, z), recur(i+1, x, y*10+v[i], z));
    if(z){
        if(x>0) minv = min(minv, recur(i, x*10, y, z-1));
        if(y>0) minv = min(minv, recur(i, x, y*10, z-1));
    }
    return minv;
}

int main() {
    int n,x,z;

    while(scanf("%d", &n)){
        if(n==0) break;

        z=0;
        v.clear();
        for(int i=0; i<n; i++){
            scanf("%d", &x);
            if(x==0) z++;
            else v.pb(x);
        }
        sort(v.begin(), v.end());
        printf("%lld\n", recur(0,0,0,z));
    }

    return 0;

}
//24860101
