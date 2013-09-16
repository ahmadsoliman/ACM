#include <stdio.h>
#include <string.h>
#include <math.h>

int ans[1010];

int main(){
    int n, i,j,k, ones, zeroones;

    ans[1]=0; ones=1; zeroones=1;
    for(i=2; i<10; i++){
        ans[i]=zeroones;
        zeroones=ans[i-1]+ones;
        ones<<=1;
    }
    while(scanf("%d", &n)>0) printf("%d\n", ans[n]);
    return 0;
}

/*
01
1001
01101001

*/
