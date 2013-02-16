#include <stdio.h>

int main(){
    int n, i, j,fing,curFing, countF=0, countWays=5;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &fing);
        countF+=fing;
    }
    for(i=1; i<6; i++){
        curFing=fing+i;
        while(curFing>0){
            for(j=0; j<n; j++){
                if(curFing>0)curFing--;
                else {
                    countWays--;
                    break;
                }
            }
        }
    }
    printf("%d\n", ((countWays>=0)?countWays:0));
}
