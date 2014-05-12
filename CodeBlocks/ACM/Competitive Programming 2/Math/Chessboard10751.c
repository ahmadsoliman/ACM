#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int n, i, t;
    double fac=sqrt(2.0)-1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n==1) printf("%.3lf\n", 0);
        else if(n%2==1) printf("%.3lf\n", (double)(n*n+fac));
        else printf("%.3lf\n", (double)n*n);
    }
    return 0;
}
