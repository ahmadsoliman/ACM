#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int mod;

long long powmod(long long a, long long b, long long  c){
  long long result = 1;
  long long base = a;
  while (b){
    if (b & 1){
      result = result*base % c;
    }
    b >>= 1;
    base = base*base % c;
  }
  return result;
}

typedef struct mat{
    int a,b,c,d;
    mat(){

    }
    mat(int a1, int b1, int c1, int d1){
        a=a1;
        b=b1;
        c=c1;
        d=d1;
    }
};

mat mul(mat m1, mat m2){
    return mat((m1.a*m2.a+m1.b*m2.c)%mod, (m1.a*m2.b+m1.b*m2.d)%mod, (m1.c*m2.a+m1.d*m2.c)%mod, (m1.c*m2.b+m1.d*m2.d)%mod);
}

mat inv(mat m){
    int det = ((m.a*m.d-m.b*m.c)%mod+mod)%mod;
    det = powmod(det, mod-2, mod);
    return mat((m.d*det)%mod, ((-m.b*det)%mod+mod)%mod, ((-m.c*det)%mod+mod)%mod, (m.a*det)%mod);
}

int N;
mat seg[165000];

mat read(int s, int e, int i, int j, int n){
    if(s<=i && e>=j) return seg[n];
    if(i>e||j<s) return mat(1,0,0,1);
    int mid = (i+j)/2;
    return mul(read(s,e,i,mid,n*2), read(s,e,mid+1,j,n*2+1));
}

vector<mat> mats, mults, invs;

int main(){
    freopen("crypto.in","r",stdin);
    freopen("crypto.out", "w", stdout);

    int r,n,m,s,e;

    scanf("%d %d %d", &r, &n, &m);
    mod=r;

    N = 1;
    while(N<n) N<<=1;
    for(int i=0; i<2*N; i++){
        seg[i]=mat(1,0,0,1);
    }

    for(int i=0; i<n; i++){
        mat m1;
        scanf("%d%d%d%d", &m1.a, &m1.b, &m1.c, &m1.d);
        seg[N+i]=m1;
    }
    for(int i=N*2-2; i>=N; i-=2){
        int j=i/2;
        while(j>0){
            seg[j]=mul(seg[2*j], seg[2*j+1]);
            j/=2;
        }
    }

    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        mat res = read(s,e,1,N,1);
        printf("%d %d\n%d %d\n", res.a, res.b, res.c, res.d);
        if(i<m-1) printf("\n");
    }


    return 0;
}





