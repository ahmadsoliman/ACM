#include <stdio.h>
#include <math.h>
#include <string.h>

void eGCD(long long res[], long long m, long long n){
    if(m==0){
        res[0]=0;res[1]=1;res[2]=n;
        return ;
    }
    long long tmp[3];
    eGCD(tmp, n%m, m);
    res[0]=tmp[1]-(n/m)*tmp[0];res[1]=tmp[0];res[2]=tmp[2];
}

int main(){
    int i,j;
    long dx, dy, a,b,c, res[3];
    while(scanf("%lld %lld %lld", &a, &b, &c)>0){
        if(a==0&&b==0&c==0) return 0;
        eGCD(res, a, b);
        if(c%res[2]==0){
            dx=b; dy=a;
            a=res[0]*(c/res[2]); b=res[1]*(c/res[2]);

            /*while(b>0 && dy>0) { a+=dx; b-=dy; }*/
            if(b>0 && dy>0){
                a+=dx*(b/dy);
                b%=dy;
            }
            /*while(a>0 && dx>0) { a-=dx; b+=dy; }*/
            if(a>0 && dx>0){
                b+=dy*(a/dx);
                a%=dx;
            }

            /*while(b<0 && dy>0) { a-=dx; b+=dy; }*/
            if(b<0 && dy>0){
                a+=dx*(b/dy+1);
                b=(b%dy)+dy;
            }

            /*while(a<0 && dx>0) { a+=dx; b-=dy; }*/
            if(a<0 && dx>0){
                b+=dy*(a/dx+1);
                a=(a%dx)+dx;
            }

            if(a*dy+b*dx!=c) {
                printf("Unquibable!\n");
                continue;
            }

            if(a==1&&b==1)
                printf("%lld foom and %lld foob for a twob!\n", a, b);
            else if(a==1)
                printf("%lld foom and %lld foobs for a twob!\n", a, b);
            else if(b==1)
                printf("%lld fooms and %lld foob for a twob!\n", a, b);
            else
                printf("%lld fooms and %lld foobs for a twob!\n", a, b);
        }else printf("Unquibable!\n");
    }
    return 0;
}
