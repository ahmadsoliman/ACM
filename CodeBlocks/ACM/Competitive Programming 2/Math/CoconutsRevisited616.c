#include <stdio.h>
#include <string.h>
#include <math.h>

int compare (const void * a, const void * b) {
  return ( *(int*)b - *(int*)a );
}

int div[100000];

int main(){
    int c,n, i,j,k, divc, tmpc, found;
    while(scanf("%d", &c)>0){
        if(c<0) return 0;
        if(c==0){
            printf("0 coconuts, no solution\n");
            continue;
        }
        divc=0;
        c--;
        for(i=1; i*i<=c; i++){
            if(c%i==0){
                div[divc++]=i;
                if(i*i!=c) div[divc++]=c/i;
            }
        }
        qsort(div, divc, sizeof(int), compare);
        c++;
        found=0;
        for(i=0; i<divc; i++){
            tmpc=c, n=div[i], k=0;
            while(tmpc%n==1){
                tmpc-=1+tmpc/n;
                k++;
            }
            if(k==n && tmpc%n==0){
                found=1; break;
            }
        }
        if(found) printf("%d coconuts, %d people and 1 monkey\n", c, n);
        else printf("%d coconuts, no solution\n", c);
    }
    return 0;
}
