#include <stdio.h>

int main(){
    int t, n, k, p, r, kase=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &k, &p);
        r = (k+p)%n;
        printf("Case %d: %d\n", kase++, (r==0)?n:r);
    }
    return 0;
}
