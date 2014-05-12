/*j ID: ahmadad1
PROG: runround
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
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int check(vi v){
    set<int> s;
    for(int i=0; i<v.size(); i++){
        if(v[i]==0) return 0;
        if(s.find(v[i])!=s.end()) return 0;
        s.insert(v[i]);
    }

    s.clear();
    int last=0;
    s.insert(last);

    while(s.size()<v.size()){
        last = (last+v[last])%v.size();
        if(s.find(v[last])!=s.end()) return 0;
        s.insert(v[last]);
    }
    last = (last+v[last])%v.size();
    return last==0;
}

vi value(long long val){
    vi v;
    while(val>0) v.push_back(val%10), val/=10;
    reverse(v.begin(), v.end());
    return v;
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    int i,j,k,r,l,q, n;
    long long val=0;

    scanf("%lld", &val);

    val++;
    for(; ; val++){
        if(check(value(val))){ printf("%lld\n", val); break; }
    }

    return 0;
}
