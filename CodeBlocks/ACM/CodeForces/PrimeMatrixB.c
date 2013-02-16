#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXSIEVE 100000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 160

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

int calcMov(int x){
    if(x==0)return 2;
    if(x==1)return 1;
    if(x==2)return 0;
    int i=x;
    if(i%2==0)i++;
    while(1){
        if(i==2 || isPrime(i))return i-x;
        i+=2;
    }
}

int matrix[505][505];

int main(){
    sieve();

    int n,m,i,j,curMov, minMov;

    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    minMov=2000000000;
    for(i=0; i<n; i++){
        curMov=0;
        for(j=0; j<m; j++){
            if(!(matrix[i][j]==2 || (matrix[i][j]%2 && isPrime(matrix[i][j])))){//not prime
                curMov+=calcMov(matrix[i][j]);
            }
        }
        if(curMov<minMov)minMov=curMov;
    }

    for(j=0; j<m; j++){
        curMov=0;
        for(i=0; i<n; i++){
            if(!(matrix[i][j]==2 || (matrix[i][j]%2 && isPrime(matrix[i][j])))){//not prime
                curMov+=calcMov(matrix[i][j]);
            }
        }
        if(curMov<minMov)minMov=curMov;
    }
    printf("%d\n", minMov);

    return 0;
}
