#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int LIS_Len(vector<int> A){
    int N = A.size(),i;
    set<int> s;
    set<int>::iterator k;
    for (i=0;i<N;i++) {
        if (s.insert(A[i]).second) {
           k = s.find(A[i]);
           k++;
           if (k!=s.end())
              s.erase(k);
        }
    }
    return s.size();
}

int s1[62510], s2[62510], kase, t, i, j, n, n1, n2, pos[62510];

vi nums;

int main(){
    kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &n1, &n2);

        scanf("%d", &i);
        for(i=0; i<n1; i++) {
            scanf("%d", &s1[i]);
            pos[s1[i]]=i;
        }
        scanf("%d", &i);
        nums.clear();
        for(i=0; i<n2; i++) {
            scanf("%d", &s2[i]);
            nums.push_back(pos[s2[i]]);
        }

        printf("Case %d: %d\n", kase++, 1+LIS_Len(nums));
    }
    return 0;
}
