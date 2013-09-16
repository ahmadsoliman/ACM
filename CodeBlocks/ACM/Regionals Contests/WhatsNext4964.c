#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int a,b,c, i,j, r;
    while(scanf("%d %d %d", &a, &b, &c)>0){
        if(a==0 && b==0 && c==0) return 0;
        if(a!=0 && b!=0 && b%a==0 && c%b==0){
            printf("GP %d\n", c*(b/a));
        }else printf("AP %d\n", c+b-a);
    }
    return 0;
}
