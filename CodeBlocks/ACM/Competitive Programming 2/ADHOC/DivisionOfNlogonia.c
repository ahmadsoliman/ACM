#include <stdio.h>

int main(){
    int k, i, a, b, n, m;
    while(scanf("%d", &k)){
        if(k==0) return 0;
        scanf("%d %d", &n, &m);
        for(i=0; i<k; i++){
            scanf("%d %d", &a, &b);
            a-=n;
            b-=m;
            if(a==0||b==0) printf("divisa\n");
            else if(a<0 && b>0) printf("NO\n");
            else if(a>0 && b>0) printf("NE\n");
            else if(a>0 && b<0) printf("SE\n");
            else if(a<0 && b<0) printf("SO\n");
        }
    }
    return 0;
}
