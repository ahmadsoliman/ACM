#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int T, grid[100][100], cumm[100][100], newgrid[100][100];
char in[100];

int sum(int r1, int c1, int r2, int c2){
    return cumm[r2][c2]-cumm[r1-1][c2]-cumm[r2][c1-1]+cumm[r1-1][c1-1];
}

void fillg(int v, int r1, int c1, int r2, int c2){
    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            newgrid[i][j]=v;
        }
    }
}

void recur(int r1, int c1, int r2, int c2){
    if(r1==r2 && c1==c2) {
        newgrid[r1][c1]=grid[r1-1][c1-1];
        return;
    }

    int n=(r2-r1+1), n2=(n/2)*(n/2), midr=(r2+r1+1)/2, midc=(c2+c1+1)/2;

    int s1=sum(r1, c1, r2, c2), s0=n*n-s1;
    s1 = s1*100/(n*n);
    s0 = s0*100/(n*n);
    if(s1>=T) { fillg(1, r1, c1, r2, c2); return; }
    else if(s0>=T) { fillg(0, r1, c1, r2, c2); return; }

    int sulr=r1,sulc=c1, surr=r1,surc=midc, sllr=midr, sllc=c1, slrr=midr, slrc=midc;
    int eulr=midr-1,eulc=midc-1, eurr=midr-1,eurc=c2, ellr=r2, ellc=midc-1, elrr=r2, elrc=c2;

    int ul1, ur1, ll1, lr1, ul0, ur0, ll0, lr0;

    ul1=sum(sulr, sulc, eulr, eulc);
    ur1=sum(surr, surc, eurr, eurc);
    ll1=sum(sllr, sllc, ellr, ellc);
    lr1=sum(slrr, slrc, elrr, elrc);

    ul0=n2-ul1;
    ur0=n2-ur1;
    ll0=n2-ll1;
    lr0=n2-lr1;

    ul1=ul1*100/n2;
    ur1=ur1*100/n2;
    ll1=ll1*100/n2;
    lr1=lr1*100/n2;
    ul0=ul0*100/n2;
    ur0=ur0*100/n2;
    ll0=ll0*100/n2;
    lr0=lr0*100/n2;

    //ul
    recur(sulr, sulc, eulr, eulc);

    //ur
    recur(surr, surc, eurr, eurc);

    //ll
    recur(sllr, sllc, ellr, ellc);

    //lr
    recur(slrr, slrc, elrr, elrc);
}

int main(){
    int i,j,k, n, kase=1;

    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        scanf("%d", &T);
        for(i=0; i<n; i++) {
            scanf("%s", in);
            for(j=0; j<n; j++) grid[i][j]=in[j]-'0';
        }

        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                cumm[i][j]=cumm[i-1][j]+cumm[i][j-1]-cumm[i-1][j-1]+grid[i-1][j-1];
            }
        }

        recur(1, 1, n, n);
        printf("Image %d:\n", kase++);
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                printf("%d", newgrid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

