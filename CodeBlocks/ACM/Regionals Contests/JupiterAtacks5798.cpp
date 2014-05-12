#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int P;

long long * tree;
long long MaxVal;

long long read(long long idx){
    long long sum = 0;
    while (idx > 0){
        sum = (sum+tree[idx]) % P;
        idx -= (idx & -idx);
    }
    return sum;
}
void update(long long idx ,long long val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long long val[100005];

long long mod(long long a){
    a%=P;
    if(a<0) a+=P;
    return a;
}

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

int main(){
    int B,L, N, i,j,k, a, b;
    char c[10];

    while(scanf("%d %d %d %d", &B, &P, &L, &N)>0){
        if(B==0 && P==0 && L==0 && N==0) return 0;
        MaxVal = L;
        tree = new long long[MaxVal+1];
        memset(tree, 0, sizeof(long long)*(MaxVal+1));

        val[1]=1;
        for(i=2; i<L+5; i++){
            val[i] = val[i-1]*B % P;
        }

        for(i=0; i<N; i++){
            scanf("%s %d %d", c, &a, &b);
            if(c[0]=='E'){
                update(a, mod(val[L-a+1]*b%P-(read(a)-read(a-1))));
            }else if(c[0]=='H'){
                printf("%d\n", mod(read(b)-read(a-1))*powmod(val[L-b+1], P-2, P)%P);
            }
        }
        printf("-\n");
    }
    return 0;
}
