#include <stdio.h>

int main(){
    int t, i;
    long long n, m, a, d, c;
    scanf("%d", &t);
    while(t--){
        scanf("%ld %ld %ld %ld", &n, &m, &a, &d);
        c=0;
        for(i=0; i<5; i++){
            c += (m-n+1) - (m/a-n/a);
            a+=d;
        }
        printf("%lld\n", c);
    }
    return 0;
}
