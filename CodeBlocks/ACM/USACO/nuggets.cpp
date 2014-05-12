/*j ID: ahmadad1
PROG: nuggets
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
#include <complex>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

int n, nums[15], vis[65536];

void recur(int last){
    if(last>65535) return;
    if(vis[last]) return;
    vis[last]=1;
    for(int i=0; i<n; i++){
        recur(last+nums[i]);
    }
}

int main() {
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);

    int i,j,k;

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &nums[i]);
    sort(nums, nums+n);
    reverse(nums, nums+n);

    recur(0);

    for(i=65535; i>0; i--){
        if(!vis[i]) break;
    }
    if(!vis[65535]) printf("0\n");
    else printf("%d\n", i);

    return 0;
}









