#include <stdio.h>


int gcd(int m, int n){
    if(m==0)return n;
    return gcd(n%m, m);
}

int main(){
    int a1,b1,c1,d1,a2,b2,c2,d2, k, d;
    while(scanf("%d %d %d %d %d %d %d %d", &a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2)>0){
        if(a1==0&&b1==0&&c1==0&&d1==0&&a2==0&&b2==0&&c2==0&&d2==0) return 0;
        if(a1==0&&a2==0) {
            if(c1==c2) printf("0 0\n");
            else{
                d=gcd(d2-d1, c1-c2);
                if(d2-d1!=0) printf("%d %d\n", (d2-d1)/d, (c1-c2)/d);
                else printf("0 1\n");
            }
        } else{
            if(a1==a2){
                if(a1==-a2) printf("0 0\n");
                else if((k=((b1+b2)*(c2-c1)-(a1+a2)*(d2-d1)))%(180*(a1+a2))==0 && k%2){
                    d=gcd(-b2-b1, a1+a2);
                    if(-b2-b1!=0) printf("%d %d\n", (-b2-b1)/d, (a1+a2)/d);
                    else printf("0 1\n");
                }
            }else{
                if(((b2-b1)*(c1-c2)-(a1-a2)*(d2-d1))%(360*(a1-a2))==0){
                    d=gcd(b2-b1, a1-a2);
                    if(b2!=b1) printf("%d %d\n", (b2-b1)/d, (a1-a2)/d);
                    else printf("0 1\n");
                } else if((k=((b1+b2)*(c2-c1)-(a1+a2)*(d2-d1)))%(180*(a1+a2))==0 && k%2){
                    d=gcd(-b2-b1, a1+a2);
                    if(-b2-b1!=0) printf("%d %d\n", (-b2-b1)/d, (a1+a2)/d);
                    else printf("0 1\n");
                } else printf("0 0\n");
            }
        }
    }
    return 0;
}
