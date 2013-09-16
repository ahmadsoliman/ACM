#include <stdio.h>

int main(){
    int t, n,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        printf("%d\n", (((n-k)&((k-1)>>1))==0));
    }
    return 0;
}
