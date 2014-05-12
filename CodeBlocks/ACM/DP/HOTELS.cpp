#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> arr;
vector<ll>::iterator it;

int main(){
    int i,j,k, n;
    ll M, cur, maxv;
    scanf("%d %lld", &n, &M);
    arr=vector<ll>(n, 0);
    scanf("%d", &arr[0]);
    for(i=1; i<n; i++) scanf("%d", &arr[i]), arr[i]+=arr[i-1];

    maxv=0;
    for(i=0; i<n; i++){
        if(arr[i]<=M) maxv=max(maxv, arr[i]);
        else {
            cur=arr[i]-M;
            it = lower_bound(arr.begin(), arr.end(), cur);
            cur=arr[i]-*it;
            maxv=max(maxv, cur);
        }
    }
    printf("%lld\n", maxv);
    return 0;
}
