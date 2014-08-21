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

ll nums[100005];

int main() {
    int n;
    scanf("%d", &n);

    ll sum=0, maxv=0;
    for(int i=0; i<n; i++){
        scanf("%lld", &nums[i]);
        sum+=nums[i];
        maxv=max(maxv,nums[i]);
    }
    printf("%lld\n", max(maxv,(ll)ceil(1.0*sum/(n-1))));

    return 0;

}
