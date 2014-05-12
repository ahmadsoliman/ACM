#include <stdio.h>
#include <string.h>
#include <math.h>

int gcd(int m, int n){
    if(m==0) return n;
    return gcd(n%m, m);
}

int main(){
    int t, cv, i,j,k, s, d, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &cv);
        d=0;
        for(i=0; i<cv; i++) {
            s=0;
            for(j=0; j<9; j++){
                scanf("%d", &v);
                s+=v;
            }
            scanf("%d", &v);
            s-=v;
            d=gcd(d,s);
        }
        if(d==0 || d==1) printf("impossible\n");
        else printf("%d\n", d);
    }
    return 0;
}
/*
4
2
1 1 1 1 1 1 1 1 1 9
2 4 6 8 10 12 14 16 18 90
3
1 1 1 1 1 1 1 1 1 1
5 4 7 2 6 4 2 1 3 2
1 2 3 4 5 6 7 8 9 5
2
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0
2
2 2 2 2 2 2 2 2 2 0
1 1 1 1 1 1 1 1 1 1
*/
