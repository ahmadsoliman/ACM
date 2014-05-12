#include <stdio.h>
#include <string.h>
#include <math.h>

long long gcdl(long long m, long long n){
    long long tmp;
    while(m>0){
        tmp = m;
        m = n%m;
        n = tmp;
    }
    return n;
}

long long lcm(int m, int n){
    return m*(n/gcdl(m,n));
}

int main(){
    int t,n,m;
    long long lcm1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        lcm1 = lcm(n,m);
        printf("%lld %lld\n", lcm1/n, lcm1/m);
    }
    return 0;
}
