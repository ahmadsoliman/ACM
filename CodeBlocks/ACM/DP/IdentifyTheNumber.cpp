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
typedef pair<string, ii> state;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char in[110000];
string N;
int kase,n,R, Q, dp[1010][1010], dp2[1010][1010], vis[1010][1010];

int recur(int i, int r){
    if(vis[i][r+1]==kase) return dp[i][r+1];
    vis[i][r+1]=kase;
    if(i==n){
        if(r==R) return dp[i][r+1]=0;
        return dp[i][r+1]=-1000000000;
    }
    int a=recur(i+1, r), b = -1;
    if(N[i]-'0'>0 || r>-1) b=1+recur(i+1, (r>-1)?(r*10+N[i]-'0')%Q:(N[i]-'0')%Q);

    if(a<=b) dp2[i][r+1]=1;
    else dp2[i][r+1]=0;

    return dp[i][r+1]=max(a, b);
}

string anss;
char ans[1010];
int len;

void recons(int i, int r){
    if(i==n){
        ans[len]='\0';
        anss = max(anss, string(ans));
        return;
    }

    int newrem=(r>-1)?(r*10+N[i]-'0')%Q:(N[i]-'0')%Q;
    int a=dp[i+1][r+1], b=-1;
    if(N[i]-'0'>0 || r>-1) b=1+dp[i+1][newrem+1];

    if(a==b){
        recons(i+1, r);
        ans[len++]=N[i];
        recons(i+1, newrem);
        len--;
    }else if(a>b) recons(i+1, r);
    else {
        ans[len++]=N[i];
        recons(i+1, newrem);
        len--;
    }
}

int main() {
//
//    freopen("identify.in","r",stdin);
//    freopen("identifymine.out", "w", stdout);

    int t, res;
    kase=1;
    scanf("%d", &t);

    while(t--){
        scanf("%s", in);
        scanf("%d %d", &R, &Q);

        N = in;
        n = N.size();
        anss="";
        len=0;

//        for(int r=0; r<Q; r++)
//        for(int st=0; st<2; st++) {
//            dp[n][r][st]=-1000000000;
//            if(r==R) dp[n][r][st]=0;
//        }
//
//        int b,c;
//        for(int i=n-1; i>=0; i--)
//        for(int r=0; r<Q; r++)
//        for(int st=0; st<2; st++){
//            b = -1;
//            c = (r*10+N[i]-'0')%Q;
//            if(N[i]-'0'>0 || (N[i]=='0'&&st)) b=1+dp[i+1][c][1];
//            dp[i][r][st]=max((int)dp[i+1][r][st], b);
//        }

        res = recur(0,-1);

        if(res<=0) printf("Not found\n");
        else{
//            recons(0,-1);
//            int maxv=0;
//            char maxc=0;
//
//            vector<ii> v;
//
//            for(int i=0; i<n; i++)
//            for(int r=-1; r<Q; r++){
//                if(dp[i][r+1]>maxv){
//                    v.clear();
//                    v.pb(ii(i, r));
//                    maxv=dp[i][r+1];
//                    maxc=N[i];
//                }else if(dp[i][r+1]==maxv){
//                    v.pb(ii(i, r));
//                    maxc=max(maxc, N[i]);
//                }
//            }
//
//            queue<state> q,q2;
//            for(int i=0; i<v.size(); i++) if(N[v[i].first]==maxc) q.push(state("", v[i]));
//
//            int a,b,c,i,r,st;
//            v.clear();
//            maxc=0;
//            string ans="";
//            while(!q.empty()){
//                state p = q.front(); q.pop();
//                if(p.first.size()==res){
//                    ans = max(ans, p.first);
//                    continue;
//                }
//                i = p.second.first, r = p.second.second;
//                if(i==n) continue;
//
//                a = dp[i+1][r+1];
//                b = -1;
//                c = (r>-1)?(r*10+N[i]-'0')%Q:(N[i]-'0')%Q;
//                if(N[i]-'0'>0 || (N[i]=='0'&&r>-1)) b=1+dp[i+1][c+1];
//
//                if(a==b && N[i]>=maxc) {
//                    if(N[i]>maxc) while(!q2.empty()) q2.pop();
//                    q.push(state(p.first, ii(i+1, r)));
//                    q2.push(state(p.first+N.substr(i,1), ii(i+1, c)));
//                    maxc=max(maxc, N[i]);
//                } else if(a>b) q.push(state(p.first, ii(i+1, r)));
//                else if(N[i]>=maxc){
//                    if(N[i]>maxc) while(!q2.empty()) q2.pop();
//                    q2.push(state(p.first+N.substr(i,1), ii(i+1, c)));
//                    maxc=max(maxc, N[i]);
//                }
//
//                if(q.empty()){
//                    while(!q2.empty()){
//                        q.push(q2.front());
//                        q2.pop();
//                    }
//                    maxc=0;
//                }
//            }
            int i=-1,r=-1, maxv=res;
            anss="";
            while(anss.size()<res){
                int maxi=-1;
                for(int curi=i+1; curi<n; curi++){
                    if(dp2[curi][r+1] && dp[curi][r+1]==maxv) {
                        if(maxi==-1 || N[curi]>N[maxi]) maxi=curi;
                    }
                }
                i = maxi;
                anss+=N[i];
                if(r==-1) r = (N[i]-'0')%Q;
                else r = (r*10+N[i]-'0')%Q;
                maxv--;
            }

            printf("%s\n", anss.c_str());
        }
        kase++;
    }

    return 0;

}
