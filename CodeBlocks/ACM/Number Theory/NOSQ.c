#include <stdio.h>
#include <string.h>

#define MAX 100010
int sqrfree[MAX];

void sieve(){
    int i,j, sqr;
    for(i=2; i<318; i++){
        if(sqrfree[i]==0){
            for(j=sqr=i*i; j<MAX; j+=sqr) sqrfree[j]=1;
        }
    }
}

int cumm[10][MAX], cnt[10][MAX];

int main(){
    int t, i,j,k, a,b,d, tmp;

    memset(sqrfree, 0, sizeof sqrfree);
    sieve();
    for(i=2; i<MAX; i++){
        if(sqrfree[i]==0){
            tmp=i;
            while(tmp>0){
                cnt[tmp%10][i]=1;
                tmp/=10;
            }
        }
        for(j=0; j<10; j++) {
            cumm[j][i]=cnt[j][i]+cumm[j][i-1];
        }
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &a, &b, &d);
        printf("%d\n", cumm[d][b]-cumm[d][a]+cnt[d][a]);
    }
    return 0;
}
