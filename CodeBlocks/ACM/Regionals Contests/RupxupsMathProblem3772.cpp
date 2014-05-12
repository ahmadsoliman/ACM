#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;

int c(int n, int d){
    return n/d;
}

int main(){
    int t, n, i,j,k, sqrtn;
    ll sum;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        sqrtn=ceil(sqrt(n));
        sum=n+n-1;
        for(i=2; i<=sqrtn; i++){
            sum+=c(n, i)-1;
            printf("s1 %d\n", sum);
            if(i>sqrtn && i*i<n-1) {
                sum+=c(n,n/i)-1;
                printf("s1 %d\n", sum);
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
