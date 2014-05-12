/*
ID: ahmadad1
PROG: milk
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

vii farmers;

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int n, m, i,j, a,b;
    long long p;

    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++) scanf("%d %d", &a, &b), farmers.push_back(ii(a,b));

    sort(farmers.begin(), farmers.end());

    p=0;
    for(i=0; n>0; i++){
        if(n>=farmers[i].second){
            n-=farmers[i].second;
            p+=farmers[i].first*farmers[i].second;
        }else{
            p+=farmers[i].first*n;
            n=0;
        }
    }
    printf("%lld\n", p);
    return 0;
}

