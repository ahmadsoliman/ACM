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


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int d=n;
    while(n>0 && n>=m){
        int k = n/m;
        d += k;
        n%=m;
        n+=k;
    }
    printf("%d\n", d);

    return 0;

}
