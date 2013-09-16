#include <stdio.h>

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m)>0){
        if(n==0) return 0;
        if(n==1) printf("1 knights may be placed on a 1 row %d column board.\n", m);
        else if(m==1) printf("1 knights may be placed on a %d row 1 column board.\n", n);
        else if(n==2) {
            printf("%d knights may be placed on a %d row %d column board.\n",  m / 4 * 4 + (m % 4 == 1? 2 : (m % 4 >= 2? 4 : 0)), n, m);
        }
        else if(m==2){
            printf("%d knights may be placed on a %d row %d column board.\n",  n / 4 * 4 + (n % 4 == 1? 2 : (n % 4 >= 2? 4 : 0)), n, m);
        }
        else printf("%d knights may be placed on a %d row %d column board.\n", ((n*m)+1)/2, n, m);
    }
    return 0;
}
