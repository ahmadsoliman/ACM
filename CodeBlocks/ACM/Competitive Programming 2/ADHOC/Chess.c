#include <stdio.h>
#include <math.h>

#define min(x,y) ((x<y)?x:y)
#define max(x,y) ((x>y)?x:y)

int main(){
    int t, n, m, res;
    char c[1];
    scanf("%d", &t);
    while(t--){
        scanf("%s %d %d", c, &n, &m);
        switch(c[0]){
            case 'r': case 'Q': res = min(n,m); break;
            case 'k': res = ((n*m)+1)/2; break;
            case 'K': res = ((n+1)/2)*((m+1)/2); break;
        }
        printf("%d\n", res);
    }
    return 0;
}
