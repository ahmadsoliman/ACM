/*j ID: ahmadad1
PROG: humble
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
typedef pair<int, char> ic;
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int np, n, primes[105];

#define MAXV 2147483647

vector<int> cur;

int main() {
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    int i,j,k,r,l;

    scanf("%d %d", &np, &n);

    for(i=0; i<np; i++) scanf("%d", &primes[i]);
    sort(primes, primes+np);

    n++;
    while(n){
        for(i=0; i<np; i++){

        }
    }

    return 0;
}
