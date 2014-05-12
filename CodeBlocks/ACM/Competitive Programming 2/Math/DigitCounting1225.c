#include <stdio.h>
#include <string.h>
#include <math.h>

int freq[11], cumm[10005][11];

int main(){
    int n, i,j, t;
    for(i=1; i<10001; i++){
        memset(freq, 0, sizeof freq);
        n=i;
        while(n>0) freq[n%10]++, n/=10;
        for(j=0; j<10; j++) cumm[i][j]=cumm[i-1][j]+freq[j];
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d", cumm[n][0]);
        for(i=1; i<10;  i++) printf(" %d", cumm[n][i]);
        printf("\n");
    }
    return 0;
}
