#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>

#define INF 100000000
#define min(x,y) ((x<y)?x:y)

using namespace std;

set<string> vis;

int recur(string s){
    if(s=="ABCDEF#") return 0;
    vis.insert(s);
    int ecell = s.find("#");
    string s1, s2, s3;
    int r1=INF,r2=INF,r3=INF;
    if(ecell==1){

    }else if(ecell==4){

    }else if(ecell==6){

    }else{
        s1=s.substr(0, ecell)+s[(ecell+1)%6]+"#"+s.substr((ecell+2)%6);
        s2=s.substr(0, ecell-1)+"#"+
    }
}

int main(){
    int t, kase=1, i,j;
    char in[10];
    string state;
    scanf("%d", &t);
    while(t--){
        scanf("%d %s", &i, in);
        state = string(in)+"#";

    }
    return 0;
}
