#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(){
    int t, n, m, c, i, j;
    //scanf("%d", &t);
    //while(t--){
    scanf("%d %d", &n, &m);

    printf("%d\n", n+m-1);
    if(n>m){
        for(i=1; i<=m; i++){
            printf("1 %d\n", i);
        }
        for(i=2; i<=n; i++){
            printf("%d 1\n", i);
        }
    }else{
        for(i=1; i<=n; i++){
            printf("%d 1\n", i);
        }
        for(i=2; i<=m; i++){
            printf("1 %d\n", i);
        }
    }
    return 0;
}
