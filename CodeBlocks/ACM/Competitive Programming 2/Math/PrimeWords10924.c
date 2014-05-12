#include <stdio.h>
#include <string.h>
#include <math.h>

char in[100];

int main(){
    int n, len, i,j, prime;
    while(scanf("%s", in)>0){
        len = strlen(in);
        n=0;
        for(i=0; i<len; i++){
            if(in[i]>='a'&&in[i]<='z') n+= in[i]-'a'+1;
            else n+= in[i]-'A'+27;
        }
        prime=1; i=2;
        while(i*i<=n) { if(n%i==0) { prime=0; break; } i++; }
        if(prime) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
