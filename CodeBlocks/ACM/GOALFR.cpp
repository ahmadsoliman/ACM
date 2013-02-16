#include <stdio.h>
#include <math.h>

#define EPS 1e-8

int main(){
    int t;
    double goalUpX=52.5,goalUpY=3.66, goalDownX=52.5, goalDownY=-3.66;
    double ballX, ballY, Xr, Yr, r, m, cLine, a , b , c, inter;
    scanf("%d", &t);
    while(t--){
        scanf("%lf", &ballX);
        scanf("%lf", &ballY);
        scanf("%lf", &Xr);
        scanf("%lf", &Yr);
        scanf("%lf", &r);

        m = (goalUpY-ballY)/(goalUpX-ballX);
        cLine = ballY-m*ballX;
        a = m*m+1;
        b = 2*m*(cLine-Yr) - 2*Xr;
        c = (cLine-Yr)*(cLine-Yr) + Xr*Xr - r*r;
        inter = pow((b/(2*a)), 2) - c/a;
        if(inter+EPS<0){
            printf("Goal!\n");
            continue;
        }

        m = (goalDownY-ballY)/(goalDownX-ballX);
        cLine = ballY-m*ballX;
        a = m*m+1;
        b = 2*m*(cLine-Yr) - 2*Xr;
        c = (cLine-Yr)*(cLine-Yr) + Xr*Xr - r*r;
        inter = pow((b/(2*a)), 2) - c/a;
        if(inter+EPS<0){
            printf("Goal!\n");
        }else{
            printf("No goal...\n");
        }
    }
}
