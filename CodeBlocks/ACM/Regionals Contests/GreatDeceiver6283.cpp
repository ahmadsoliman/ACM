#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int k;
vi nk;

ll dp[10000][2];

ll recur(int i, int can){
    if(i==nk.size()) {
        return 1;
    }

    if(dp[i][can]!=-1) return dp[i][can];

    if((nk.size()-i)%2==0) {
        return dp[i][can]=recur(i+1, (nk[i]>0)?1:can);
    }

    ll sum=0;
    for(int j=0; j<nk[i]; j++){
        sum+=recur(i+1, 1);
    }
    sum+=recur(i+1, can);
    if(can){
        for(int j=nk[i]+1; j<k; j++){
            sum+=recur(i+1, 1);
        }
    }
    return dp[i][can]=sum;
}

int main(){
    int i,j;
    ll n, tmpn;

    while(scanf("%lld %d", &n, &k)>0){
        tmpn=n;
        nk.clear();
        while(tmpn>0) nk.push_back(tmpn%k), tmpn/=k;
        reverse(nk.begin(), nk.end());

        memset(dp, -1, sizeof dp);
        printf("%lld\n", recur(0, 0));
    }

    return 0;
}
