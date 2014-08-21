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

vector<double> t;

int main() {
    int n;
    scanf("%d", &n);
    n*=2;

    double v;
    for(int i=0; i<n; i++){
        scanf("%lf", &v);
        t.pb(v-(int)v);
    }
    sort(t.begin(), t.end());



    printf("%.3lf\n", sum);

    return 0;

}
