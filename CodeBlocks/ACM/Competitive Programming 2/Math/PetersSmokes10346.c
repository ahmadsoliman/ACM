#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int n,butt, k,i, tot;
    while(scanf("%d %d", &n, &k)>0){
        tot=n;
        while(n>=k) {
            tot+=n/k;
            n=n%k+n/k;
        }
        printf("%d\n", tot);
    }
    return 0;
}
