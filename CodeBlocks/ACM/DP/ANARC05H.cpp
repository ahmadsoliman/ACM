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

char in[50];
string s;

//int dp[30][300][300];

int recur(int i, int last, int cur){
    if(i==s.size()){
        if(cur>=last) return 1;
        return 0;
    }
//    if(dp[i][last][cur]!=-1) return dp[i][last][cur];
    return recur(i+1, last, cur+s[i]-'0') + ((i>0&&cur>=last)?recur(i+1, cur, s[i]-'0'):0);
}

int main() {
    int kase=1;
    while(scanf("%s", in)>0){
        s=in;
        if(s=="bye") break;

        //memset(dp, -1, sizeof dp);
        printf("%d. %d\n", kase++, recur(0,0,0));
    }


    return 0;

}
