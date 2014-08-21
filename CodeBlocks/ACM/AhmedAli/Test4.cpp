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
    int t,n,k,sum,l;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &k);
        sum=0;
        for(int i=0; i<n; i++){
            scanf("%d", &l);
            sum+=l/k;
        }
        printf("%d\n", sum);
    }

    return 0;

}
