#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
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

int main(){
    bool entered=false;
    int x, kase=1;
    while(scanf("%d", &x)){
        if(x==-1) break;
        if(entered) printf("\n");
        else entered=1;
        vi A;
        A.push_back(x);
        while(scanf("%d", &x)){
            if(x==-1) break;
            A.push_back(x);
        }
        reverse(A.begin(), A.end());
        printf("Test #%d:\n", kase++);
        printf("  maximum possible interceptions: %d\n", LIS_Len(A));
    }
    return 0;
}
