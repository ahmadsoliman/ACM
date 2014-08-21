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

typedef bitset<105> bs;

int n;
char in[105];
vi graph[105];
vii tmp;

int check(bs bm){
    bs nbm=bm;
    for(int i=0; i<n; i++){
        if(bm[i]) for(int j=0; j<graph[i].size(); j++) nbm[graph[i][j]]=1;
    }
    if(nbm.count()==n) return 1;
    return 0;
}

int recur(bs bm, int i, int left){
    if(left==0){
        if(check(bm)){
            printf("%d", bm.count());
            for(int j=0; j<n; j++) if(bm[j]) printf(" %d", j+1);
            return 1;
        }
        return 0;
    }
    if(i==n) return 0;
    if(recur(bm, i+1, left)) return 1;
    bm[i]=1;
    return recur(bm, i+1, left-1);
}

int main(){
    int maxSol, kase=1;
    while(scanf("%d", &n)>0){
        tmp.clear();
        for(int i=0; i<n; i++){
            graph[i].clear();
            scanf("%s", in);
            for(int j=0; j<n; j++) if(in[j]=='1') graph[i].push_back(j);
            tmp.pb(ii(graph[i].size(), i));
        }
        sort(tmp.begin(), tmp.end());

        bs bm;
        for(maxSol=0; maxSol<tmp.size(); maxSol++){
            bm[tmp[maxSol].second]=1;
            if(check(bm)) break;
        }
        maxSol++;

        printf("Case %d: ", kase++);
        for(int i=1; i<=maxSol; i++){
            if(recur(bs(), 0, i)) break;
        }
        printf("\n");
    }
    return 0;
}
