#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

ll * tree;
int MaxVal;

long long read(long long idx){
    long long sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(long long idx ,long long val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

vii nums;

int main(){
    int t, i,j, n,m,k, l,r, kase=1;
    ll sum;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        nums.clear();
        for(i=0; i<k; i++){
            scanf("%d %d", &l, &r);
            nums.push_back(ii(l,r));
        }
        sort(nums.begin(), nums.end());
        sum=0;
        MaxVal=max(n,m);
        tree = new ll[MaxVal+1];
        memset(tree, 0, sizeof(long long)*(MaxVal+1));
        for(i=0; i<k; i++){
            update(nums[i].second, 1);
            sum+=read(MaxVal)-read(nums[i].second);
        }
        printf("Test case %d: %lld\n", kase++, sum);
    }
    return 0;
}
