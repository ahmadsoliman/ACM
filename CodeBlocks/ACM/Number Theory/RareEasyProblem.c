#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    unsigned long long x, N, r1,r2;
    while(scanf("%ld", &x)>0){
        if(x==0)
            break;
        r1 = 10*x/9;
        r2 = -1;
        for(i=1; i<10; i++){
            if((10*(x%9)-i)%9==0){
                r2 = (10*x-i)/9;
            }
        }
        if(r2==-1||r1==r2)
            printf("%lu\n", r1);
        else
            printf("%lu %lu\n", r2, r1);
    }
    return 0;
}
