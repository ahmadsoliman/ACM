#include <stdio.h>

int main(){
    int x, y, n, i, j, a, b;
    double minDiff, curDiff, xy, dJ;
    minDiff = 1000000000;
    scanf("%d %d %d", &x, &y, &n);
    xy = 1.0*x/y;
    for(j=1; j<=n; j++){
        dJ = 1.0*j;
        for(i=0; i<=x; i++){
            curDiff = xy-i/dJ;
            if(curDiff<0)curDiff*=-1;
            if(curDiff<minDiff){
                minDiff = curDiff;
                a = i;
                b = j;
            }
        }
    }
    printf("%d/%d", a, b);
    return 0;
}
