#include <stdio.h>

int coeffs[1005], caseNum,n,i,j,k, curK, eval, curPow;

int main(){
    caseNum=1;
    while(scanf("%d", &n)>-1){
        if(n<0)
            break;
        for(i=n++; i>-1; i--){
            scanf("%d", &coeffs[i]);
        }
        scanf("%d", &k);
        printf("Case %d:\n", caseNum++);
        for(i=0; i<k; i++){
            scanf("%d", &curK);
            eval=0;
            curPow=1;
            for(j=0; j<n; j++, curPow*=curK){
                eval+=curPow*coeffs[j];
            }
            printf("%d\n", eval);
        }
    }
    return 0;
}
