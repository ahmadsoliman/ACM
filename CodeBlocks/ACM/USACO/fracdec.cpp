/*j ID: ahmadad1
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int vis[200000];

int main() {
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);

    int i,j,k, n,d;

    vi res, ns;

    scanf("%d %d", &n, &d);

    if(n%d==0) { printf("%d.0\n", n/d); return 0; }

    stringstream ss;

    ss << n/d << ".";
    n%=d;

    while(n && !vis[n]++) ns.push_back(n), n*=10, res.push_back(n/d), n%=d;

    for(i=0; i<res.size(); i++) {
        if(n && ns[i]==n) ss << "(";
        ss << res[i];
        if(ss.str().size()==76) printf("%s\n", ss.str().c_str()), ss.str("");
    }
    if(n) ss << ")";
    printf("%s\n", ss.str().c_str());

    return 0;
}
