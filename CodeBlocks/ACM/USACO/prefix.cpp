/*j ID: ahmadad1
PROG: prefix
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

vector<string> prims;
string s;

int dp[200005];

char in[100];

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    int i,j,k,r,l,q;

    while(scanf("%s", in)>0){
        if(strcmp(in, ".")==0) break;
        prims.push_back(in);
    }

    while(scanf("%s", in)>0){
        string x(in);
        s+=x;
    }

    memset(dp, 0, sizeof dp);

    int f, maxv=0;
    for(i=s.size()-1; i>=0; i--){
        maxv=0;
        for(j=0; j<prims.size(); j++){
            if(i+prims[j].size()>s.size()) continue;
            f=1;
            for(k=0; k<prims[j].size(); k++) if(prims[j][k]!=s[i+k]) { f=0; break; }
            if(f) maxv=max(maxv, k+dp[i+k]);
        }
        dp[i]=maxv;
    }

    printf("%d\n", dp[0]);

    return 0;
}
