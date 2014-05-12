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
typedef vector<vi> vvi;

#define INF 1000000000
#define pb push_back

char str[50];
vi grps, type;
int done, dp[34000000], kase, vis[34000000];

int recur(int bm){
    if(bm==done) return 1;
    if(vis[bm]==kase) return dp[bm];
    vvi newgrps;
    vi newgrpsi, grpsc;
    int c, j, bm2;
    for(int i=0; i<grps.size(); ){
        if(!(bm&(1<<i))){
            newgrpsi.pb(i);
            grpsc.pb(grps[i]);
            newgrps.pb(vi());
            c=0, j=i+1;
            while(j<grps.size()){
                while(j<grps.size() && (bm&(1<<j))) j++;
                if(j>=grps.size()) break;
                if(type[i]!=type[j]) break;

                newgrps[grpsc.size()-1].pb(j);
                grpsc[grpsc.size()-1]+=grps[j];
                j++;
            }
            i=j;
        } else i++;
    }
    vis[bm]=kase;
    for(int i=0; i<newgrpsi.size(); i++){
        if(grpsc[i]>1){
            bm2=bm|(1<<newgrpsi[i]);
            for(j=0; j<newgrps[i].size(); j++) bm2|=(1<<newgrps[i][j]);
            if(recur(bm2)) return dp[bm]=1;
        }
    }
    return dp[bm]=0;
}

int main(){
    int t, n, i, c;
    scanf("%d", &t);
    kase=1;
    while(t--){
        scanf("%s", str);
        n = strlen(str);
        grps.clear();
        type.clear();
        for(i=0; i<n; ){
            if(str[i]=='a'){
                c=0;
                while(i<n && str[i]=='a') c++, i++;
                grps.pb(c);
                type.pb(0);
            }else{
                c=0;
                while(i<n && str[i]=='b') c++, i++;
                grps.pb(c);
                type.pb(1);
            }
        }

        done = (1<<grps.size())-1;
        printf("%d\n", recur(0));
        kase++;
    }
    return 0;
}
