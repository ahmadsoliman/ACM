#include <stdio.h>

#define INF (1000000000000000000LL)

long long sums[50005];

int main(){
    int N,M,i,j,l,type, x,y,k, cur;
    long long maxS;
    scanf("%d", &N);
    for(i=1; i<=N; i++){
        scanf("%d", &cur);
        sums[i]=sums[i-1]+cur;
    }
    scanf("%d", &M);
    for(i=0; i<M; i++){
        scanf("%d", &type);
        if(type==0){
            scanf("%d %d %d", &x, &y, &k);
            for(j=x,l=1; j<=y; j++,l++){
                sums[j]+=k*l;
            }
            l--;
            for(j=y+1; j<=N; j++){
                sums[j]+=k*l;
            }
        }else{
            scanf("%d %d", &x, &y);
            maxS=-INF;
            for(j=x; j<=y; j++){
                maxS=(sums[j]>maxS)?sums[j]:maxS;
            }
            printf("%lld\n", maxS);
        }
    }

    return 0;
}
