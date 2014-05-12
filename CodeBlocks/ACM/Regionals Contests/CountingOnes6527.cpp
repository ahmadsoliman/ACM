#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

ll dp[100], cumm[100];

ll recur(ll a, ll b){
    //printf("%lld %lld\n", a, b);
    if(a<0||b<=0) return 0;
    if(a>=b){
        if(a==b){
            ll sum=0;
            while(a>0) sum+=a%2, a/=2;
            return sum;
        }
        return 0;
    }
    ll minp=ceil(log(a)/log(2)-1e-5), maxp=floor(log(b)/log(2)+1e-5);
    /*ll minp=0, maxp=0, tmpa=1, tmpb=1;
    while(tmpa<a) minp++, tmpa<<=1;
//if(a==0) minp=1;
    while(tmpb<=b) maxp++, tmpb<<=1;
    maxp--;*/

//printf("%d %d, %d %d\n", a, b, minp, maxp);

    ll min2=pow(2,minp), max2=pow(2,maxp);
//printf("%d\n", cumm[maxp]-((minp>0)?cumm[minp]:0));
    ll sum=cumm[maxp]-((minp>0)?cumm[minp]:0)+min2-a+recur(max(a-min2/2, 1ll), min2-1-min2/2)+b-max2+1+recur(1, b-max2);

    return sum;
}
/*
0 1
0 1, 0 0
1
0 5
0 5, 0 2
0 1, 0 0
7
0 -1
0
0 11
0 11, 0 3
0 3, 0 1
0 1, 0 0
20




*/

int main(){
    int i,j,k;
    ll a,b, pow2;

    dp[0]=0; cumm[0]=0;
    dp[1]=1; cumm[1]=1;
    dp[2]=3; cumm[2]=4;
    pow2=4;
    for(i=3; i<60; i++) dp[i]=dp[i-1]+cumm[i-2]+pow2, pow2<<=1, cumm[i]=cumm[i-1]+dp[i];
   // for(i=3; i<10; i++) printf("%d\n", dp[i]);

    while(scanf("%lld %lld", &a, &b)>0){
        printf("%lld\n", recur(a,b));
    }
    return 0;
}
