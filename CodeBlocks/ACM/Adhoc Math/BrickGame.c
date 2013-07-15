#include <stdio.h>

int main(){
    int t, i, n, c, kase=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%d", &c);
            if(i==n/2)
                printf("Case %d: %d\n", kase++, c);
        }
    }
    return 0;
}
