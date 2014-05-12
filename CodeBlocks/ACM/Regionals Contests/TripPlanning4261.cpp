#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<long long, int> ii;

int n, a[1005];

ii dp[1005][1005];

ii recur(int i, int last){
    if(i==n-1) return dp[i][last]=ii(pow(a[i]-a[last]-100, 2),1);

    if(dp[i][last].first!=-1) return dp[i][last];

    ii ao=recur(i+1, last), bo=recur(i+1, i);
    bo.first+=(long long)pow(a[i]-a[last]-100, 2);
    bo.second++;
    if(ao.first<bo.first) return dp[i][last]=ao;
    if(ao.first>bo.first) return dp[i][last]=bo;
    if(ao.second<=bo.second) return dp[i][last]=ao;
    return dp[i][last]=bo;
}

vector<int> res;

void rec(int i, int last){
    if(i==n-1) {
        res.push_back(i);
        return;
    }

    ii ao=dp[i+1][last], bo=dp[i+1][i];
    bo.first+=(long long)pow(a[i]-a[last]-100, 2);
    bo.second++;

    if(ao.first<bo.first) { rec(i+1, last); return; }
    if(ao.first>bo.first) { res.push_back(i), rec(i+1, i); return; }
    if(ao.second<=bo.second) { rec(i+1, last); return; }
    res.push_back(i), rec(i+1, i);
}

int main(){
    int i,j,k, entered=0;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        if(entered) printf("\n");
        else entered=1;
        n++;
        a[0]=0;
        for(i=1; i<n; i++) scanf("%d", &a[i]), a[i]+=a[i-1];

        for(i=0; i<n; i++) for(j=0; j<n; j++) dp[i][j]=ii(-1,-1);
        printf("p=%lld\n", recur(1,0).first);
        res.clear();
        res.push_back(0);
        rec(1, 0);
        j=0;
        for(i=0; i<res.size(); i++){
            printf(" %d", res[i]);
            j++;
            if(j==30) printf("\n"), j=0;
        }
        if(j!=0) printf("\n");
    }
    return 0;
}
