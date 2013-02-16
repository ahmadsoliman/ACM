#include <math.h>
#include <string.h>

#define MAXSIEVE 100000000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000

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

const int MAX = 1000000, LMT = 1000;
int flag[MAX>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve2() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2)
        if(!ifc(i))
            for(j = i*i, k = i<<1; j < MAX; j += k)
                isc(j);
}

//int primes[6000000];

int main(){
    //sieve();
    sieve2();
    //primes[0]=2;
    //int i,j=1;
    //for(i=3; i<MAXSIEVE; i+=2)if(isPrime(i))primes[j++]=i;


    int t,m,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        if(m<3){
            printf("2\n");
            m=3;
        }
        if(m%2==0)m++;
        for(;m<=n;m+=2){
            if(isPrime(m))printf("%d\n", m);
        }
        if(t>0)printf("\n");
    }
    return 0;
}
