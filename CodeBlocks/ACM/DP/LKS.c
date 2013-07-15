#include <stdio.h>

int K, N, v[501], w[501], dp[2000005];

int main(){
    int i, j, m, t;
    scanf("%d %d", &K, &N);
    for(i=0; i<N; i++) scanf("%d %d", &v[i], &w[i]);
    memset(dp, 0, sizeof dp);
    for(m=1; m<=K; m++){
        for(i=0; i<N; i++){
            if(m-w[i]>=0){
                t = dp[m-w[i]] + v[i];
                if(t>=dp[m]) dp[m] = t;
            }
        }
    }
    for(m=1; m<=K; m++) printf("%d ", dp[m]);
    printf("%d\n", dp[K]);
    return 0;
}
