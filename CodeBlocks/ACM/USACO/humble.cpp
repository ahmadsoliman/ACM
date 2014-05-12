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

#define MAXV 2000000000


static int i,j,k, maxe;
static long long e;
static int np, n, primes[105];
static priority_queue<int, vi, greater<int> > pq;

int main() {
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    scanf("%d %d", &np, &n);

    for(i=0; i<np; i++) scanf("%d", &primes[i]);
    sort(primes, primes+np);

    n++;
    pq.push(1);
    while(!pq.empty()){
        int cur = pq.top(); pq.pop();

        n--;
        if(n==0){
            printf("%d\n", cur);
            return 0;
        }
        j=0;
        for(i=0; i<np; i++) if(cur%primes[i]==0) j=i;

        for(i=j; i<np; i++){
            e = (long long)cur*primes[i];
            if(e>MAXV) break;
            if(pq.size()>n && e>maxe) break;
            maxe = max(maxe, (int)e);
            pq.push(e);
        }
    }

    return 0;
}
