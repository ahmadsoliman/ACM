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

vi xb, yb, sb;

int main(){
    int t, kase=1, b,x,y, i,j,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &k, &b, &x, &y);

        xb.clear(); yb.clear();
        while(x>0) {
            xb.push_back(x%b);
            x/=b;
        }
        while(y>0) {
            yb.push_back(y%b);
            y/=b;
        }

        sb.clear();
        for(i=0; i<min(xb.size(), yb.size()); i++){
            sb.push_back((xb[i]+yb[i])%b);
        }
        while(i<xb.size()) { sb.push_back((xb[i])%b); i++; }
        while(i<yb.size()) { sb.push_back((yb[i])%b); i++; }

        ll r=0;
        for(i=0, j=0; i<sb.size(); i++, j++){
            r += sb[i]*pow(b, j);
        }
        printf("%d %lld\n", kase++, r);
    }
    return 0;
}
