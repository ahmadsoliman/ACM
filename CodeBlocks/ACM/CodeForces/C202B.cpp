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

vii p;
vi res;

int main(){
    int n, i,j,k, v;
    scanf("%d", &v);

    for(i=0; i<9; i++){
        scanf("%d", &k);
        p.push_back(ii(k,9-i));
    }
    sort(p.rbegin(), p.rend());

    while(v>0 && p.size()>0) {
        while(v>=p.back().first && p.size()>0) {
            res.push_back(9-p.back().second+1);
            v-=p.back().first;
        }
        p.pop_back();
    }
    if(v!=0 || res.size()==0)  printf("-1\n");
    else {
        for(i=0; i<res.size(); i++) printf("%d", res[i]);
        printf("\n");
    }
    return 0;
}
