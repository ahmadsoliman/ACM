#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;
#define MOD 1234567891

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

int nCk[350][350];

void initnCk(){
    int i, j;
    for(i=0; i<330; i++) nCk[i][i]=1;
    for(i=0; i<330; i++) nCk[i][0]=1;
    for(i=1; i<330; i++){
        for(j=1; j<i; j++){
            nCk[i][j]=((ll)nCk[i-1][j]+nCk[i-1][j-1])%MOD;
        }
    }
}

int barn[350];
typedef pair<int, int> frac;
void initBarnoulli(){
    int i,j;
    barn[0]=1;
    for(i=1; i<330; i++){

    }
}

/*
1
123456789 321
*/
int main(){
    int t, n,k, i,j;
    long long s, tmp;

    initnCk();


    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        s=0;
        for(i=1; i<=n; i++){
            //tmp = (n-i+1)*powmod(i, k)%MOD;
            s += tmp;
            if(s>MOD) s-=MOD;
        }
        printf("%d\n", s);
    }
    return 0;
}
