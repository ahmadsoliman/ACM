#include <stdio.h>
#include <string.h>
#include <math.h>

#define abs_val(a) (((a)>=0)?(a):-(a))
typedef long long ll;

ll mulmod(ll a, ll b, ll c) { // returns (a * b) % c, and minimize overflow
  ll x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) x = (x + y) % c;
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }       // standard gcd

ll pollard_rho(ll n) {
    int i = 0, k = 2;
    ll x = 3, y = 3;                // random seed = 3, other values possible
    while (1) {
        i++;
        x = (mulmod(x, x, n) + n - 1) % n;               // generating function
        ll d = gcd(abs_val(y - x), n);                       // the key insight
        if (d != 1 && d != n) return d;         // found one non-trivial factor
        if (i == k) y = x, k *= 2;
    }
}

unsigned long long powmod(long long a, long long b, long long  c){
  unsigned long long result = 1;
  unsigned long long base = a;
  while (b){
    if (b & 1){
      result = mulmod(result, base , c);
    }
    b >>= 1;
    base = mulmod(base, base , c);
  }
  return result;
}

int millerIsPrime(long long n, int itr){
    if(n==2) return 1;
    if(n<2||n%2==0) return 0;
    unsigned long long b,res;
    while(itr--){
        b = rand()%(n-1) + 1;
        res = powmod(b, n, n);
        if(res!=b) return 0;
        res = powmod(b, (n-1)/2, n);
        if(!(res==1||res==n-1)) return 0;
    }
    return 1;
}

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

ll fac[1000], div[100], powp[100];


int main(){
    int t, i,j, cnt;
    ll tmpn, n, factor;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        i=0, tmpn=n;
        while(millerIsPrime(n, 3)==0){
            fac[i]=pollard_rho(n);
            n/=fac[i++];
        }
        fac[i++]=n;
        cnt=i;
        qsort(fac, cnt, sizeof(ll), compare);

        for(i=0, j=0; i<cnt; i++){
            div[j]=fac[i], powp[j]=1;
            while(fac[i]==fac[i+1]) i++, powp[j]++;
            j++;
        }
        cnt=j;
        printf("%lld = ", tmpn);
        for(i=0; i<cnt; i++) {
            printf("%lld", div[i]);
            if(powp[i]>1) printf("^%lld", powp[i]);
            if(i<cnt-1) printf(" * ");
        }
        printf("\n");
    }
    return 0;
}
