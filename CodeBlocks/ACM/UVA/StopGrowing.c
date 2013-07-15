#include <stdio.h>

int main(){
    int t,kase=1,a,b,c,d,e,m,count,s,tmp;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d %d", &a,&b, &c,&d, &e, &m);
        count=0;
        while((s=a+b+c+d+e)<m){
            if(s<=0){
                count=-1;
                break;
            }
            tmp = a;
            a += b;
            b += c;
            c += d;
            d += e;
            e += tmp;
            count++;
        }
        printf("Case #%d: %d\n", kase++, count);
    }
    return 0;
}
