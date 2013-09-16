#include <stdio.h>

int main(){
    int months, ndep, curdep, lastdep, i,j, ans;
    double downpay, downpay1, loan, car, depval, lastdepval;
    while(scanf("%d %lf %lf %d", &months, &downpay1, &loan, &ndep)>0){
        if(months<0) return 0;
        ans=-1;
        lastdep=0;
        scanf("%d %lf", &curdep, &lastdepval);
        car = (1.0-lastdepval)*(loan+downpay1);
        if(loan<car) ans=0;
        downpay = loan/months;

        for(i=1; i<ndep; i++){

            scanf("%d %lf", &curdep, &depval);
            while(ans==-1 && lastdep<curdep-1){
                car = (1.0-lastdepval)*car;
                loan-=downpay;
                lastdep++;
                if(ans==-1 && loan<car) ans=lastdep;
            }
            lastdepval = depval;
            lastdep=curdep;
            car = (1.0-lastdepval)*car;
            loan-=downpay;
            if(ans==-1 && loan<car) ans=lastdep;
        }
        while(ans==-1){
            car = (1.0-lastdepval)*car;
            loan-=downpay;
            lastdep++;
            if(ans==-1 && loan<car) ans=lastdep;
        }
        if(ans==1)printf("1 month\n");
        else printf("%d months\n", ans);
    }
    return 0;
}
