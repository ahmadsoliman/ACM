#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int grid[520][520], pre[520][520][10][2];

char in[520];

int count(int i, int j, int n, int ans){
    n = (int)(log(n)/log(2)+1e-8);
    if(n==0) return ans!=grid[i][j];
    if(pre[i][j][n][ans]!=-1) return pre[i][j][n][ans];
    int mid=pow(2, n-1);
    return pre[i][j][n][ans]=count(i,j,mid, ans)+count(i+mid, j, mid, ans)+count(i,j+mid, mid, ans)+count(i+mid, j+mid, mid, ans);
}

int d[4][2], resgrid[520][520];

void fill(int i, int j, int n, int ans) {
    for(int k=i; k<i+n; k++){
        for(int l=j; l<j+n; l++){
            resgrid[k][l]=ans;
        }
    }
}

int recur(int i, int j, int n){
    if(n==1) { resgrid[i][j]=grid[i][j]; return 0; }
    int mid=n/2;

    int rec[4];
    rec[0]=recur(i,j, mid), rec[1]=recur(i+mid, j, mid);
    rec[2]=recur(i, j+mid, mid), rec[3]=recur(i+mid, j+mid, mid);

    d[0][0]=count(i,j, mid, 0), d[0][1]=count(i,j, mid, 1);
    d[1][0]=count(i+mid, j, mid, 0), d[1][1]=count(i+mid, j, mid, 1);
    d[2][0]=count(i, j+mid, mid, 0), d[2][1]=count(i, j+mid, mid, 1);
    d[3][0]=count(i+mid, j+mid, mid, 0), d[3][1]=count(i+mid, j+mid, mid, 1);

    int curv, minv=1000000000, mink, minl, minr, minf;
    for(int k=0; k<4; k++){
        for(int l=0; l<4; l++){
            for(int r=0; r<4; r++){
                for(int f=0; f<4; f++){
                    if(k==l || k==r || k==f || l==r || l==f || r==f) continue;
                    curv = rec[k]+rec[l]+d[r][0]+d[f][1];
                    if(curv<minv){
                        minv=curv;
                        mink=k, minl=l, minr=r, minf=f;
                    }
                    curv = rec[k]+rec[l]+d[r][1]+d[f][0];
                    if(curv<minv){
                        minv=curv;
                        mink=k, minl=l, minr=f, minf=r;
                    }
                }
            }
        }
    }
    switch(minr){
        case 0: fill(i, j, mid, 0) ; break;
        case 1: fill(i+mid, j, mid, 0) ; break;
        case 2: fill(i, j+mid, mid, 0) ; break;
        case 3: fill(i+mid, j+mid, mid, 0) ; break;
    }
    switch(minf){
        case 0: fill(i, j, mid, 1) ; break;
        case 1: fill(i+mid, j, mid, 1) ; break;
        case 2: fill(i, j+mid, mid, 1) ; break;
        case 3: fill(i+mid, j+mid, mid, 1) ; break;
    }
    return minv;
}

int main(){
    int i,j, n;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", in);
        for(j=0; j<n; j++){
            grid[i][j]=in[j]-'0';
        }
    }
    memset(pre, -1, sizeof pre);
    printf("%d\n", recur(0,0, n));
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) printf("%d", resgrid[i][j]);
        printf("\n");
    }
    return 0;
}
