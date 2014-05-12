#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 1e-9

int main(){
    int s, i,j, found, sqrts, twos;
    long long a,b, tmp;
    while(scanf("%d", &s)>0){
        if(s<0) return 0;
        found=0, sqrts=sqrt(s), twos=2*s;
        for(a=1; a<=sqrts; a++){
            for(b=2*sqrts; b>a; b--){
                tmp = (b*(b+1)-a*(a-1));
                if(tmp==twos){
                    found=1; break;
                }
            }
            if(found) break;
        }
        if(!found) printf("%d = %d + ... + %d\n", s, s, s);
        else printf("%d = %d + ... + %d\n", s, a, b);
    }
    return 0;
}
