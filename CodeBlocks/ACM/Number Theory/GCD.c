#include <stdio.h>

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}
int main(){
    int n, G, i, j;
    while(scanf("%d", &n)>0){
        if(n==0)
            break;

        G=0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++){
                G+=gcd(i,j);
            }
        printf("%d\n", G);
    }
    return 0;
}
