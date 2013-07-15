#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

int m, pDone, price[16], area[16], nCoup[16], coupI[16][16], coupV[16][16], areas[32800];
double prices[32800];

int recur(int bm){
    if(areas[bm]!=-1) return areas[bm];
    if(bm == 0) return areas[bm] = 0;

    int a=0,i;
    for(i=0; i<m; i++)
        if(bm&(1<<i)) {
            a+=area[i]+recur(bm^(1<<i));
            break;
        }
    return areas[bm] = a;
}


double recur2(int bm){
    if(bm == pDone) return 0;

   // if(prices[bm]!=-1) return prices[bm];

    int i,j,k;
    double minP=1000000000, p;

    for(i=0; i<m; i++){
        if(!(bm&(1<<i))&&(pDone&(1<<j))){
            p = 1.0*price[i];

            for(j=0; j<m; j++)
                if(bm&(1<<j))
                    for(k=0; k<nCoup[j]; k++) if(coupI[j][k]==i) p*=(coupV[j][k]/100.0);

            p += recur2(bm|(1<<i));
            if(p<minP)
                minP = p;
        }
     }
     return prices[bm] = minP;
}

int main(){
    int i, j, m2;
    double res, cur;
    while(scanf("%d", &m)>0){
        if(m==0) return 0;
        for(i=0; i<m; i++) {
            scanf("%d %d %d", &price[i], &area[i], &nCoup[i]);
            for(j=0; j<nCoup[i]; j++) {
                scanf("%d %d", &coupI[i][j], &coupV[i][j]);
                coupI[i][j]--;
                coupV[i][j] = 100-coupV[i][j];
            }
        }
        m2 = (1<<m);
        res = 100000000.0;
        for(i=1; i<m2; i++) {
            areas[i]=-1;
            pDone=i;
            for(j=0; j<=i; j++) prices[j]=-1;
            cur = recur2(0)/recur(i);
            if(cur<res) res = cur;
        }
        printf("%.4lf\n", res+1e-9);
    }
    return 0;
}
