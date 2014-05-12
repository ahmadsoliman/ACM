/*
ID: ahmadad1
PROG: ariprog
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

typedef vector<int> vi;
typedef pair<int, int> ii;

int isBiSquare[130000];

int pre2(int m){
    int maxm=0,v;
    memset(isBiSquare, 0, sizeof isBiSquare);
    for(int i=0; i<=m; i++){
        for(int j=0; j<=m; j++){
            v=i*i+j*j;
            if(v>=130000) break;
            isBiSquare[v]=1;
            maxm=max(maxm, v);
        }
    }
    return maxm;
}

set<ii> sol;

void check(int a, int b, int n, int m){
    int c=a;
    for(int i=0; i<n; i++){
        if(c>=130000) return;
        if(!isBiSquare[c]) return;
        c+=b;
    }
    //printf("%d %d\n", a, b);
    sol.insert(ii(b,a));
}


int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    int n,m, i,j,k, f, a,b, maxm;

    scanf("%d %d", &n, &m);

    maxm=pre2(m);

    for(a=0; a<=m*m; a++){
        for(b=1; b<=m*m; b++){
            if(a+b*(n-1)>maxm) break;
            check(a,b, n, m);
        }
    }
    if(sol.size()==0){
        printf("NONE\n");
        return 0;
    }

    for(set<ii>::iterator it=sol.begin(); it!=sol.end(); it++){
        printf("%d %d\n", (*it).second, (*it).first);
    }
    return 0;
}
