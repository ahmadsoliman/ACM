/*j ID: ahmadad1
PROG: frac1
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vii v;

bool compare(const ii &a, const ii &b){
    if(1.0*a.first/a.second < 1.0*b.first/b.second) return 1;
    return 0;
}

int gcd(int n, int m){
    if(n==0) return m;
    return gcd(m%n, n);
}

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    int n, i,j,k;

    scanf("%d", &n);

    v.push_back(ii(0,1));
    v.push_back(ii(1,1));

    for(i=1; i<n; i++){
        for(j=i+1; j<=n; j++){
            if(gcd(i,j)>1) continue;
            v.push_back(ii(i,j));
        }
    }

    sort(v.begin(), v.end(), compare);

    for(i=0; i<v.size(); i++){
        printf("%d/%d\n", v[i].first, v[i].second);
    }

    return 0;
}
