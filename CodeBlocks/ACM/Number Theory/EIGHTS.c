#include <stdio.h>

int main(){
    int t;
    long long n;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", 192+250*(n-1));
    }
    return 0;
}
