#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
    int t,d, kase=1, i,j,k, l, halfl, cnt, rem, lo, hi, mid, lowrange, upperrange;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &d, &l);
        cnt=0;
        halfl=l/3.0;

        for(i=1; i<=halfl; i++){
            rem=l-i;

            lo=i-1, hi=(rem+1)/2+1;

            while(lo+1<hi){
                mid=(lo+hi)/2;

                if(i+mid>rem-mid) hi = mid;
                else lo = mid;
            }
            lowrange=mid;

            lo=i-1, hi=(rem+1)/2+1;
            while(lo+1<hi){
                mid=(lo+hi)/2;

                if(i+mid<=rem-mid) hi = mid;
                else lo = mid;
            }
            upperrange=mid;
            printf("%d %d %d\n", i, lowrange, rem-lowrange);
            printf("%d %d %d\n", i, upperrange, rem-upperrange);
            if(lowrange<=rem-lowrange && i+lowrange>rem-lowrange){
                cnt+=2;
                if(i==lowrange || lowrange==rem-lowrange) cnt--;

            }
            if(upperrange>lowrange){
                if(upperrange<=rem-upperrange && i+upperrange>rem-upperrange){
                    cnt+=2;
                    if(i==upperrange || upperrange==rem-upperrange) cnt--;
                    upperrange--, lowrange++;
                    cnt+=2*(upperrange-lowrange+1);
                }
            }
        }

        printf("%d\n", cnt);
    }
    return 0;
}
