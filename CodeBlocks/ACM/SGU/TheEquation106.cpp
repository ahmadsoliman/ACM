#include <stdio.h>
#include <math.h>

typedef long long ll;

int main(){
    ll a,b,c, x1, x2, y1, y2;

    scanf("%lld %lld %lld", &a, &b, &c);
    scanf("%lld %lld", &x1, &x2);
    scanf("%lld %lld", &y1, &y2);

    ll sy1=floor(1.0*(-1*c-a*x1)/b), sy2=floor(1.0*(-1*c-a*x2)/b);

    if(sy1>sy2) {
        ll tmp=sy1;
        sy1=sy2;
        sy2=tmp;
    }

    if(y1>sy1) sy1=y1;
    if(y2<sy2) sy2=y2;

    ll range=sy2-sy1+1;

    range /= b;

    printf("%lld\n", range);

    return 0;
}
