/*j ID: ahmadad1
PROG: stamps
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

static int nums[55], nn;
static short vis[2010005];

void recur(int n, int k){
    if(k==0) return;

    if(vis[n]>=k) return;
    vis[n] = k;

    for(int i=nn-1; i>=0; i--)
        if(vis[n+nums[i]]<k-1)
            recur(n+nums[i], k-1);
}

int main() {
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    int i,j,r,l, k;

    scanf("%d %d", &k, &nn);
    for(i=0; i<nn; i++) scanf("%d", &nums[i]);
    sort(nums, nums+nn);

    memset(vis, -1, sizeof vis);

    recur(0, k+1);

    i=0;
    while(vis[i]>-1) i++;
    printf("%d\n", i-1);

    return 0;
}
