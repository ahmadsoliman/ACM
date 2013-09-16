#include <stdio.h>

int main(){
    int h,d,f, i,j, day;
    double u, dropv, curv;
    while(scanf("%d %lf %d %d", &h, &u, &d, &f)>0){
        if(h==0) return 0;
        curv=0;
        day=0;
        dropv=u*f/100.0;
        while(curv>=0){
            day++;
            if(u>0) curv += u;
            if(curv>h) break;
            curv -= d;
            u-=dropv;
        }
        if(curv<0) printf("failure on day %d\n", day);
        else printf("success on day %d\n", day);
    }
    return 0;
}
