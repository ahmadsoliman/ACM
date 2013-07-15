#include <stdio.h>
#include <string.h>

int recur(int r, int c){
    if(r==1||c==1) return 0;
    int k, sum=(r==c);
    for(k=1; k<r || k<c; k++) {
        if(r<=c){
            if(k<r)
                sum += recur(k, c) + recur(r-k, c);
            else
                sum += recur(r, k) + recur(r, c-k);
        }else{
            if(k<c)
                sum += recur(r, k) + recur(r, c-k);
            else
                sum += recur(k, c) + recur(r-k, c);
        }
    }
    return sum;
}

int main(){
    int n;
    while(scanf("%d", &n)>0){
        if(n==0) break;
        printf("%d\n", recur(n,n)+n*n);
    }
    return 0;
}
