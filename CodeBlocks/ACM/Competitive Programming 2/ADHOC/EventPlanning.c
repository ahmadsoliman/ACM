#include <stdio.h>

#define INF 1000000000

int main(){
    int n,b,h,w, i, j, p, beds, minP;
    while(scanf("%d %d %d %d", &n, &b, &h, &w)>0){
        minP=INF;
        for(i=0; i<h; i++){
            scanf("%d", &p);
            for(j=0; j<w; j++){
                scanf("%d", &beds);
                if(beds>=n && p*n<b && p*n<minP) minP=p*n;
            }
        }
        if(minP==INF) printf("stay home\n");
        else printf("%d\n", minP);
    }
    return 0;
}
