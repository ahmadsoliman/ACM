#include <stdio.h>

int main(){
    int t, a, b, c, kase=1, res;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &a, &b, &c);
        res=0;
        if((a>b&&b>c)||(c>b&&b>a)) res = b;
        if((b>a&&a>c)||(c>a&&a>b)) res = a;
        if((b>c&&c>a)||(a>c&&c>b)) res = c;
        printf("Case %d: %d\n", kase++, res);
    }
    return 0;
}
