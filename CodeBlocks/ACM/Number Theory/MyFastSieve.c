#define MAXSIEVE 100000000
#define MAXSIEVEHALF 50000000
#define MAXSQRT 5000

short a[50000000];
int primes[6000000];

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
    int i;
    for(i=0;i<26;i++) printf("%d, ", primes[i]);
}

