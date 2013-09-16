#include <stdio.h>

int main(){
    int t, n;
    unsigned long long c, k1, k2, k3;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        n--;
        k1 = n/3;   k2 = n/5;   k3 = n/15;
        c = 3*k1*(k1+1)/2 + 5*k2*(k2+1)/2 - 15*k3*(k3+1)/2 ;
        printf("%llu\n", c);
    }
    return 0;
}
