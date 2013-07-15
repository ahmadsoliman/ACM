#include <stdio.h>

#define MAXSIEVE 10000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 50

char a[MAXSIEVE/16+2];
int primes[10000];
#define isPrime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

int fast_sieve(){
    int i, j;
    memset(a, 255, sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
        if(a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
    primes[0]=2;
    j=1;
    for(i=3; i<MAXSIEVE; i+=2)if(isPrime(i))primes[j++]=i;
    return j;
}

int dp[10005];

int binarySearch(int a[], int low, int high, int target) {
    while (low <= high) {
        int middle = low + (high - low)/2;
        if (target < a[middle]){
            if(target > a[middle-1])
                return middle-1;
            high = middle - 1;
        }else if (target > a[middle]){
            if(target < a[middle+1])
                return middle;
            low = middle + 1;
        }else
            return middle;
    }
    return -1;
}

int n;

int recur(int i){
    if(i==0) return 1;
    if(i==1) return 0;

    int index = binarySearch(primes, 0, n, i);
    if(index==-1){

    }

    while(index>=0){
        int tmp = index, cur = i;
        while(tmp>=0 && cur>primes[tmp])cur-=primes[tmp--];
        index--;
    }
}

int main(){
    n = fast_sieve();
    //recur(10000);
    int n;
    while(scanf("%d",&n)>0){
        if(n==0)
            break;

    }
    return 0;
}
