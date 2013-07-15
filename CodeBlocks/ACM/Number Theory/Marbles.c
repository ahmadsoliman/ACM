#include <stdio.h>
#include <stdlib.h>
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
    int n, A, B, c1, c2, t1, t2;
    long long x1,x2,y1,y2, cost1,cost2;
    while(scanf("%d", &n)>0){
        if(n==0)
            break;
        scanf("%d %d", &c1, &A);
        scanf("%d %d", &c2, &B);
        long long x,y, d;
        d = gcd(A, B, &x, &y);

        if(n%d!=0)
            printf("failed\n");
        else{
            t1 = ceil(-1.0*x/B*n+1e-9);
            x1 = (long long)(x*n/d+1.0*B/d*t1+1e-9);
            y1 = (long long)(y*n/d-1.0*A/d*t1+1e-9);
            cost1 = x1*c1+y1*c2;
            t2 = floor(1.0*y/A*n+1e-9);
            x2 = (long long)(x*n/d+1.0*B/d*t2+1e-9);
            y2 = (long long)(y*n/d-1.0*A/d*t2+1e-9);
            cost2 = x2*c1+y2*c2;

            if(t1>t2)
                printf("failed\n");
            else {
                if(cost1-cost2<=1e-9 && x1>=0 && y1>=0)
                    printf("%ld %ld\n", x1, y1);
                else if(cost1-cost2>=1e-9 && x2>=0 && y2>=0)
                    printf("%ld %ld\n", x2, y2);
                else
                    printf("failed\n");
            }
        }
    }
    return 0;
}
