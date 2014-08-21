#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000000
int d[MAX+10];

int main(){
    int n, i,j,k, sqrtn, flag, found=0, i2;
    for(i=2; i<=1000; i++){
        i2=i*i;
        d[i]+=2;
        for(j=i; j<MAX; j+=i)  {
            if(i*i>j)continue;
            div[j][d[j]++]=i;
            if(j!=i2) div[j][d[j]++]=j/i;
        }
    }
    for(i=1001; i<MAX; i++) d[i]+=2;

    printf("%d %d\n", i, d[131072]);

    return 0;
}
