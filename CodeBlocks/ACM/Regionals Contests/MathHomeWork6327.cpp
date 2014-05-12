#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll n, N;

long long mod(long long x){
    x%=MOD;
    if(x<0) x+=MOD;
    return x;
}

/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

long long powmod(long long a, long long b, int c){
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

ll inv(ll n){
    return powmod(n, MOD-2, MOD);
}

long long gcd(long long m, long long n){
    long long tmp;
    while(m>0){
        tmp = m;
        m = n%m;
        n = tmp;
    }
    return n;
}

ll lcm(ll n, ll m){
    return n*(m/gcd(n,m));
}
/*
ll div(int a){
    return mod(1+mulmod(inv(a),mod(n-(n%a)), MOD)-((n%a==0)?1:0));
}
*/
int div(int x){
    return mod(1 + mulmod((mod(powmod(10,N,MOD) - powmod(10,N,x))) , powmod(x,MOD-2,MOD),MOD) - ((powmod(10,N,x)==0)?1:0));
}

ll incexc(vector<int> v, int i, int left, int lcmt){
    if(left==0) return div(lcmt);
    if(i==v.size()) return 0;
    return (incexc(v, i+1, left, lcmt)+
           ((left>0)? incexc(v, i+1, left-1, lcm(lcmt, v[i])) :0)) % MOD;
}

char cond[10];

int main(){
    int t, i,j,k, lcm1, lcm2;
    ll sum;
    scanf("%d", &t);
    while(t--){
        scanf("%lld %s", &N, cond);
        n = mod(powmod(10, N, MOD));

        if(cond[0]=='0'){
            printf("0\n");
            continue;
        }

        lcm1=lcm2=1;
        vector<int> condnotdiv;
        for(i=1; i<6; i++){
            if(cond[i]=='1') lcm1=lcm(lcm1, i+1);
            else if(cond[i]=='0') condnotdiv.push_back(i+1), lcm2=lcm(lcm2, i+1);
        }
        sum=0;

        int i, sum=div(lcm1);
        //if(lcm2==1) sum++;
        //else if(lcm1==1) sum--;

        for(i=1; i<=condnotdiv.size(); i++){
            sum=mod(sum-mod(pow(-1, i+1)*incexc(condnotdiv, 0, i, lcm1)));
        }
        printf("%d\n", (int)sum);
    }
    return 0;
}

/*
4
2 222201
1 111001
1 111111
2 222222
*/
