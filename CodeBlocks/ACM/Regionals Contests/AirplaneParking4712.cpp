#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;


int n, dp[305][305][305];
vii ranges;

int recur(int i, int last, int maxlast) {
    if(i==n) return 0;

    if(last!=-1 && dp[i][last][maxlast]!=-1) return dp[i][last][maxlast];
    int a=recur(i+1, last, maxlast),b=0;
    if(last==-1 || (-1*ranges[i].second<=-1*ranges[last].second || ranges[i].first>=-1*ranges[maxlast].second ||
            (ranges[i].first>=-1*ranges[last].second && -1*ranges[i].second<=-1*ranges[maxlast].second)))
        b=1+recur(i+1, i, (maxlast==-1 || -1*ranges[i].second>=-1*ranges[maxlast].second)?i:maxlast);
    if(last!=-1) dp[i][last][maxlast]=max(a,b);
    return max(a,b);
}

int main() {
    int t, i,j,k, a,b;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ranges=vii(n);
        for(i=0; i<n; i++){
            scanf("%d %d", &a, &b);
            ranges[i]=ii(a,-1*b);
        }
        sort(ranges.begin(), ranges.end());
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0,-1, -1));
    }

    return 0;
}
