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

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char in[10000];

set<string> insig;
string word;
vector<string> phrase;

vector<vector<vector<vector<int> > > > dp;

// w index, jth word in phrase, kth letther in jth word
int recur(int i, int j, int k, int taken){
    if(i==word.size()) {
        if(j==phrase.size()-1 && taken) return 1;
        return 0;
    }
    if(j==phrase.size()) return 0;
    if(k==phrase[j].size()) {
        if(taken) return recur(i, j+1, 0, 0);
        return 0;
    }
    if(dp[i][j][k][taken]!=-1) return dp[i][j][k][taken];
    int sum = recur(i, j, k+1, taken);
    if(word[i]-'A'==phrase[j][k]-'a') sum+=recur(i+1,j,k+1,1);
    return dp[i][j][k][taken]=sum;
}

int main() {
    int n, maxv;

    while(scanf("%d", &n)>0){
        if(n==0) break;
        insig.clear();
        for(int i=0; i<n; i++) scanf("%s", in), insig.insert(in);
        scanf("%s", in);
        while(1){
            if(string(in)=="LAST") { scanf("%s", in); break; }
            word=in;
            phrase.clear();
            maxv=0;
            while(scanf("%s", in)>0){
                if(in[0]>='A'&&in[0]<='Z') break;
                if(insig.find(in)==insig.end()) phrase.pb(in), maxv=max(maxv, (int)phrase.back().size());
            }
            dp = vector<vector<vector<vector<int> > > >(word.size(), vector<vector<vector<int> > >(phrase.size(), vector<vector<int> >(maxv+1, vector<int>(2,-1))));
            int res = recur(0, 0, 0, 0);
            if(res==0) printf("%s is not a valid abbreviation\n", word.c_str());
            else printf("%s can be formed in %d ways\n", word.c_str(), res);
        }
    }

    return 0;

}
