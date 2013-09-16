#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, string > is;
typedef pair<int, is > iis;

#define INF 1000000000

char in[110];

char notc(char c){
    if(c=='W') return 'B';
    return 'W';
}

set<string> vis;

int main(){
    int i,j,k, kase=1, n, fi, d, mind,w, failed;
    iis u;
    string s;
    queue< iis > q;
    while(scanf("%s", in)>0){
        if(in[0]=='-') return 0;
        s = string(in);
        n=s.size();
        for(i=0; i<n; i++) if(s[i]=='F') {fi=i; break;}
        q=queue<iis>();
        q.push(iis(0, is(fi, s)));
        mind=-1;
        vis.clear();
        while(!q.empty()){
            u = q.front(); q.pop();
            d=u.first; fi=u.second.first; s=u.second.second;
            if(vis.insert(s).second==false) continue;

            for(failed=0, i=0, w=0; i<s.size(); i++){
                if(w==0 && s[i]=='B') w=1;
                if(w==1 && s[i]=='W') w=2;
                if(w==2 && s[i]=='B') {failed=1; break; }
            }
            if(failed==0) {mind=d; break;}
            if(d==9) continue;
            if(fi>0) {
                string s1 = s;
                s1[fi]=s1[fi-1];
                s1[fi-1]='F';
                q.push(iis(d+1, is(fi-1, s1)));
            }
            if(fi<n-1) {
                string s1 = s;
                s1[fi]=s1[fi+1];
                s1[fi+1]='F';
                q.push(iis(d+1, is(fi+1, s1)));
            }
            if(fi>1) {
                string s1 = s;
                s1[fi]=notc(s1[fi-2]);
                s1[fi-2]='F';
                q.push(iis(d+1, is(fi-2, s1)));
            }
            if(fi<n-2) {
                string s1 = s;
                s1[fi]=notc(s1[fi+2]);
                s1[fi+2]='F';
                q.push(iis(d+1, is(fi+2, s1)));
            }
        }
        printf("%d. %d\n", kase++, mind);
    }
    return 0;
}
