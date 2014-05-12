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

#define MOD 98765431
#define FOR(i,n) for (int i = 0; i < n; i++)

int K;

ll mod(ll n){
    n%=MOD;
    if(n<0) n+=MOD;
    return n;
}

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

int nums[50010], diff[50010];

int main(){
    K=2;

    int n, i,j, flag;
    ll P, S0, CP;

    scanf("%d %lld", &n, &P);
    scanf("%d", &nums[0]);
    S0=nums[0];
    for(i=1; i<n; i++) {
        scanf("%d", &nums[i]);
        S0=(S0+nums[i])%MOD;
        diff[i]=mod(nums[0]-nums[i]);
    }

    // create vector F1
    vector<ll> F1(K);
    F1[0] = S0; F1[1] = nums[0];

     // create matrix T
    matrix T(K, vector<ll>(K));
    T[0][0] = n-1, T[0][1] = 0; T[1][0] = 1, T[1][1] = mod(-1);

    // raise T to the (N-1)th power
    T = pow(T, P);

    CP = 0;
    FOR(i, K) CP = (CP + (T[1][i] * F1[i])%MOD) % MOD;

    printf("%d\n", CP);
    flag=P&1;
    for(i=1; i<n; i++){
        if(flag) printf("%d\n", mod(CP+diff[i]));
        else printf("%d\n", mod(CP-diff[i]));
    }
    return 0;
}
