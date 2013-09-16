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

int arr[100010];

int main(){
    int n, i,j;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &arr[i]);

    set<int> all, s, last;
    set<int>::iterator it;


    for(i=n-1; i>=0; i--){
        all.insert(arr[i]);
        last = s;
        s.clear();
        for (it=last.begin(); it!=last.end(); ++it){
            s.insert(arr[i]|(*it));
            all.insert(arr[i]|(*it));
        }
        s.insert(arr[i]);
    }
    printf("%d\n", all.size());
    return 0;
}
