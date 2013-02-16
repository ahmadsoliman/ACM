#include <stdio.h>

int main(){
    int n, j, d1,d2,d3,d4;
    scanf("%d", &n);
    while(n++){
        j = n;
        d1=j%10;j/=10;
        d2=j%10;j/=10;
        d3=j%10;j/=10;
        d4=j%10;j/=10;
        if(d1==d2||d1==d3||d1==d4||d2==d3||d2==d4||d3==d4)continue;
        printf("%d", n);
        break;
    }
    return 0;
}
