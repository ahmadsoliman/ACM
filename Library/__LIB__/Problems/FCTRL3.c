#include <stdio.h>
#include <string.h>
#include <math.h>

#define INF 1000000000

int main(){
    int t, n, i,j, r1[10]={0,0,0,0,2,2,2,4,2,8},r2[10]={1,1,2,6,4,0,0,0,0,0};
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n<10) printf("%d %d\n", r1[n], r2[n]);
        else printf("0 0\n");
    }
    return 0;
}
