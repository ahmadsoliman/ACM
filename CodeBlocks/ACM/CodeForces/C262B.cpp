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

vi res;

int main() {
    int a,b,c, curs;
    scanf("%d%d%d", &a, &b, &c);

    for(int sx=0; sx<82; sx++){
        ll sxa = powl(sx, a);
        ll x = b*sxa+c,tmpx=x;
        if(x<=0 || x>=1e9) continue;
        curs=0;
        while(tmpx>0) curs+=tmpx%10, tmpx/=10;
        if(curs==sx) res.push_back((int)x);
    }

    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    if(res.size()>0){
        printf("%d", res[0]);
        for(int i=1; i<res.size(); i++) printf(" %d", res[i]);
    }


    return 0;

}
