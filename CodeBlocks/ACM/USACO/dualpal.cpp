/*
ID: ahmadad1
PROG: dualpal
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

typedef vector<int> vi;

vi convert(int n, int b){
    vi r;
    while(n>0) r.push_back(n%b), n/=b;
    reverse(r.begin(), r.end());
    return r;
}

int isPalin(vi v){
    for(int i=0; i<v.size(); i++) if(v[i]!=v[v.size()-1-i]) return 0;
    return 1;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int n,s, i,j, c;

    scanf("%d %d", &n, &s);


    for(i=s+1; n; i++){
        c=0;
        for(j=2; j<11; j++) {
            if(isPalin(convert(i, j))) c++;
            if(c>1) break;
        }
        if(c>1) printf("%d\n", i), n--;
    }

    return 0;
}
