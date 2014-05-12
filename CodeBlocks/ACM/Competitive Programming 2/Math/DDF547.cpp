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
#define MAX 3010
#define pb push_back

int sum[MAX];
vvi ddf;
vi found;

int main() {
    int n,m ,i,j, fact, k, kase=1, maxi;

    for(i=1; i<MAX; i++){
        sum[i]=0;
        for(j=1; j*j<=i; j++){
            if(i%j==0){
                fact = j;
                while(fact>0) sum[i]+=fact%10, fact/=10;
                if(j*j==i) continue;
                fact = i/j;
                while(fact>0) sum[i]+=fact%10, fact/=10;
            }
        }
    }

    ddf=vvi(MAX+1, vi());
    for(i=1; i<MAX; i++){
        found=vi(MAX+1);
        ddf[i].pb(i);
        found[i]=1;
        while(!found[sum[ddf[i].back()]]) found[sum[ddf[i].back()]]=1, ddf[i].pb(sum[ddf[i].back()]);
    }

    while(scanf("%d %d", &m, &n)>0){
        maxi=min(m,n);
        for(i=min(m,n)+1; i<=max(m,n); i++){
            if(ddf[i].size()>ddf[maxi].size()) maxi=i;
        }
        printf("Input%d: %d %d\nOutput%d:", kase, m, n, kase);
        for(i=0; i<ddf[maxi].size(); i++) {
            printf(" %d", ddf[maxi][i]);
        }
        printf("\n");
        kase++;
    }
    return 0;
}
