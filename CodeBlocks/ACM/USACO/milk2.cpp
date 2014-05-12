/*
ID: ahmadad1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

vector<ii> in, v;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int n, i,j,k, f, a, b, cur, maxon, maxoff;

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        in.push_back(ii(a,b));
    }
    sort(in.begin(), in.end());
    for(i=0; i<n; i++) {
        a=in[i].first, b=in[i].second;
        f=0;
        for(j=0; j<v.size(); j++){
            if(v[j].second>=a) { if(v[j].second<b) v[j].second=b; f=1; break; }
        }
        if(!f) v.push_back(ii(a,b));
    }
    sort(v.begin(), v.end());
    maxon=maxoff=0;
    for(i=0; i<v.size(); i++){
        maxon=max(maxon, v[i].second-v[i].first);
        if(i>0) maxoff=max(maxoff, v[i].first-v[i-1].second);
    }
    printf("%d %d\n", maxon, maxoff);
    return 0;
}
