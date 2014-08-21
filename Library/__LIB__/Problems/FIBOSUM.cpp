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
#define MOD 1000000007


void matcpy(int dist[][2], int src[][2], int n, int m){
    int i,j;
    for(i=0; i<n; i++) for(j=0; j<m; j++) dist[i][j]=src[i][j];
}

void matrixmult(int a[][2], int b[][2], int c[][2]){
    int i,j,k;
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            c[i][j]=0;
            for(k=0; k<2; k++) c[i][j]=((ll)c[i][j]+(ll)a[i][k]*(ll)b[k][j]%MOD)%MOD;
        }
    }
}

void matrixpow(int a[][2], int n, int m, int p, int res[][2]){
    int base[2][2], identity[2][2]={{1,0},{0,1}}, tmp[2][2];
    matcpy(res, identity, 2, 2);
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

int mod(int a, int m){
    while(a<0) a+=m;
    return a%m;
}

int main(){
    int a[2][2]={{1,1},{1,0}}, c[2][2], t, i,j, n,m, s;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        matrixpow(a, 2,2, n, c);
        s = c[0][0]-1;
        matrixpow(a, 2,2, m+1, c);
        s = mod((c[0][0]-1-s), MOD);
        printf("%d\n", s);
    }
    return 0;
}

/*
    ^n
1 1       fn+1 fn
      =
1 0        fn  fn-1

1 1   1 1  =  2 1
1 0   1 0     1 1

sum f0..fn = fn+2 -1
*/
