/*j ID: ahmadad1
PROG: hamming
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vi v;

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    int n,b,d, i,j,k, bm, f, cnt;

    scanf("%d %d %d", &n, &b, &d);

    for(bm=0; bm<(1<<b); bm++){
        if(v.size()==n) break;

        f=1;
        for(i=0; i<v.size(); i++){
            cnt=0;
            for(j=0; j<b; j++){
                if((bm&(1<<j))!=(v[i]&(1<<j))) cnt++;
            }
            if(cnt<d) {f=0; break;}
        }
        if(f) v.push_back(bm);
    }

    printf("%d", v[0]);
    for(i=1; i<n; i++) {
        if(i%10==0) printf("\n");
        else printf(" ");
        printf("%d", v[i]);
    }
    if((n-1)%10!=0) printf("\n");

    return 0;
}
