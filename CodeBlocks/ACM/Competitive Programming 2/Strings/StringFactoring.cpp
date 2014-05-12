#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

typedef pair<int, int> ii;

int len, dp[100][100];
char in[100];
string s;
vector< vector<ii> > rep;

int recur(int a, int b){
    if(a>=b) return 0;
    if(a==b-1) return 1;

    if(dp[a][b]!=-1) return dp[a][b];

    int r=b-a, cur, minv=r;

    for(int i=r/2; i>0; i--){
        for(int j=0; j<rep[i].size(); j++){
            ii p=rep[i][j];
            if(p.first>=a && p.first+p.second<=b){
                cur = recur(a, p.first) + min(i, recur(p.first, p.first+i)) + recur(p.first+p.second, b);
                minv=min(minv, cur);
            }
        }
    }
    return dp[a][b]=minv;
}

int main(){
    int i,j,k;
    while(scanf("%s", in)>0){
        s=string(in);
        if(s=="*") return 0;

        len=s.size();
        rep = vector< vector<ii> >(len, vector<ii>());
        for(i=1; i<=len/2; i++){
            k=1;
            string cur;
            for(j=0; j+i<len; j++){
                cur = s.substr(j, i);
                k=j+i;
                while(j+i<len && cur==s.substr(k, i)) k+=i;
                if(k>j+i) rep[i].push_back(ii(j, k-j));
            }
        }

        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0, len));
    }
    return 0;
}
