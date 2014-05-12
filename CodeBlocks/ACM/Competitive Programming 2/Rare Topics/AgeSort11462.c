#include <stdio.h>
#include <string.h>
#include <math.h>


int freq[105];

int main(){
    int n, i, k;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        memset(freq, 0, sizeof freq);
        for(i=0; i<n; i++){
            scanf("%d", &k);
            freq[k]++;
        }
        for(i=0, k=0; i<101; i++){
            while(freq[i]-->0){
                printf("%d", i);
                if(++k!=n) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
