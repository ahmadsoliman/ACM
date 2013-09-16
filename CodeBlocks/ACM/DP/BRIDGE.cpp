#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int LIS_Len(vi A){
    int N = A.size(),i, c=0;
    set<int> s;
    set<int>::iterator k;
    for (i=0;i<N;i++) {
        if (s.insert(A[i]).second) {
            k = s.find(A[i]);
            k++;
            if (k!=s.end())
                s.erase(k);
        } /*else{
            k = s.find(A[i]);
            k++;
            c++;
            if (k!=s.end())
                s.erase(k);
        }*/
    }
    return s.size()+c;
}
/*

1 2 3 4 5 6 7 8 9 10 11 12 13 14
7 8 7 8 9 2 1 8 7 9 9 10 10 9

*/

vii ps;
vi ys;

int main(){
    int t, n, i,j, x,y;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ps.clear();
        for(i=0; i<n; i++){ scanf("%d", &x); ps.push_back(ii(x,-1)); }
        for(i=0; i<n; i++){ scanf("%d", &x); ps[i].second=x; }

        sort(ps.begin(), ps.end());
        ys.clear();
        for(i=0; i<n; i++) ys.push_back(ps[i].second);
        printf("%d\n", LIS_Len(ys));
    }
    return 0;
}
