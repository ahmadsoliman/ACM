#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n-(int)ceil(n/3.0));
    return 0;
}
