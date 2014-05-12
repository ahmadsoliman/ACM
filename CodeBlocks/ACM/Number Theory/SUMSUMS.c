#include <stdio.h>
#include <string.h>
#include <math.h>

int K, MOD;

typedef long long ll;

long long mod(long long n){
    n%=MOD;
    if(n<0) n+=MOD;
    return n;
}

void matcpy(int dist[][2], int src[][2], int n, int m){
    int i,j;
    for(i=0; i<n; i++) for(j=0; j<m; j++) dist[i][j]=src[i][j];
}

ll intr;
void matrixmult(int a[][2], int b[][2], int c[][2]){
    int i,j,k;
    for(i=0; i<K; i++){
        for(j=0; j<K; j++){
            intr=0;
            for(k=0; k<K; k++) intr+=(ll)a[i][k]*b[k][j];
            c[i][j]=intr%MOD;
        }
    }
}

int ident[2][2]={{1,0},{0,1}};

void matrixpow(int a[][2], int n, int m, long long p, int res[][2]){
    int base[2][2], tmp[2][2];
    matcpy(res, ident, 2, 2);
    matcpy(base, a, 2, 2);
    while (p){
        if (p & 1){
            matrixmult(res, base, tmp);
            matcpy(res, tmp, 2, 2);
        }
        p >>= 1;
        matrixmult(base, base, tmp);
        matcpy(base, tmp, 2, 2);
    }
}

int n, i,j,flag, nums[50010], diff[50010];
long long P, S0, CP;

int main(){
    K=2;
    MOD=98765431;

    scanf("%d %lld", &n, &P);
    scanf("%d", &nums[0]);
    S0=nums[0];
    for(i=1; i<n; i++) {
        scanf("%d", &nums[i]);
        S0=mod(S0+nums[i]);
        diff[i]=mod((ll)nums[0]-nums[i]);
    }

    int T[2][2]= {{n-1,0},{1,mod(-1)}}, TN1[2][2], F1[2]={S0, nums[0]};

    matrixpow(T, 2, 2, P, TN1);

    CP = 0;
    for(i=0; i<K; i++) CP = (CP + ((ll)TN1[1][i] * F1[i])%MOD) % MOD;

    printf("%d\n", CP);
    flag=P&1;
    for(i=1; i<n; i++){
        if(flag) printf("%d\n", mod(CP+diff[i]));
        else printf("%d\n", mod(CP-diff[i]));
    }
    return 0;
}

