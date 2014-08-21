#include <stdio.h>

int main(){
    FILE *in = fopen("input.in", "rw"), *out = fopen("output.out", "w");
    int n;
    fscanf(in, "%d", &n);
    n*=100;
    fprintf(out, "%d\n", n);
    return 0;
}
