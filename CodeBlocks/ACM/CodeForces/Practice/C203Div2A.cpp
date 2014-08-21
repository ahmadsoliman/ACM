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

int c[200], w[200];

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &c[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d", &w[i]);
    }

    sort(c, c+n);
    sort(w, w+m);

    int v = c[n-1];
    if(2*c[0]>v) v = 2*c[0];

    if(2*c[n-1]>=w[m-1]) printf("-1\n");
    else {
        printf("%d\n", v);
    }

    return 0;

}
