#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int t, n, i,j,k, cnt;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        cnt=0;
        i=2;
        while(i*i<=n){
            while(n%i==0) n/=i, cnt++;
            i++;
        }
        if(n>1) cnt++;
        if(cnt==2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
