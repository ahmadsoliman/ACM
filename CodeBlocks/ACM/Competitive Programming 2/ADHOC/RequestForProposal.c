#include <stdio.h>
#include <string.h>

int main(){
    int kase=1, n,p, r, maxr, i,j;
    double d, mind;
    char name[1000], res[1000], hals[1000];

    while(sscanf(gets(hals), "%d %d\n", &n, &p)){
        if(n==0&&p==0) return 0;
        if(kase>1) printf("\n");
        maxr=-1;
        mind=2000000000;
        for(i=0; i<n; i++) gets(hals);
        for(i=0; i<p; i++) {
            gets(name);
            sscanf(gets(hals), "%lf %d\n", &d, &r);
            for(j=0; j<r; j++) gets(hals);
            if(r>maxr || (r==maxr && d<mind)) {
                maxr=r;
                mind=d;
                strcpy(res, name);
            }
        }
        printf("RFP #%d\n%s\n", kase++, res);
    }
    return 0;
}
