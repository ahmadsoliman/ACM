#include <stdio.h>
#include <string.h>

#define MAXSIEVE 1000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 16

char a[MAXSIEVE/16+2];
#define isPrime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

void sieve(){
    int i, j;
    memset(a, 255, sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
        if(a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
}

int primes[168];
int main(){
    sieve();
    primes[0]=2;
    int i,j=1;
    for(i=3; i<MAXSIEVE; i+=2)if(isPrime(i))primes[j++]=i;

    int A,B,divA,divB,powA,powB,countN,distance,caseNum=1;;
    while(scanf("%d %d", &A, &B)>0){
        if(A==0)break;
        countN=0;distance=0;
        for(i=0; i<j; i++){
            if(A==1&&B==1)break;
            divA=A%primes[i];
            divB=B%primes[i];
            if(divA==0||divB==0)countN++;
            powA=0;powB=0;
            if(divA==0)while(A%primes[i]==0&&++powA)A/=primes[i];
            if(divB==0)while(B%primes[i]==0&&++powB)B/=primes[i];
            distance+=abs(powA-powB);
        }
        if(A>1&&A==B)countN++;
        else{
            if(A>1){
                distance++;
                countN++;
            }
            if(B>1){
                distance++;
                countN++;
            }
        }
        printf("%d. %d:%d\n", caseNum++, countN, distance);
    }
    return 0;
}
