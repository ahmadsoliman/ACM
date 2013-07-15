#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(){
    int t, n, c;
    //scanf("%d", &t);
    //while(t--){
    scanf("%d", &n);

    while(n>1){
        if(n%1000==144){
            n/=1000;
        }else if(n%100==14){
            n/=100;
        }else if(n%10==1){
            n/=10;
        }else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
