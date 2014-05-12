#include <stdio.h>
#include <string.h>
#include <math.h>

int sum[60005];

int main(){
    int i,j,k, n;
    sum[0]=sum[1]=0;
    for(i=2; i<60005; i++){
        sum[i]=1;
        for(j=2; j*j<=i; j++) if(i%j==0) {
            sum[i]+=j;
            if(j*j!=i) sum[i]+=i/j;
        }
    }
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n)>0){
        if(n==0) break;
        if(sum[n]==n) printf("%5d  PERFECT\n", n);
        else if(sum[n]<n) printf("%5d  DEFICIENT\n", n);
        else printf("%5d  ABUNDANT\n", n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
