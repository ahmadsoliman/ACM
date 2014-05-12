#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

char M[1100];
int Q, R, n, vis[1010][1100], kase;
string dp[1010][1100], e="", hsh="#";

string recur(int i, int rem){
    if(i==n){
        if(rem==R) return e;
        else return hsh;
    }
    if(vis[i][rem+1]==kase) return dp[i][rem+1];

    int dig=M[i]-'0', newrem=((rem==-1)?dig:(rem*10+dig));

    string a=recur(i+1, rem), b, res;

    if(rem==-1 && dig==0) b=recur(i+1, rem);
    else if(newrem>=Q) b=recur(i+1, newrem%Q);
    else b=recur(i+1, newrem);

    if(a==hsh&&b==hsh) res=hsh;
    else if(b==hsh) res=a;
    else{
        if(!(rem==-1&&dig==0)) b=M[i]+b;
        if(a==hsh) res=b;
        else{
            if(a.size()>b.size()) res=a;
            else if(a.size()<b.size()) res=b;
            else{
                res=a;
                for(int j=0; j<a.size(); j++){
                    if(a[j]>b[j]) { res=a; break; }
                    else if(a[j]<b[j]) { res=b; break; }
                }
            }
        }
    }
    vis[i][rem+1]=kase;
    return dp[i][rem+1]=res;
}

int main(){
    int t, i,j,k;
    kase=1;
    string res;
    scanf("%d", &t);
    while(t--){
        scanf("%s %d %d", M, &R, &Q);
        if(Q==1){
            printf("%s\n", M);
            kase++;
            continue;
        }
        n=strlen(M);
        res = recur(0, -1);
        if(res!=hsh) {
            printf("%s\n", res.c_str());
        }else printf("Not found\n");
        kase++;
    }
    return 0;
}
