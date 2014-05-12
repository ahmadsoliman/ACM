/*j ID: ahmadad1
PROG: zerosum
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

int n;
vector<string> res;

void recur(string s, int i, long long val){
    if(i==n) {
        if(val==0) res.push_back(s);
        return;
    }
    string s1 = s+"+", s2=s+"-";
    long long curv=0;
    for(int j=i; j<n; j++){
        curv = curv*10 + (j+1);
        s1 += (char)('1'+j);
        s2 += (char)('1'+j);
        recur(s1, j+1, val+curv);
        recur(s2, j+1, val-curv);
        s1+=" ";
        s2+=" ";
    }
}

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    int i,j,k;

    scanf("%d", &n);

    string s1 = "";
    long long curv=0;
    for(int j=0; j<n; j++){
        curv = curv*10 + (j+1);
        s1 += (char)('1'+j);
        recur(s1, j+1, curv);
        s1+=" ";
    }


    sort(res.begin(), res.end());

    for(i=0; i<res.size(); i++) printf("%s\n", res[i].c_str());

    return 0;
}
