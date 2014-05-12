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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vii ops;
int target;

int recur(int i, int left){
    if(left==0) return 0;
    if(i==ops.size()) return 1000000000;
    int a, b=ops[i].second+recur(i+1, left-1);
    //if(ops[i].first==target) a=recur(i+1, left+1);
    //else
        a=recur(i+1, left);
    return min(a,b);
}

int main() {
    int n,k,i,j, p,e;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d %d", &p, &e);
        ops.push_back(ii(p,e));
    }
    sort(ops.rbegin(), ops.rend());
    if(k==n+1){
        printf("0\n");
        return 0;
    }
    if(ops[k-1].first>n){
        printf("-1\n");
        return 0;
    }
    target=ops[k-1].first;
    printf("%d\n", recur(0, ops[k-1].first));
    return 0;
}
