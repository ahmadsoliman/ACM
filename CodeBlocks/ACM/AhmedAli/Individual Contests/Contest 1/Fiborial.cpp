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

#define MAXSIEVE 2000010
#define MAXSIEVEHALF 1000005
#define MAXSQRT 1001

static int MOD=1e9+7;

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

void eGCD(long long res[], long long m, long long n){
    if(m==0){
        res[0]=0;res[1]=1;res[2]=n;
        return;
    }
    long long tmp[3];
    eGCD(tmp, n%m, m);
    res[0]=tmp[1]-(n/m)*tmp[0]; res[1]=tmp[0];  res[2]=tmp[2];
}

short a[MAXSIEVEHALF];
int primes[1000000];

int sieve(){
    int i, j, k;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
    return k;
}

set<int> fprimes;
int isPrime[2100100];

int main() {
    memset(a, 0, sizeof a);
    memset(primes, 0, sizeof primes);
    int countp=sieve();

    memset(isPrime, 0, sizeof isPrime);
    for(int i=0; i<countp; i++){
        isPrime[primes[i]]=1;
    }

    int n;
    scanf("%d", &n);
    if(n==1){
        printf("1\n");
        return 0;
    }
    if(n==2){
        printf("2\n");
        return 0;
    }

    ll res=1;
    ll a1=1, a2=1;
    for(int i=2; i<=n; i++){
        if(isPrime[i]) fprimes.insert(i);
        res = (((a1*a2)%MOD)*i)%MOD;
        a1 = a2;
        a2 = res;
    }

    for(set<int>::iterator it=fprimes.begin(); it!=fprimes.end(); it++){
        res = (res*((*it)-1))%MOD;
        res = (res*powmod(*it, MOD-2, MOD))%MOD;
    }

    res = (res+2)%MOD;

    printf("%lld\n", res);

    return 0;

}

