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

char in[1000];
vector<int> nums;

int main(){
    int t,n,k, sum;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        nums= vi(n);
        sum=0;
        for(int i=0; i<n; i++){
            scanf("%d", &k);
            nums[i]=k;
            sum+=k;
        }
        sort(nums.begin(), nums.end());
        int avg = sum/n;
        int r1 = sum%n, r2=0;
        for(int i=0; i<n && nums[i]<avg; i++) r2+=avg-nums[i];
        printf("%d %d\n", r1, r2);
    }

    return 0;
}





