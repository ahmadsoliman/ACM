#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <map>

using namespace std;

#define MAXSIEVE 31700
#define MAXSIEVEHALF 15850
#define MAXSQRT 90

short a[MAXSIEVEHALF];

long long primes[10000];

void sieve(){
    int i, j, k;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
}

long long gcd(long long m, long long n){
    if(m==0)return n;
    return gcd(n%m, m);
}

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

int compare (const void * a, const void * b)
{
  if ( *(long long*)a <  *(long long*)b ) return -1;
  if ( *(long long*)a == *(long long*)b ) return 0;
  if ( *(long long*)a >  *(long long*)b ) return 1;
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

long long factors[100], roots[10005];

int main(){
    long long n,k,a,p,e,phiP,tmpPhiP,phiN,rootPhiP,m,factNum,rootsNum, primitiveRoot, rootInv, Y, rootPow,mh, h, d, i,j,flag;

    scanf("%lld %lld %lld", &n, &k, &a);

    //calculate phi(n), n = p^e
    double tmpP;
    p = n; e = 1;
    for(i=31; i>1; i--){
        tmpP = powl(n, 1.0/i);
        if(fmodl(tmpP, 1)==0){
            p = tmpP;
            e = i;
            break;
        }
    }
    phiN = (p-1)*powl(p,e-1);
    phiP=p-1;

    if(p==3){
        primitiveRoot=2;
    }else{
        //factorize phiN
        factNum=0;
        rootPhiP=sqrtl(phiP);
        tmpPhiP=phiP;
        sieve();
        for(i=0; primes[i]<=rootPhiP && tmpPhiP>1; i++){
            if(tmpPhiP%primes[i]==0){
                factors[factNum++]=primes[i];
                while(tmpPhiP%primes[i])tmpPhiP/=primes[i];
            }
        }
        if(tmpPhiP>1){
            factors[factNum++]=primes[i];
        }

        //find a primitive root
        primitiveRoot=-1;
        while(1){
            i = rand()%p;
            flag=1;
            for(j=0; j<factNum; j++){
                if(powmod(i, phiP/factors[j], p)==1){
                    flag=0;
                    break;
                }
            }
            if(flag){
                primitiveRoot=i;
                if(e>1){
                    if(powmod(i, phiP, p*p)==1){
                        primitiveRoot=i+p;
                    }
                }
                break;
            }
        }
    }

    rootPow=primitiveRoot;
//find h
    h=1;
    /*while(1){
        if(rootPow==a)break;
        rootPow=(rootPow*primitiveRoot)%n;
        h++;
    }
    printf("%d\n", h);
    */

    mh = ceil(sqrtl(n));
    map<long long, long long> mymap;

    for(i=0; i<mh; i++){
        //add g^i, i to hash table
        mymap.insert(make_pair(powmod(primitiveRoot,i,n), i));
    }
    //g^-m
    rootInv = powmod(powmod(primitiveRoot, phiN-1, n), mh, n);
    //set Y = a
    Y = a;

    //step 5
    for(i=0; i<mh; i++){
        map<long long, long long>::iterator it = mymap.find(Y);
        if(it!=mymap.end()){
            h = i*mh + it->second;
            break;
        }else{
            Y = mulmod(Y, rootInv, n);
        }
    }
    //map<long long, long long>::iterator it = m.find();
    //it->second;

    //printf("%d\n", h);

    long long res[3];
    d = gcd(k, phiN);
    if(h%d!=0){
        printf("0\n");
        return 0;
    }
    eGCD(res, k, phiN);

    rootsNum=0;
    for(i=0; i<d; i++){
        roots[rootsNum++]=powmod(primitiveRoot, (mulmod(modulo(res[0],phiN),(h/d),phiN)+mulmod(i,(phiN/d),phiN))%phiN, n);
    }

    //printf("%d %d %lld %lld\n", primitiveRoot, h, res[0], res[2]);

    qsort(roots, rootsNum, sizeof(long long), compare);
    printf("%lld\n", rootsNum);
    for(j=0; j<rootsNum; j++){
        printf("%lld\n", roots[j]);
    }

    return 0;
}
