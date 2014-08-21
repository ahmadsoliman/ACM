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

typedef vector< vector<int> > matrix;

#define INF 1000000000
#define FOR(i,n) for (int i = 0; i < n; i++)

int K, MOD;

/*
2
1 1 1000000000 1000000000000000
1000000 1000000 1000000000 1000000000000000000
282257702
501000000
*/

int mod(ll n, int m){
    n%=m;
    if(n<0) n+=m;
    return n;
}
// computes A * B
unsigned long long intr;
matrix mul(matrix A, matrix B) {
    matrix C(K, vector<int>(K));
    FOR(i, K) FOR(j, K) {
        intr=0;
        FOR(k, K){
            intr += (ll)A[i][k] * B[k][j];
        }
        C[i][j] = intr%MOD;
    }
    return C;
}

int x[3][3]={{1,0,0},{0,1,0},{0,0,1}};
matrix ident(3), T(3), A, TN1;
vector<int> F1(3);

int t1[]={0,1,0}, t2[]={0,0,1}, t3[]={-1,2,2}, t, f0, f1, f2,f3,f4, r;
ll n;

int main(){

//freopen("in", "r", stdin);
//freopen("out", "w", stdout);

    K=3;
    scanf("%d", &t);

    T[0]=vector<int>(t1, t1+3);
    T[1]=vector<int>(t2, t2+3);
    T[2]=vector<int>(t3, t3+3);

    ident[0]=vector<int>(x[0], x[0]+3);
    ident[1]=vector<int>(x[1], x[1]+3);
    ident[2]=vector<int>(x[2], x[2]+3);

    while(t--){
        scanf("%d %d %d %lld", &f0, &f1, &MOD, &n);

        f0%=MOD;
        f1%=MOD;
        f2 = (f0+f1+2*(ll)sqrt(3+f0*f1)%MOD);
        if(f2>MOD) f2-=MOD;
        f3 = mod(-1*f0,MOD) + 2*f1 % MOD + 2*f2 % MOD;
        if(f3>MOD) f3-=MOD;
        f4 = mod(-1*f1,MOD) + 2*f2 % MOD + 2*f3 % MOD;
        if(f4>MOD) f4-=MOD;

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

        n-=2;
        TN1 = ident;
        A=T;
        while(n>0){
            if(n&1) TN1 = mul(TN1, A);
            n>>=1;
            A = mul(A, A);
        }

        r=0;
        for(int i=0; i<3; i++) {
            r=(r+(ll)TN1[0][i]*F1[i]%MOD);
            if(r>MOD) r-=MOD;
        }
        printf("%d\n", r);
    }
    return 0;
}

