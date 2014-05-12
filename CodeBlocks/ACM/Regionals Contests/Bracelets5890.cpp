#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

char in1[1550], in2[1550];
int len1, len2, dp[1550][1550], vis[1550][1550], kase=1;
string s1, s2, s3;

int recur(int i, int j){
    if(i==s1.size()||j==s2.size()) return 0;

    if(vis[i][j]==kase) return dp[i][j];

    int a=0,b=recur(i+1,j),c=recur(i,j+1);
    if(s1[i]==s2[j]) a = 1+recur(i+1, j+1);

    vis[i][j]=kase;
    return dp[i][j]=max(a, max(b,c));
}

int main(){
    int i,j,k, maxv;
    while(scanf("%s %s", in1, in2)>0){
        s1=string(in1), s2=string(in2);
        len1=s1.size(), len2=s2.size();

        maxv=0;
        s2+=s2;
        for(i=0; i<s1.size(); i++) for(j=0; j<s2.size(); j++) dp[i][j]=-1;
        maxv=max(maxv, recur(0, 0));


        s3=s2;
        for(i=0; i<s2.size(); i++){
            s2[i]=s3[s2.size()-i-1];
        }
        s3=s2;

        for(i=0; i<s1.size(); i++) for(j=0; j<s2.size(); j++) dp[i][j]=-1;
        maxv=max(maxv, recur(0, 0));

        printf("%d\n", maxv*2);
    }
    return 0;
}
