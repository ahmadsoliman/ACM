#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

#define MOD 1000000003

long long powmod(long long a, long long b){
  long long result = 1;
  long long base = a;
  while (b){
    if (b & 1){
      result = result*base % MOD;
    }
    b >>= 1;
    base = base*base % MOD;
  }
  return result;
}

long long mod(long long n){
    n%=MOD;
    if(n<0) n+=MOD;
    return n;
}

//Extended Euclidean Algorithm
void eGCD(long long res[], long long m, long long n){
    if(m==0){
        res[0]=0;res[1]=1;res[2]=n;
        return ;
    }
    long long tmp[3];
    eGCD(tmp, n%m, m);
    res[0]=tmp[1]-(n/m)*tmp[0];res[1]=tmp[0];res[2]=tmp[2];
}

long long inv(long long n){
    long long r[3];
    eGCD(r, n, MOD);
    return mod(r[0]);
}

long long S3(int n){
    return inv(4)*(powmod(n, 4)%MOD+2*powmod(n, 3)%MOD+powmod(n, 2)%MOD)%MOD ;
}

long long S4(int n){
    return inv(30)*mod(6*powmod(n, 5)%MOD+15*powmod(n, 4)%MOD+10*powmod(n, 3)%MOD-n%MOD)%MOD;
}

int main(){
    int t, n,k, i,j;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", mod((ll)(n+1)*S3(n)%MOD-S4(n)));
    }
    return 0;
}
