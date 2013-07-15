#include <stdio.h>

int main(){
    int n, c, cur;
    while(scanf("%d", &n)>0){
        c = 1;
        cur = 0;
        while(cur = (cur*10+1)%n) c++;
        printf("%d\n", c);
    }
    return 0;
}
