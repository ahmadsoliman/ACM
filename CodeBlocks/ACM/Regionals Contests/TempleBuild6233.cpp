#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int maxh,b1,b2, bh[5];
unsigned long long dp[1000050];
long double tana;

unsigned long long gen(){
    unsigned long long maxv=0, cur, cnt;
    long double nb;
    int nh;

    dp[maxh]=0;
    for(int h=maxh-1; h>=0; h--){
        dp[h]=0;
        for(int i=0; i<3; i++){
            nh = h+bh[i];
            if(nh>maxh) continue;
            nb=b1-2*nh/tana;
            cnt = (unsigned long long)(nb/bh[i]+1e-9);
            cur = cnt*cnt*bh[i]*bh[i]*bh[i] + dp[nh];
            dp[h] = max(dp[h], cur);
        }
    }
    return dp[0];
}

int main(){
    int i,j,k;
    while(scanf("%d %d %d %d %d %d", &maxh, &b1, &b2, &bh[0], &bh[1], &bh[2])>0){
        tana = (long double)maxh/((b1-b2)/2.0);
        printf("%llu\n", gen());
    }
    return 0;
}
