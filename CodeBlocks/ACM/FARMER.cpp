#include <stdio.h>
#include <algorithm>

using namespace std;

int a[2005], b[2005];

int main(){
    int t, Q, M , K, i, sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &Q);
        scanf("%d", &M);
        scanf("%d", &K);
        for(i=0; i<M; i++) scanf("%d", &a[i]);
        for(i=0; i<K; i++) scanf("%d", &b[i]);
        sum=0;
        sort(a, a+M);
        for(i=M-1; i>=0 ; i--){
            if(a[i]<=Q){
                Q-=a[i];
                sum+=a[i];
            }
            if(Q==0)break;
        }
        if(Q>0){
            sort(b, b+K);
            for(i=K-1; i>=0 ; i--){
                if(b[i]<=Q){
                    Q-=b[i];
                    sum+=b[i]-1;
                }
                if(Q==0)break;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
