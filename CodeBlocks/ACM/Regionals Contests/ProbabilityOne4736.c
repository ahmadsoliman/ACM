#include <stdio.h>
#include <string.h>

int main(){
    int n, i,j, kase=1, even;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        even=0;
        n*=3;
        if(n%2==0) {
            even=1;
            n/=2;
        }else n=(n+1)/2;
        n*=3;
        n/=9;
        if(even) printf("%d. even %d\n", kase++, n);
        else printf("%d. odd %d\n", kase++, n);
    }
    return 0;
}
