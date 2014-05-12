#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define EPS 1e-9

struct point {
    int x,y;
    point() { x = 0; y = 0; }
    point(int _x, int _y) { x = _x; y = _y; }
};

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int numP[105], m, n;
vector< bitset<105> > bits;
point loc[25], cities[105];

int recur(int i, int k, int bm){
    if(k==0){
        int cnt=0;
        bitset<105> rem;
        for(int j=0; j<m; j++) if((bm&(1<<j))) rem|=bits[j];
        for(int j=0; j<n; j++) if(rem[j]) cnt+=numP[j];
        return cnt;
    }
    if(i==m || m-k<0) return 0;
    int a=recur(i+1, k, bm), b=recur(i+1, k-1, bm|(1<<i));
    return max(a,b);
}

int main(){
    int k,r, x,y, i,j,l;
    double d;

    scanf("%d %d", &k, &r);
    scanf("%d", &m);
    for(i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        loc[i]=point(x,y);
    }
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d %d", &x, &y, &j);
        cities[i]=point(x,y);
        numP[i]=j;
    }

    bits = vector<bitset<105> >(n, bitset<105>());
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            d = dist(loc[i], cities[j]);
            if(d<r || fabs(d-r)<EPS){
                bits[i][j]=1;
            }
        }
    }
    printf("%d\n", recur(0, k, 0));
    return 0;
}
