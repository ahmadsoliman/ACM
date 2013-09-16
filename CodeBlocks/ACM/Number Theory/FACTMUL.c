#include <stdio.h>
#include <string.h>
#include <math.h>

int n, n2, flag, i,j, k;
static const long long MOD=109546051211ll;
long long res, fib, x,b,c, y;

int main(){
    int n;
    scanf("%d", &n);
    if(n>=587117) { printf("0\n"); return 0; }
    if(n==1){ printf("1\n"); return 0; }

    res=1ll, fib=1ll, flag=n&1, n=(n>>1)+((flag)?1:0);
    for(i=2, j=2; i<=n; i++){
        c=(fib*j)%MOD;
        j++;
        fib=(c*j)%MOD;
        j++;

        x=0; y=res; b=c;
        while(b){
            if(b&1) x += y;
            if(x>=MOD) x-=MOD;
            y <<= 1;
            if(y>=MOD) y-=MOD;
            b >>= 1;
        }
        res = x;

        x=0; y=res; b=fib;
        while(b){
            if(b&1) x += y;
            if(x>=MOD) x-=MOD;
            y <<= 1;
            if(y>=MOD) y-=MOD;
            b >>= 1;
        }
        res = x;
    }
    if(!flag){
        fib=(fib*j)%MOD;
        x=0; y=res; b=fib;
        while(b){
            if(b&1) x += y;
            if(x>=MOD) x-=MOD;
            y <<= 1;
            if(y>=MOD) y-=MOD;
            b >>= 1;
        }
        res = x;
    }
    printf("%lld", res);
    return 0;
}
