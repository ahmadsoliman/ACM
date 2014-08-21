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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<int> failfn(string K) {
    vector<int> T(K.size() + 1, -1);
    for(int i = 1; i <= K.size(); i++){
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}
    return T;
}


vector<int> z;

char in[105];

string s1, s2, v;

int dp[105][105][105];

int recur(int i, int j, int k){
    if(k==v.size()) return dp[i][j][k] = -1000000000;
    if(i==s1.size()||j==s2.size()) return dp[i][j][k] = 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    dp[i][j][k]=0;

    if(s1[i]==s2[j]){
        int nk=k;
        while(nk!=-1 && s1[i]!=v[nk]){
            nk=z[nk];
        }
        dp[i][j][k] = 1+recur(i+1, j+1, nk+1);
    }
    dp[i][j][k] = max(dp[i][j][k], recur(i+1, j, k));
    dp[i][j][k] = max(dp[i][j][k], recur(i, j+1, k));
    return dp[i][j][k];
}

string res;

void recons(int i, int j, int k){
    if(i==s1.size()||j==s2.size()) return;

    int a=0, b = dp[i+1][j][k], c=dp[i][j+1][k];
    int nk=k;
    if(s1[i]==s2[j]){
        while(nk!=-1 && s1[i]!=v[nk]){
            nk=z[nk];
        }
        a=1+dp[i+1][j+1][nk+1];
    }
    int maxv= max(a,max(b,c));
    if(s1[i]==s2[j] && a==maxv){
        res+=s1[i];
        recons(i+1, j+1, nk+1);
    }else if(b==maxv){
        recons(i+1, j, k);
    }else if(c==maxv){
        recons(i, j+1, k);
    }
}

int main() {
    scanf("%s", in);
    s1 = in;
    scanf("%s", in);
    s2 = in;
    scanf("%s", in);
    v = in;

    memset(dp, -1, sizeof dp);
    z = failfn(v);

    recur(0,0,0);
    if(dp[0][0][0]==0){
        printf("0\n");
        return 0;
    }

    recons(0,0,0);

    printf("%s\n", res.c_str());

    return 0;

}
