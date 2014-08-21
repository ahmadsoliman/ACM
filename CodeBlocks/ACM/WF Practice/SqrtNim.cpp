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

ll firstl[1000100], lastl[1000100];

int main() {

    freopen("nim.in","r",stdin);
    freopen("nim.out", "w", stdout);

    firstl[1] = lastl[1]= 2;
    firstl[2] = 5;
    lastl[2] = 8;

    ll k;

    for(ll i=3; i<1000100; i++){
        firstl[i] = lastl[i-1]+i+1;
        k = floorl(1.0*((i+1)*(i+1)-1-firstl[i])/(i+1));
        lastl[i] = firstl[i]+k*(i+1);
    }

    ll n;
    scanf("%lld", &n);

    ll round = sqrtl(n);
    ll num = n-firstl[round];
    if(num<0 || num%(round+1)!=0) printf("WIN\n");
    else printf("LOSE\n");


    return 0;

}
