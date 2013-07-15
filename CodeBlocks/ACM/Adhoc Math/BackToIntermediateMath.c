#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int t, kase=1;
    double d,v,u, df,vf2,t1,t2;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf %lf %lf", &d, &v, &u);
        if(v>=u)
            printf("Case %d: can't determine\n", kase++);
        else {
            vf2 = v*v + u*u;
            t1 = d/sqrt(u*u-v*v);
            t2 = d/u;

            if(fabs(t2-t1)<=1e-9)
                printf("Case %d: can't determine\n", kase++);
            else
                printf("Case %d: %.3lf\n", kase++, fabs(t2-t1+1e-9));
        }
    }
    return 0;
}
