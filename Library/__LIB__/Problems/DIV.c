#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 1000010
#define MAXSQRT 1001

short a[1000010];
int primes[78501];

int sieve(){
    int i, j, k;
    for(i=2,k=0;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i;
            for(j=2*i;j<MAXSIEVE;j+=i)
                a[j]=1;
        }
    for(; i<MAXSIEVE; i++)if(a[i]==0)primes[k++]=i;
    return k;
}

int main(){
    int i,j,k=sieve(), nine=0, n, sqrtN, c, cp, flag, tmp, last,sqrtL;

    for(i=50; i<999928; i++){
        if(a[i]==0) continue;

        //calc dN
        n=i;j=0;sqrtN=sqrt(n)+1;last=-1;flag=1;cp=0;
        while(n>1 && primes[j]<=sqrtN){
            c=1;
            while(n%primes[j]==0&&c++) n/=primes[j];
            if(c>1){
                cp++;
                if(last==-1){
                    if(a[c]==0) last=c;
                    else if(n>1) {flag=0; break;}
                    else last=c;
                }else{
                    if(n>1 || last==c || a[c]==1) {flag=0; break;}
                }
            }
            j++;
        }

        if(flag==0) continue;

        if(n>1){
            if(last==2) continue;
        }else {
            if(cp==1){
                flag=0;
                sqrtL = sqrt(last);
                for(j=0; primes[j]<=sqrtL; j++){
                    if(last%primes[j]==0){
                        tmp = last/primes[j];
                        if(primes[j]!=tmp && a[tmp]==0) flag=1;
                        break;
                    }
                }
            }
        }

        if(flag){
            if(nine==0)
                printf("%d\n", i);
            nine = (nine+1)%9;
        }
    }
    return 0;
}
