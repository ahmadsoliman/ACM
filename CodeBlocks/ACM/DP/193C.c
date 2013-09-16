#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int i, g, d, f;
} pair;

int r;
pair pairs[200005];

int compare1 (const void * a, const void * b)
{
    r = ( (*(pair*)b).g - (*(pair*)a).g );
    if(r==0) return ( (*(pair*)b).d - (*(pair*)a).d );
    return r;
}

int compare2 (const void * a, const void * b)
{
    r = ( (*(pair*)a).d - (*(pair*)b).d );
    if(r==0) return ( (*(pair*)b).g - (*(pair*)a).g );
    return r;
}

int main(){
    int n, i, p, k, g, d, c;
    scanf("%d %d %d", &n, &p, &k);
    pair p1;
    p1.f=0;
    for(i=0; i<n; i++) {
        scanf("%d %d", &g, &d);
        p1.i=i+1;
        p1.g=g;
        p1.d=d;
        pairs[i]=p1;
    }

    qsort(pairs, n, sizeof(pair), compare1);

    for(i=0; i<k; i++) {
        printf("%d", pairs[i].i);
        pairs[i].f=1;
        if(i<p-1) printf(" ");
    }

    qsort(pairs, n, sizeof(pair), compare2);

    c=0;
    for(i=0; c<p-k && i<n; i++) {
        if(pairs[i].f!=1) {
            c++;
            printf("%d", pairs[i].i);
            if(c<p-k) printf(" ");
        }
    }

    return 0;
}
