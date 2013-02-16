#include <stdio.h>
#define MOD (1000000007)

long long modulo(long long x, int m){
    while(x<0)x+=m;
    return x%m;
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

int countDiv(long long n, int x){
    return modulo(1 + mulmod((modulo(powmod(10,n,MOD) - powmod(10,n,x),MOD)) , powmod(x,MOD-2,MOD),MOD) - ((powmod(10,n,x)==0)?1:0) ,MOD);
}

int gcd(int m, int n){
    if(m==0)return n;
    return gcd(n%m, m);
}

int lcm(int m, int n){
    return (m*n)/gcd(m, n);
}

int cond[7];

int main(){
    int t,tNum, conditions, i, j, k,i1,i2,l, lcmT, lcmP, X, Y;
    long long N;
    scanf("%d", &t);
    while(t--){
        scanf("%I64d %d", &N, &conditions);
        for(i=6; i>0; i--,conditions/=10)cond[i]=conditions%10;
        if(cond[1]==0){
            printf("0\n");
            continue;
        }
        lcmT=1;lcmP=1;l=0;
        for(i=2; i<7; i++){
            if(cond[i]==1)lcmT=lcm(lcmT, i);
            if(cond[i]==0&&++l)lcmP=lcm(lcmP, i);
        }
        X = countDiv(N, lcmT);

        Y=0;
        for(i=2; i<7; i++){
            if(cond[i]==0) {
                Y=modulo(Y+countDiv(N, lcm(lcmT, i)) ,MOD);
            }
        }
        if(l<2){
            printf("%d\n", modulo(X-Y, MOD));
            continue;
        }
        for(i=2; i<7; i++){
            if(cond[i]==0){
                for(j=i+1; j<7; j++){
                    if(cond[j]==0){
                        Y=modulo(Y-countDiv(N, lcm(lcm(lcmT, i), lcm(lcmT, j))), MOD);
                    }
                }
            }
        }
        if(l<3){
            printf("%d\n", modulo(X-Y, MOD));
            continue;
        }
        for(i=2; i<7; i++){
            if(cond[i]==0){
                for(j=i+1; j<7; j++){
                    if(cond[j]==0){
                        for(k=j+1; k<7; k++){
                            if(cond[k]==0){
                                Y=modulo(Y+countDiv(N, lcm(lcm(lcm(lcmT, i), lcm(lcmT, j)),lcm(lcmT, k))), MOD);
                            }
                        }
                    }
                }
            }
        }
        if(l<4){
            printf("%d\n", modulo(X-Y, MOD));
            continue;
        }
        for(i=2; i<7; i++){
            if(cond[i]==0){
                for(j=i+1; j<7; j++){
                    if(cond[j]==0){
                        for(k=j+1; k<7; k++){
                            if(cond[k]==0){
                                for(i1=k+1; i1<7; i1++){
                                    if(cond[i1]==0){
                                        Y=modulo(Y-countDiv(N, lcm(lcm(lcm(lcm(lcmT, i), lcm(lcmT, j)),lcm(lcmT, k)), lcm(lcmT,i1))), MOD);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(l<5){
            printf("%d\n", modulo(X-Y, MOD));
            continue;
        }
        if(cond[2]==0){
            if(cond[3]==0){
                if(cond[4]==0){
                    if(cond[5]==0){
                        if(cond[6]==0){
                            Y=modulo(Y+countDiv(N, 60) , MOD);
                        }
                    }
                }
            }
        }
        printf("%d\n", modulo(X-Y, MOD));
    }
    return 0;
}
