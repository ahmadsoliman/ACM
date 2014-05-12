#include <stdio.h>
#include <string.h>

typedef long long ll;

using namespace std;

int n, done, f;
ll dp[22][1050000];

ll recur(int last, int bm){
    if(bm==done) return 1;
    if(last>-1 && dp[last][bm]!=-1) return dp[last][bm];
    int i, cnt, even=0; ll sum=0;

    for(i=0, cnt=0; i<n; i++) if(bm&(1<<i)) cnt++;
    if(cnt%2==0) even=1;
    even=even&&!f;

    for(i=0; i<n; i++){
        if(!(bm&(1<<i)) && ((even && i>last)||(!even&&i<last))) sum+=recur(i, bm|(1<<i));
    }
    if(last>-1) dp[last][bm]=sum;
    return sum;
}

ll ans[22]={0, 1,2,4,10,32,122,544,2770,15872,101042,707584,5405530,44736512,398721962,3807514624,
            38783024290,419730685952,4809759350882,58177770225664,740742376475050};

int main(){
    int t, d, i=1, kase=1;
    ll sum;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &d, &n);
        /*n=i;
        done = (1<<n)-1;
        memset(dp, -1, sizeof dp);
        f=0;
        sum=recur(-1, 0);
        f=1;
        if(n>1)sum+=+recur(n, 0);
        */
        printf("%d %lld\n", kase++, ans[n]);
    }
    return 0;
}
