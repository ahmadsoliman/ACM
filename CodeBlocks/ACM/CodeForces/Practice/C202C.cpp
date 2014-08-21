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
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define N 100010
#define SQRTN 320

ll nums[N];
vector<int> sets[N];

bool heavy[N];
vector<int> theheavy;

bool inheavy[SQRTN][N];
int intr[N][SQRTN];

char qry[10];

ll ans[N], cntr[N];

int main() {
    int n,m,q,sqrtn, k,a,x;
    scanf("%d %d %d", &n, &m, &q);
    sqrtn = ceil(sqrt(n));

    for(int i=0; i<n; i++){
        scanf("%d", &a);
        nums[i]=a;
    }

    for(int i=0; i<m; i++){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &a);
            sets[i].pb(a-1);
            ans[i]+=nums[a-1];
        }
        sort(sets[i].begin(), sets[i].end());
        heavy[i]=sets[i].size()>=sqrtn;
        if(heavy[i]) theheavy.pb(i);
    }

    for(int i=0; i<theheavy.size(); i++){
        int h = theheavy[i];
        for(int j=0; j<sets[h].size(); j++){
            inheavy[i][sets[h][j]]=true;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<sets[i].size(); j++){
            for(int h=0; h<theheavy.size(); h++){
                intr[i][h]+=inheavy[h][sets[i][j]];
            }
        }
    }

    while(q--){
        scanf("%s", qry);
        if(qry[0]=='?'){
            scanf("%d", &k);
            k--;
            ll res=0;
            if(heavy[k]==0){
                for(int i=0; i<sets[k].size(); i++) res+=nums[sets[k][i]];
            }else{
                res+=ans[k];
            }
            for(int i=0; i<theheavy.size(); i++){
                res+=cntr[theheavy[i]]*intr[k][i];
            }
            printf("%lld\n", res);
        }else{
            scanf("%d %d", &k, &x);
            k--;
            if(heavy[k]==0){
                for(int i=0; i<sets[k].size(); i++) nums[sets[k][i]]+=x;
                for(int i=0; i<theheavy.size(); i++){
                    ans[theheavy[i]]+=intr[k][i]*x;
                }
            }else{
                cntr[k]+=x;
            }
        }
    }

    return 0;

}
/*
5 3 51
5 -5 5 1 -4
2 1 2
4 2 1 4 5
2 2 5
? 2
+ 3 4
? 1
+ 2 1
? 2
*/
