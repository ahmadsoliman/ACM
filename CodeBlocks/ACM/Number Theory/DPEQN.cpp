#include <stdio.h>
using namespace std;

long long modulo(long long x, long long m){
    x%=m;
    if(x<0) x+=m;
    return x;
}

long long gcd(long long m, long long n){
    if(m==0)return n;
    return gcd(n%m, m);
}

long long egcd(long long a, long long b, long long &x, long long &y)
{
  if (a < b) return egcd(b, a, y, x);
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  long long x1, y1;
  long long g = egcd(b, a % b, x1, y1);
  x = y1;
  y = (x1 - a / b * y1);
  return g;
}

int a[105], GCD_pairs[105], sol[105];

int main(){
    int t, n, b, m, i, j, flag;
    long long GCD=-1, GCDT, X;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        scanf("%d %d", &b, &m);
        b%=m;

        GCD_pairs[n]=0;
        GCD_pairs[n-1]=a[n-1]%=m;
        for(i=n-2; i>=0; i--){
            GCD_pairs[i] = gcd(GCD_pairs[i+1], a[i]%=m);
        }

        if(b%GCD_pairs[0]!=0){
            printf("NO\n");
            continue;
        }
        flag = 1;
        for(i=0; i<n; i++){
            GCD = gcd(GCD_pairs[i+1], m);

            long long res0,res1,res2;
            res2 = egcd(a[i], GCD, res0, res1);

            if(b%res2!=0){
                printf("NO\n");
                flag = 0;
                break;
            }

            sol[i] = (modulo(res0,m)*((b/res2)%m))%m ;

            b = modulo(b - (a[i]*sol[i])%m, m);
        }
        if(flag==0)continue;

        printf("%d", sol[0]);
        for(i=1; i<n; i++){
            printf(" %d", sol[i]);
        }
        printf("\n");
    }
    return 0;
}
/*

3
2 4 6
8 10


*/
