#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> ps;

char in[5005];
string T;

short zfn[100], len;
vector < vector <short> > occ;

void kmpPreprocess(string P) {
    int i=0, j=-1;
    zfn[0]=-1;
    while(i<P.size()) {
        while(j>=0 && P[i]!=P[j]) j=zfn[j];
        i++, j++;
        zfn[i]=j;
    }
}

void kmp(string P, int index){
    int i=0, j=0;
    while(i<T.size()) {
        while(j>=0 && T[i]!=P[j]) j=zfn[j];
        i++; j++;
        if(j==P.size()){
            occ[index].push_back(i-j);
            j=zfn[j];
        }
    }
}

int done;
vector< vector<short> > dp;

short recur(int i, int bm){
    if(bm==done) return 1;
    if(i>=T.size()) return 0;

    if(dp[i][bm]!=-1) return dp[i][bm];

    short res=0;
    for(int j=0; j<ps.size(); j++){
        if(!(bm&(1<<j))){
            for(int k=0; k<occ[j].size(); k++){
                if(occ[j][k]==i) {
                    res =max(res, recur(i+ps[j].size(), bm|(1<<j)));
                    break;
                }
            }
        }
    }
    return dp[i][bm]=res;
}

int main(){
    int n,m, i,j,k, f, bm, cnt, last;

    //freopen("g.out", "w", stdout);
    while(scanf("%d %d", &n, &m)>0){
        if(n==0) return 0;

        memset(zfn, 0 ,sizeof zfn);
        ps.clear();
        for(i=0; i<n; i++) {
            scanf("%s", in);
            ps.push_back(in);
        }

        T="";
        for(i=0; i<m; i++){
            scanf("%s", in);
            T+=string(in);
        }

        occ = vector<vector<short> >(n+1);

        f=1;
        for(i=0; i<n; i++) {
            kmpPreprocess(ps[i]);
            kmp(ps[i], i);

            if(occ[i].size()==0) { f=0; break; }
            /*for(j=0; j<occ[i].size(); j++){
                occs.push_back(make_pair(occ[i][j], i));
            }*/
        }
        if(n==1) {printf("%d\n", occ[0].size()); continue; }

        done = (1<<n)-1;
        dp = vector< vector<short> >(T.size(), vector<short>(done, -1));

        short res=0;
        for(i=0; i<T.size(); i++){
            res+=recur(i, 0);
        }
        printf("%d\n", res);
    }
    return 0;
}
