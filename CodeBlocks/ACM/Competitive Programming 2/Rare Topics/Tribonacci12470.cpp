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

typedef vector< vector<ll> > matrix;

#define INF 1000000000
#define MOD 1000000009
#define FOR(i,n) for (int i = 0; i < n; i++)

int K;

// computes A * B
matrix mul(matrix A, matrix B) {
    matrix C(K, vector<ll>(K));
    FOR(i, K) FOR(j, K) FOR(k, K)
        C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) %MOD) % MOD;
    return C;
}

matrix identity(int n){
    matrix res(n, vector<ll>(n));
    FOR(i, n) res[i][i]=1;
    return res;
}

// computes A ^ p
matrix pow(matrix A, long long p) {
    matrix base(A), res=identity(K);
    while(p){
        if(p&1) res = mul(res, base);
        p>>=1;
        base = mul(base, base);
    }
    return res;
}


int trib(long long N) {
    if(N==1) return 0;
    if(N==2) return 1;
    if(N==3) return 2;
    K=3;
    // create vector F1
    vector<ll> F1(K);
    F1[0] = 2; F1[1] = 1; F1[2]=0;
/*
            1 1 1   F3 F4
            1 0 0   F2 F3
            0 1 0   F1 F2
*/
    // create matrix T
    matrix T(K, vector<ll>(K));
    T[0][0] = 1, T[0][1] = 1, T[0][2] = 1;
    T[1][0] = 1, T[1][1] = 0, T[1][2] = 0;
    T[2][0] = 0, T[2][1] = 1, T[2][2] = 0;

    // raise T to the (N-1)th power

    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    FOR(i, K) res = (res + T[2][i]*F1[i]%MOD) % MOD;
    return res;
}

int main(){
    long long n;
    while(scanf("%lld", &n)>0){
        if(n==0) return 0;
        printf("%d\n", trib(n));
    }
    return 0;
}
