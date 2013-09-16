#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)
#define INF 100000000

int m, done, price[16], area[16], nCoup[16], coupI[16][300], coupV[16][300], adp[32800], vis[32800], kase;
double pdp[32800];

void recur(int bm){
    if(bm==done) {
        pdp[bm]=0;
        adp[bm]=0;
        return;
    }

    if(vis[bm]==kase) return;

    int i,j,k, minA=0,curA, cur;
    double minV=INF, curV, curP, minP=0, tmpP;

    for(i=0; i<m; i++){
        if(!(bm&(1<<i))){
            tmpP=price[i];
            for(k=0; k<nCoup[i]; k++) if(!(bm&(1<<coupI[i][k]))) tmpP*=coupV[i][k]/100.0;

            recur(cur=(bm|(1<<i)));
            curP = pdp[cur];
            curA = adp[cur];
            curV = curP/curA;
            if(curV<minV) { minV=curV; minP=curP; minA=curA; }

            curP += tmpP;
            curA += area[i];
            curV = curP/curA;
            if(minV==INF || curV<minV) { minV=curV; minP=curP; minA=curA; }
        }
    }
    pdp[bm] = minP;
    adp[bm] = minA;
    vis[bm] = kase;
}

int main(){
    //freopen("helpbob.txt", "r", stdin);
    int i, j, index,v,n;
    kase=1;
    while(scanf("%d", &m)>0){
        if(m==0) return 0;
        done=1<<m;
        memset(nCoup, 0, sizeof nCoup);
        for(i=0; i<m; i++) {
            scanf("%d %d %d", &price[i], &area[i], &n);
            for(j=0; j<n; j++) {
                scanf("%d %d", &index, &v);
                index--;
                coupV[index][nCoup[index]]=100-v;
                coupI[index][nCoup[index]]=i;
                nCoup[index]++;
            }
        }
        recur(0);
        printf("%.4lf\n", pdp[0]/adp[0]);
        kase++;
    }
    return 0;
}
