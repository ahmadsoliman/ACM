#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int t, i,j,k, kase=1;
    double D, sa, sb, sf, xa,xb,xf, da,db,df, time, res=0;
    scanf("%d", &t);
    while(t--){
        scanf("%d %lf %lf %lf %lf", &k, &D, &sa, &sb, &sf);

        res=0;
        xa=0, xb=D, xf=0;

        while(xa<xb){
            D=xb-xf;

            db=D*sb/(sf+sb);
            df=D-db;
            time=df/sf;
            xb -= db;
            res+=xb-xf;
            xf = xb;
            xa += sa*time;

            D=xf-xa;
            if(D<0 || fabs(D)<1e-9) break;

            da=D*sa/(sf+sa);
            df=D-da;
            time=df/sf;
            xa += da;
            res+=xf-xa;
            xf = xa;
            xb -= sb*time;
        }
        printf("%d %.2lf\n", kase++, res);

    }
    return 0;
}
