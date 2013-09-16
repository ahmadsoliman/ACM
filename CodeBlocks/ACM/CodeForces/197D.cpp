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

int twon, nums[132000], seg[263000];


int main(){
    int n, m, i,j, p, b, alt, tmp;
    scanf("%d %d", &n, &m);
    twon = 1<<n;
    for(i=0; i<twon; i++) {
        scanf("%d", &nums[i]);
        seg[i+twon]=nums[i];
    }

    tmp=twon;
    alt=0;
    while(tmp>1){
        for(i=tmp; i<(tmp<<1); i+=2) {
            seg[i>>1] = (alt==0)?(seg[i]|seg[i+1]):(seg[i]^seg[i+1]);
        }
        alt=!alt;
        tmp=tmp>>1;
    }

    for(i=0; i<m; i++){
        scanf("%d %d", &p, &b);
        p--;

        tmp=twon+p;
        seg[tmp]=b;
        if(p&1) seg[tmp>>1] = seg[tmp]|seg[tmp-1];
        else seg[tmp>>1] = seg[tmp]|seg[tmp+1];
        alt=1;
        tmp>>=1;
        while(tmp>1){
            if(tmp&1) seg[tmp>>1] = (alt==0)?(seg[tmp]|seg[tmp-1]):(seg[tmp]^seg[tmp-1]);
            else seg[tmp>>1] = (alt==0)?(seg[tmp]|seg[tmp+1]):(seg[tmp]^seg[tmp+1]);
            alt=!alt;
            tmp>>=1;
        }
        printf("%d\n", seg[1]);
    }
    return 0;
}
