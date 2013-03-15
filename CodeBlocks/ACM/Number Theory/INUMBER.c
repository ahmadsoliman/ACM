#include <stdio.h>

int main(){
    int t,n,i,nines;
    char *res;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        nines=n;
        while(nines%n>0)nines--;
        res = "" + (n-nines);
        nines=nines/9;
        res +=
        res += "000"
    }
    return 0;
}
