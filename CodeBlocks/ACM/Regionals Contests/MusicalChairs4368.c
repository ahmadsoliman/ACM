#include <stdio.h>

int main(){
    int n, d, i, res;
    while(scanf("%d %d", &n, &d)>0){
        if(n==0&&d==0) return 0;
        res=0;
        for(i=1; i<=n; i++) res=(res+d)%i;
        printf("%d %d %d\n", n, d, res+1);
    }
    return 0;
}
