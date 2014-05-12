#include <stdio.h>
#include <string.h>

char s[10000010];

int main(){
    int t, i,j,k,d, b, sum, n, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %s", &d, &b, s);
        n = strlen(s);
        b--;
        sum=0;
        for(i=0; i<n; i++){
            sum=(sum+s[i]-'0');
        }
        printf("%d %d\n", kase++, sum%b);
    }
    return 0;
}
/*
5
1 10 7829
2 7 123456
3 6 432504023545112
4 8 37777777777777773
5 2 10110100010101010101101110001010001010101010101010111
*/
