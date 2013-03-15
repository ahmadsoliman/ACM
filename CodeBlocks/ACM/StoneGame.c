#include <stdio.h>

int main(){
    int N, xored, tmp, i;
    while(scanf("%d", &N)>0){
        if(N==0)break;
        xored = 0;
        for(i=0; i<N; i++){
            scanf("%d", &tmp);
            xored ^= tmp;
        }
        if(xored)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
