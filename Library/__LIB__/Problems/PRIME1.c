#include<stdio.h>
#include<math.h>

#define MAXSIEVE 32000
#define MAXSIEVEHALF 16000
#define MAXSQRT 90

short a[50000000];

int primes[20000];

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

int main(){
    sieve();
    unsigned int t,m,n,s,i,temp,flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        if(m==1)
            m++;
        for(;m<=n;m++){
            flag=0;
            temp=sqrt(m);
            for(i=0;primes[i]<=temp;i++){
                if(m%primes[i]==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                printf("%u\n",m);
        }
    }
    return 0;
}
