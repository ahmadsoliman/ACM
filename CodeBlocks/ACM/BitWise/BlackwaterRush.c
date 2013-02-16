#include <stdio.h>
#include <math.h>

int main(){
    int t,i, x0, y0, N;
    double x1, x2, len, tmp1 ,tmp2;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        len = 0.0;
        for(i=0; i<N; i++){
            scanf("%d %d", &x0, &y0);
            x1 = x0 + 4*sqrt(y0);
            x2 = x0 - 4*sqrt(y0);
            tmp1 = x2-x1;
            tmp2 = ((x2*x2-x1*x1)/2.0 + x0*(x1-x2));
            len += ((tmp1>=0)?tmp1:-1*tmp1)-(1.0/8)*((tmp2>=0)?tmp2:-1*tmp2);
        }
        printf("%lf", len);
    }
    return 0;
}

