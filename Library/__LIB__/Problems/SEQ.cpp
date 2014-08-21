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
#define MOD 1000000000
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
matrix pow(matrix A, int p) {
    matrix base(A), res=identity(K);
    while(p){
        if(p&1) res = mul(res, base);
        p>>=1;
        base = mul(base, base);
    }
    return res;
}

int base[15], cs[15];

int main(){
    int t, n, res;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &K);
        FOR(i, K) scanf("%d", &base[i]);
        FOR(i, K) scanf("%d", &cs[i]);
        scanf("%d", &n);

        if(n<=K) { printf("%d\n", base[n-1]); continue; }

        matrix F1(K, vi(1)), T(K, vi(K)), TN;
        FOR(i, K) {
            F1[i][0]=base[i];
            if(i<K-1) T[i][i+1]=1;
        }
        FOR(i, K) T[K-1][i]=cs[K-i-1];

        TN = pow(T, n-1);

        res=0;
        FOR(i, K) res = (res + ((ll)TN[0][i]*F1[i][0])%MOD)%MOD;
        printf("%d\n", res);
    }
    return 0;
}
/*
F1 = basecases

T = 0 1 0 0 .. 0
    0 0 1 0 .. 0
    ..   ..   ..
    ck ck-1 .. c1
*/
