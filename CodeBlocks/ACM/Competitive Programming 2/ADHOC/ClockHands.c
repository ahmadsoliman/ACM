#include <stdio.h>

int main(){
    int h,m;
    double res;
    while(scanf("%d:%d", &h, &m)>0){
        if(h==0&&m==0) return 0;
        res=fabs(((h*60)*0.5)+(m*0.5)-(m*6));

        if(res>180) res=360-res;
        printf("%.3lf\n", res);
    }
    return 0;
}
