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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int nums[105];

int gcd(int n, int m){
    if(m==0) return n;
    return gcd(m, n%m);
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }

    int d = nums[0];
    for(int i=1; i<n; i++){
        if(d==1) break;
        d = gcd(d, nums[i]);
    }

    sort(nums, nums+n);
    int left = nums[n-1]/d - n;

    if(left%2==1) printf("Alice\n");
    else printf("Bob\n");

    return 0;

}
