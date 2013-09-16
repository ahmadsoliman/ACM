#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(x,y) (((x)>(y))?x:y)

int n;
int P[100100];
int S[100100];
int s_sz=0;

int main(){
    int i;
    while(1){
        scanf("%d", &n);
        if (n==0) break;
        for(i=1; i<=n; i++) scanf("%d", &P[i]);

        long long ans=0;
        s_sz=0;
        P[0]=0;
        P[n+1]=0;
        for(i=1; i<=n+1; i++) {
            while(s_sz && P[S[s_sz]]>=P[i]) {
                ans = max(ans, (long long)P[S[s_sz]]*(long long)(i-S[s_sz-1]-1));
                s_sz--;
            }
            S[++s_sz] = i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
