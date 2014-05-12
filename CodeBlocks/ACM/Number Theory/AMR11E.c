#include <stdio.h>
#include <string.h>
#include <math.h>

int a[2705];
int lucky[1005];

void sieve(){
    int i, j;
    memset(a, 0, sizeof a);
    for(i=2;i<2700;i++)
        if(a[i]==0) {
            for(j=2*i; j<2700; j+=i) a[j]++;
        }
}

int main(){
    int t, n, i,j,k, sqrtn, flag, found=0, i2;

    sieve();k=0;
    for(i=30; i<2700; i++){
        if(a[i]>2) lucky[k++]=i;
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", lucky[n-1]);
    }
    return 0;
}
