#include <stdio.h>
#include <math.h>

long long gcd(int a, int b, long long* x, long long* y) {
    if (b > a) return gcd(b, a, y, x);
    if (b == 0) {
      *x = 1;
      *y = 0;
      return a;
    }
    long long x1, y1;
    long long r = gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - a / b * y1;
    return r;
}

int main(){
    int t, i, x, k, d, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &x, &k);

        a = floor(1.0*x/k);
        b = ceil(1.0*x/k);
        long long p, q;
        d = gcd(a, b, &p, &q);
        p *= x/d;
        q *= x/d;
        printf("%ld %ld\n", p, q);
    }
    return 0;
}
