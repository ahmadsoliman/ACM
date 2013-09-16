#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii pairs, lis;

int main(){
    int n, i, k, a,b, maxlis;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        pairs.push_back(make_pair(a,b));
    }

    vii::iterator low;
    lis.push_back(pairs[0]);

    for(i=1, k=1, maxlis=1; i<n; i++){
        if(pairs[i].first>lis[k].first && pairs[i].second>lis[k].second) {
            if(k+1==lis.size())
                lis.push_back(pairs[i]);
            else
                lis[++k]=pairs[i];
            if(k+1>maxlis) maxlis=k+1;
        } else{
            low = lower_bound(lis.begin(), lis.begin()+k+1, pairs[i]);
            lis[k=low-lis.begin()]=pairs[i];
        }
    }
    printf("%d\n", maxlis);
    return 0;
}
