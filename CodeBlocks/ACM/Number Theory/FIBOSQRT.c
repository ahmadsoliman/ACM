#include <stdio.h>
#include <string.h>
#include <math.h>

int K, MOD;

/*
2
1 1 1000000007 1000000000000000
1000000 1000000 1000000000 1000000000000000000
282257702
501000000
*/

int mod(int n, int m){
    n%=m;
    if(n<0) n+=m;
    return n;
}

void matcpy(int dist[][3], int src[][3], int n, int m){
    int i,j;
    for(i=0; i<n; i++) for(j=0; j<m; j++) dist[i][j]=src[i][j];
}

unsigned long long intr = 0;
void matrixmult(int a[][3], int b[][3], int c[][3]){
    int i,j,k;
    for(i=0; i<K; i++){
        for(j=0; j<K; j++){
            intr=0;
            for(k=0; k<K; k++) intr += (unsigned long long)a[i][k]*b[k][j];
            c[i][j]=intr%MOD;
        }
    }
}

int ident[3][3]={{1,0,0},{0,1,0},{0,0,1}};

void matrixpow(int a[][3], int n, int m, long long p, int res[][3]){
    int base[3][3], tmp[3][3];
    matcpy(res, ident, 3, 3);
    matcpy(base, a, 3, 3);
    while (p){
        if (p & 1){
            matrixmult(res, base, tmp);
            matcpy(res, tmp, 3, 3);
        }
        p >>= 1;
        matrixmult(base, base, tmp);
        matcpy(base, tmp, 3, 3);
    }
}

int t, i,j;
int f0, f1, f2,f3,f4;
long long n, r;

int main(){
    K=3;
    scanf("%d", &t);

    int T[3][3]= {{0,1,0},{0,0,1},{-1,2,2}}, TN1[3][3], F1[3];

    while(t-->0){
        scanf("%d %d %d %lld", &f0, &f1, &MOD, &n);

        f2 = (f0+f1+(2*(long long)round(sqrt((double)(3+(long long)f0*f1))+1e-7))%MOD)%MOD;
        f3 = (mod(-1*f0,MOD) + 2*f1 % MOD + 2*f2 % MOD)%MOD;
        f4 = (mod(-1*f1,MOD) + 2*f2 % MOD + 2*f3 % MOD)%MOD;
        f0%=MOD;
        f1%=MOD;

        switch(n){
            case 0: printf("%d\n", f0%MOD); continue;
            case 1: printf("%d\n", f1%MOD); continue;
            case 2: printf("%d\n", f2%MOD); continue;
            case 3: printf("%d\n", f3%MOD); continue;
            case 4: printf("%d\n", f4%MOD); continue;
        }

        F1[0] = f2;
        F1[1] = f3;
        F1[2] = f4;

        T[2][0]=mod(-1, MOD);
        matrixpow(T, 3, 3, n-2, TN1);

        r=0;
        for(i=0; i<3; i++) {
            r=(r+(long long)TN1[0][i]*F1[i]%MOD)%MOD;
        }
        printf("%lld\n", r);
    }
    return 0;
}

