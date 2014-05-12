#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;

int n, k[105], c[105], ci[5005], cnt;

typedef pair<int, int> ii;

map<ii, int> dp;

int recur(int t, int diff){
    if(t==n) return abs(diff);

    ii state(t,diff);
    map<ii, int>::iterator it;
    if((it=dp.find(state))!=dp.end()) return it->second;

    int i, curdiff, mindiff=1000000;
    for(i=0; i<=k[t]; i++){
        curdiff=recur(t+1, diff+(i-(k[t]-i))*c[t]);
        if(curdiff<mindiff) mindiff=curdiff;
    }
    return dp[state]=mindiff;
}

int main(){
    int i,j;
    cnt=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d %d", &k[i], &c[i]);
        for(j=0; j<k[i]; j++) ci[cnt++]=c[i];
    }
    sort(ci, ci+cnt);
    printf("%d\n", recur(0));
    return 0;
}
