#include <stdio.h>

long long modulo(long long x, long long m){
    while(x<0)x+=m;
    return x%m;
}

long long gcd(long long m, long long n){
    if(m==0)return n;
    return gcd(n%m, m);
}

//Extended Euclidean Algorithm
void eGCD(long long res[], long long m, long long n){
    if(m==0){
        res[0]=0;res[1]=1;res[2]=n;
        return;
    }
    long long tmp[3];
    eGCD(tmp, n%m, m);
    res[0]=tmp[1]-(n/m)*tmp[0]; res[1]=tmp[0];  res[2]=tmp[2];
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

        GCD_pairs[n-1]=a[n-1];
        for(i=n-2; i>=0; i--){
            GCD_pairs[i] = gcd(GCD_pairs[i+1], a[i]);
        }

        if(b%GCD_pairs[0]>0){
            printf("NO\n");
            continue;
        }
        flag = 1;
        for(i=1; i<=n; i++){
            GCD = gcd(GCD_pairs[i], m);

            long long res[3];
            eGCD(res, a[i-1], GCD);

            if(b%gcd(a[i-1], GCD_pairs[i])>0){
                printf("NO\n");
                flag = 0;
                break;
            }

            X = ((modulo(res[0],m)%m)*((b/res[2])%m))%m ;//+ (res[2]-1)*(GCD/res[2])
            sol[i-1] = X%m;

            b = modulo(b - (((a[i-1]%m)*(X%m))%m), m);
        }
        if(!flag)continue;

        printf("%d", sol[0]);
        for(i=1; i<n; i++){
            printf(" %d", sol[i]);
        }
        printf("\n");
    }
    return 0;
}

