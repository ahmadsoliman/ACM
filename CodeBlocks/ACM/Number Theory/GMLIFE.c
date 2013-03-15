#include <stdio.h>
#include <math.h>

#define MAX (100000000000000ll)

long long modulo(long long x, long long m){
    while(x<0)x+=m;
    return x%m;
}

// calculates (a*b)%c taking into account that a*b might overflow
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

long long gcd(long long m, long long n){
    if(m==0)return n;
    return gcd(n%m, m);
}

long long lcm(long long m, long long n){
    return m*(n/gcd(m, n));
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

//Chinese Remainder Theorem , congruences[i][0] = ai & congruences[i][1] = ni
long long congruences[1005][2];
long long CRT(int len){
    //check all n are co-prime or ai=aj (mod gcd(ni, nj )) for all i; j.
    int i,j,gcdIJ;
    for (i = 0; i < len; i++) {
        for (j = i+1; j < len; j++) {
            gcdIJ = gcd(congruences[i][1], congruences[j][1]);
            if(modulo(congruences[i][0],gcdIJ)!=modulo(congruences[j][0], gcdIJ))return 0;
        }
    }

    //calculate a
    long long a=congruences[0][0], n=congruences[0][1], r, tmp[3], tmpN;

    for (i = 1; i < len; i++) {
        r = gcd(n, congruences[i][1]);

        eGCD(tmp, n, congruences[i][1]);
        tmpN=n;
        n = n*(congruences[i][1]/r);//lcm
        if(n<tmpN)n=MAX;
        a = modulo(a + modulo(((tmp[0]>=0)?1:-1)*mulmod(mulmod(modulo((congruences[i][0]-a)/r, n),((tmp[0]>=0)?tmp[0]:-1*tmp[0]) ,n),tmpN, n), n),n);
    }
    return modulo(a, n);
}

int main(){
    int n;
    long long ai, ni, i, j, X, sqrtX, pow, countDiv;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%lld %lld", &ai, &ni);
        congruences[i][0]=modulo(-ai, ni);
        congruences[i][1]=ni;
    }
    if(n>1){
        X = CRT(n);
    }else{
        X = congruences[0][0];
    }

    //check eligibility
    if(X==0){
        printf("0\n");
        return 0;
    }
    //printf("%lld\n", X);

    //factorise X
    countDiv=2ll;
    sqrtX = sqrtl(X);
    for(i=2; i<=sqrtX; i++){
        if(X%i==0){
            countDiv+=2;
            if(i==sqrtX)countDiv--;
        }
    }

    printf("%lld\n", countDiv);
    return 0;
}

