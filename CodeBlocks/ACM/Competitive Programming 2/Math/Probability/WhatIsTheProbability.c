#include <stdio.h>
#include <string.h>
#include <math.h>

#define EPS 1e-6

int main(){
    int t, n, i,j;
    double p, prob, pnot, pnotnow, pwin;
    scanf("%d", &t);
    while(t--){
        scanf("%d %lf %d", &n, &p, &i);

        if(p<EPS) printf("%.4lf\n", 0);
        else
            printf("%.4lf\n", p*powf((1-p), i-1)/(1-powf((1-p),n))+EPS);
    }
    return 0;
}
