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
#define FOR(i,n) for (int i = 0; i < n; i++)

int MOD;

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
matrix pow(matrix A, ll p) {
    matrix base(A), res=identity(K);
    while(p){
        if(p&1) res = mul(res, base);
        p>>=1;
        base = mul(base, base);
    }
    return res;
}


// returns the N-th term of Fibonacci sequence
int fib(ll N) {
    if(N==0 || N==1) return 1;
    if(N==2) return 3;
    if(N==3) return 5;
    K=3;
    // create vector F1
    vector<ll> F1(K);
    F1[0] = 3; F1[1] = 5; F1[2]=1;

    // create matrix T
    matrix T(K, vector<ll>(K));
    T[0][0] = 0, T[0][1] = 1, T[0][2] = 0;
    T[1][0] = 1, T[1][1] = 1, T[1][2] = 1;
    T[2][0] = 0, T[2][1] = 0, T[2][2] = 1;

    // raise T to the (N-1)th power
    T = pow(T, N-2);

    // the answer is the first row of T . F1
    ll res = 0;
    FOR(i, K) res = (res + (T[0][i] * F1[i])%MOD) % MOD;
    return res;
}


int main(){
    ll n;
    int b, res, kase=1;
    while(scanf("%lld %d", &n, &b)>0){
        if(n==0 && b==0) return 0;
        MOD=b;
        res = fib(n);
        res %= b;
        printf("Case %d: %lld %d %d\n", kase++, n, b, res);
    }
    return 0;
}
