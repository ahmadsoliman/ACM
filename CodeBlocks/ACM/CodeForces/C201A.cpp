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

int a[105];

int main(){
    int n, i,j,tmp, mid;
    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    tmp=a[0];
    a[0]=a[n-1];
    a[n-1]=tmp;

    printf("%d", a[0]);
    for(i=1; i<n; i++) printf(" %d", a[i]);
    printf("\n");
    return 0;
}
