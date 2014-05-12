#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

int s[1500005], t[1500005], a[1500005];
ll cumm[1500005];

int main(){
    int T, i,j,k, n,m, entered;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &s[0], &t[0], &n, &m);

        k=0;
        a[0]=cumm[0]=0;
        for(i=1; i<=n; i++){
            s[i] = (78901 + 31*s[i-1])%699037;
            t[i] = (23456 + 64*t[i-1])%2097151;
            a[i] = (s[i]%100+1)*(t[i]%100+1);
            cumm[i]=cumm[i-1]+a[i];
            if(cumm[i]<m) k=i;
        }
        entered=0;
        for(i=1; k>=0, i+k<=n; i++){
            while(cumm[i+k]-cumm[i-1]>m) { k--; entered=1; }
        }
        if(entered) k++;
        printf("%d\n", k);
    }
    return 0;
}
