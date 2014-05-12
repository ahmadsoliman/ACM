#include <stdio.h>

int fact[10];

int main(){
    int i,j,k;

    fact[1]=1;
    for(i=2; i<10; i++) fact[i]=fact[i-1]*i;

    printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");

    double e=2.5;
    for(i=3; i<10; i++){
        e += 1.0/fact[i];
        printf("%d %.9lf\n", i, e);
    }
    return 0;
}
