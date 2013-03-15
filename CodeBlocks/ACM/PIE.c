#include <stdio.h>
#include <math.h>

#define PI 3.1415926535898
#define INF (2000000000)
#define DBLE 1e-8

int N, F;
double volumes[10005];

double bSearch(double start, double end){
    int i, j, cur, f;
    double mid;
    for(i=0; i<100; i++){
        mid = (start+end)/2.0 + DBLE;
        f = F+1;
        for(j=0; j<N; j++){
            f-=(int)floor((volumes[j]/mid));
        }
        if(f<=0){
            start = mid;
        }else{
            end = mid;
        }
    }
    return mid;
}

int main(){
    int t, r, i;
    double maxV;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &F);
        maxV = 0;
        for(i=0; i<N; i++){
            scanf("%d", &r);
            volumes[i] = PI*r*r;
            if(volumes[i]>maxV)maxV=volumes[i];
        }
        printf("%.4lf\n", bSearch(0.0, maxV));
    }
    return 0;
}
