#include <stdio.h>
#include <math.h>

int main(){
    int r, n, i, printed, kase=1;
    while( scanf("%d %d", &r, &n)) {
        if(r==0&&n==0)
            break;

        printed = 0;
        for(i=1; i<=27; i++){
            if (n*i >= r) {
                printf ("Case %d: %d\n", kase++, i - 1);
                printed = 1;
                break;
            }
        }
        if (!printed)
            printf ("Case %d: impossible\n", kase++);
    }
    return 0;
}
