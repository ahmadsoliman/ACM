#include <string.h>
#include <stdio.h>
#include <math.h>

int main() {
    int t, l;
    double pi=acos(-1);
    while(scanf("%d", &l)>0){
        if(l==0) return 0;
        printf("%.2lf\n", l*l/pi/2.0);
    }
    return 0;
}
