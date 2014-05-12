#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define MOD 1000000007

typedef long long ll;

char in[105];
ll n, nums[105], totc, dp[105][55][2000];

ll recur(int i, int even, int sum){
    if(i==n) {
        if(even==0) return sum%11==0;
        return 0;
    }
    if(dp[i][even][sum+1000]!=-1) return dp[i][even][sum+1000];
    return dp[i][even][sum+1000]=
        (((even>0)?recur(i+1, even-1, sum+nums[i]):0)+
        recur(i+1, even, sum-nums[i]))%MOD;
}

long long powmod(long long a, long long b, long long  c){
  long long result = 1;
  long long base = a;
  while (b){
    if (b & 1){
      result = result*base % c;
    }
    b >>= 1;
    base = base*base % c;
  }
  return result;
}

long long modInv(long long n){
    return powmod(n, MOD-2, MOD);
}

ll fact[105], freq[15];

int main(){
    int i,j,k;
    long long ans;
    fact[0]=fact[1]=1;
    for(i=2; i<105; i++) fact[i]=fact[i-1]*i % MOD;

    while(scanf("%s", in)>0){
        n=strlen(in);
        memset(freq, 0, sizeof freq);
        for(i=0; i<n; i++){
            nums[i]=in[i]-'0';
            freq[nums[i]]++;
        }
        memset(dp, -1, sizeof dp);
        ans = ((fact[n/2]*fact[(int)ceil(n/2.0)] % MOD) * recur(0, ceil(n/2.0), 0)) % MOD;
        if(freq[0]>1) ans=ans*modInv(freq[0])%MOD;
        for(i=0; i<10; i++) if(freq[i]>1) ans=ans*modInv(fact[freq[i]])%MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
