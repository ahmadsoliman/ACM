#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <bitset>
#include <algorithm>

#define EPS 1e-9

using namespace std;

typedef pair<int, int> ii;

int c(long long x, long long n){
    int pow=0;
    while(x>=n) x/=n, pow++;
    return pow;
}

int nums[4]={2,3,5,7};

vector<long long> ans;

long long calc(long long n){
    int i,j,k,l;
    int power[4];
    for(i=0; i<4; i++) power[i]=c(n, nums[i]);
    long long sum=0, lev1=1, lev2=1, lev3=1, lev4=1;

    for(i=0; i<=power[0]; i++){
        lev2=lev1;
        for(j=0; j<=power[1]; j++){
            lev3=lev2;
            if(lev2>n) break;
            for(k=0; k<=power[2]; k++){
                lev4=lev3;
                if(lev3>n) break;
                for(l=0; l<=power[3]; l++){
                    if(lev4<=n) ans.push_back(lev4);
                    else break;
                    lev4*=7;
                }
                lev3*=5;
            }
            lev2*=3;
        }
        lev1*=2;
    }

    return sum;
}

int main() {
    int t, i,j,k;
    long long n, sum;
    calc(pow(10, 18));
    sort(ans.begin(), ans.end());
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", ans[n-1]);
    }
    return 0;
}
