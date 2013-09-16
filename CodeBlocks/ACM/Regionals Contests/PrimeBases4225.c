#include <stdio.h>

int main(){
    int k,n,i,j,cumm[10]={2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870}, c[10], d, l;
    char *out[10]={"2","2*3", "2*3*5", "2*3*5*7", "2*3*5*7*11", "2*3*5*7*11*13", "2*3*5*7*11*13*17", "2*3*5*7*11*13*17*19", "2*3*5*7*11*13*17*19*23"};

    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        if(n==1){
            printf("1 = 1\n");
            continue;
        }
        k=n;
        l=0;

        for(i=8; i>=0; i--){
            d = n/cumm[i];
            if(d==0) { c[i]=0; continue; }
            c[i]=d;
            n-=d*cumm[i];
            l++;
        }
        printf("%d = ", k);
        if(n>0) printf("%d + ", n);
        for(i=0; i<9; i++){
            if(c[i]>0){
                printf("%d*%s", c[i], out[i]);
                l--;
                if(l>0) printf(" + ");
            }
        }
        printf("\n");
    }
    return 0;
}
