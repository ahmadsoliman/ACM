#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

char s[10000];

int freq[50], totc;
vector<int> v;

#define INF 100000000

int dp[30][100][100];

int recur(int i, int bits, int filled){
    //printf("%d %d %d\n", i, bits, filled);

    if(i==v.size()) return 0;
    if(bits>8) return INF;

    if(dp[i][bits][filled]!=-1) return dp[i][bits][filled];

    if(filled==bits) {
        if(i==v.size()-1) return dp[i][bits][filled]=v[i]*bits;
        return dp[i][bits][filled]=recur(i, bits+1, filled);
    }

    int a=v[i]*bits+recur(i+1, bits, filled+1), b=recur(i, bits+1, filled), c=recur(i, bits+1, filled-1);

    return dp[i][bits][filled]=min(a,min(b,c));
}

int main(){
    int i,j,k, n, l, minc;
    while(scanf("%s", s)>0){
        if(strcmp(s, "END")==0) return 0;
        l = strlen(s);

        memset(freq, 0, sizeof freq);
        for(i=0; i<l; i++) freq[s[i]-'A']++;

        v.clear();
        totc=0;
        for(i=0; i<31; i++) if(freq[i]>0) totc+=freq[i]*8, v.push_back(freq[i]);

        sort(v.rbegin(), v.rend());

        memset(dp, -1, sizeof dp);
        minc = recur(0, 1, 0);

        printf("%d %d %.1lf\n", totc, minc, 1.0*totc/minc);
    }
    return 0;
}
