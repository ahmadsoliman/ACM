/*
ID: ahmadad1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int stalls[1000],c, dp[55][205];

int recur(int m, int i){
    if(i==c&&m>=0) return 0;
    if(m==0) return 1000000000;

    if(dp[m][i]!=-1) return dp[m][i];

    int minv=1000000000;
    for(int j=i; j<c; j++){
        minv=min(minv, stalls[j]-stalls[i]+1+recur(m-1, j+1));
    }
    return dp[m][i]=minv;
}

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int m,s, i,j,k;

    scanf("%d %d %d", &m, &s, &c);
    for(i=0; i<c; i++) scanf("%d", &stalls[i]);

    sort(stalls, stalls+c);

    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(m, 0));

    return 0;
}

