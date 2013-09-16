#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int main(){
    int cal, a,b,c,i;
    double amin,amax,bmin,bmax,cmin,cmax, mincal, maxcal;
    while(scanf("%d%d%d%d", &cal, &a,&b,&c)>0){
        if(cal==0&&a==0&&b==0&&c==0) return 0;

        amin=(a>0)?a-0.5:0; amax=a+0.5;
        bmin=(b>0)?b-0.5:0; bmax=b+0.5;
        cmin=(c>0)?c-0.5:0; cmax=c+0.5;

        mincal=amin*9+bmin*4+cmin*4;
        maxcal=amax*9+bmax*4+cmax*4;

        if((cal>mincal || fabs(cal-mincal)<=EPS) && cal+EPS<maxcal) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
