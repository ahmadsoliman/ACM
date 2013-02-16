#include <stdio.h>

int main(){
    int t,i, N, D, M;
    long long res;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &N, &D, &M);
        res=1ll;
        for(i=N; i>1; i--){
            if(D%i==0){
                D/=i;
                continue;
            }
            res*=i;
            if(M>0&&res>=M)res%=M;
        }
        if(D>1)
            printf("-1\n");
        else
            printf("%lld\n", res);
    }
    return 0;
}
