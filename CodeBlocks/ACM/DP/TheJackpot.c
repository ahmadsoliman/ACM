#include <stdio.h>

#define max(x,y) ((x>y)?x:y)

int main(){
    int N, cur, last, maxS, i;
    while(scanf("%d", &N)){
        if(N==0)
            break;
        for(i=0; i<N; i++){
            scanf("%d",&cur);
            if(i==0){
                last=cur;
                maxS=last;
            }else{
                last = max(cur , last+cur);
                if(last>maxS)
                    maxS=last;
            }
        }
        if(maxS>0)
            printf("The maximum winning streak is %d.\n", maxS);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
