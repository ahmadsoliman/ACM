#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <set>

using namespace std;

char in[1005];
string s, fs, ns;

int dp[300][300];

int palin(int i, int j){
    if(i>=j) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==s[j]) return dp[i][j]=palin(i+1, j-1);
    return dp[i][j]=0;
}

set<string> myset;
set<string>::iterator it, jt;

int main(){
    int i,j,k, f;
    while(scanf("%s", in)>0){
        s=string(in);
        memset(dp, -1, sizeof dp);
        f=0;
        myset.clear();
        for(i=3; i<=s.size(); i++){
            for(j=0; j+i<=s.size(); j++){
                if(palin(j, j+i-1)) myset.insert(s.substr(j, i));
            }
        }
        for(it=myset.begin(); it!=myset.end(); it++){
            for(jt=it; jt!=myset.end(); jt++){
                if(it->find(*jt)==-1 && jt->find(*it)==-1){
                    f=1; break;
                }
            }
            if(f) break;
        }
        if(f) printf("%s\n", in);
    }
    return 0;
}
