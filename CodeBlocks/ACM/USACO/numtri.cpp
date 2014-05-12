/*
ID: ahmadad1
PROG: numtri
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
#include <set>
#include <math.h>

using namespace std;

int n, arr[1005][1005], dp[1005][1005];

int recur(int i, int j){
    if(i==n-1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int a=0,b=0;
    a=arr[i+1][j]+recur(i+1, j);
    if(j<i+1) b=arr[i+1][j+1]+recur(i+1, j+1);

    return dp[i][j]=max(a, b);
}

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    int i,j,k;

    scanf("%d", &n);

    memset(arr, 0, sizeof arr);
    for(i=0; i<n; i++) for(j=0; j<=i; j++) scanf("%d", &arr[i][j]);

    memset(dp, -1, sizeof dp);
    printf("%d\n", arr[0][0]+recur(0,0));

    return 0;
}
