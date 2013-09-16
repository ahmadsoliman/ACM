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

typedef vector< vi > matrix;

#define INF 1000000000
int MOD;
#define FOR(i,n) for (int i = 0; i < n; i++)

int K;

// computes A * B
matrix mul(matrix A, matrix B) {
    matrix C(K, vi(K));
    FOR(i, K) FOR(j, K) FOR(k, K)
        C[i][j] = (C[i][j] + ((ll)A[i][k] * B[k][j]) %MOD) % MOD;
    return C;
}

matrix identity(int n){
    matrix res(n, vi(n));
    FOR(i, n) res[i][i]=1;
    return res;
}

// computes A ^ p
matrix pow(matrix A, ll p) {
    matrix base(A), res=identity(K);
    while(p){
        if(p&1) res = mul(res, base);
        p>>=1;
        base = mul(base, base);
    }
    return res;
}

int mod(int x, int m){
    while(x<0) x+=m;
    return x%m;
}

int base[20], cs[20];

int main(){
    int t, res, Sn, Sm;
    ll n,m;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &K);
        FOR(i, K) scanf("%d", &base[i]);
        FOR(i, K) scanf("%d", &cs[i]);
        scanf("%lld %lld %d", &n, &m, &MOD);

        K++;
        matrix F1(K, vi(1)), T(K, vi(K)), TN, TM;

        for(int i=1; i<K; i++) {
            F1[i][0]=base[i-1];
            if(i<K) T[i-1][i]=1;
        }
        T[0][0]=1;
        FOR(i, K-1) T[K-1][i+1]=cs[K-i-2];

        TN = pow(T, n-1);
        TM = pow(T, m);

        Sn=0;
        FOR(i, K) Sn = (Sn + ((ll)TN[0][i]*F1[i][0])%MOD)%MOD;

        Sm=0;
        FOR(i, K) Sm = (Sm + ((ll)TM[0][i]*F1[i][0])%MOD)%MOD;

        res = mod(Sm-Sn, MOD);
        printf("%d\n", res);
    }
    return 0;
}
/*
F1 = S0, basecases

T = 1 1 0 0 .. 0
    0 0 1 0 .. 0
    ..   ..   ..
    0 ck  ..   c1
*/
