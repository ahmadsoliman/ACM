/*j ID: ahmadad1
PROG: fence9
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
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

int main() {
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);

    int i,j,k;
    int n,m,p, b;

    scanf("%d %d %d", &n, &m, &p);

    double a=0.5*p*m;
    long double y ;

    b=p+2;

    if(n>0)
        for(i=1; i<n; i++) {
            y = ((long double)m/n)*i;
            if(fabs(y-floor(y))<1e-9) b++;
        }
    else b+=m-1;

    if(n<p){
        for(i=n+1; i<p; i++){
            y = ((long double)m/(n-p))*(i-p);
            if(fabs(y-floor(y))<1e-9) b++;
        }
    }else if(n>p){
        for(i=p+1; i<n; i++){
            y = ((long double)m/(n-p))*(i-p);
            if(fabs(y-floor(y))<1e-9) b++;
        }
    } else b+=m-1;

    printf("%lld\n", (long long)(a-b/2.0+1));

    return 0;
}





