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

int a[100010];

int main(){
    int n, i,j,k, maxa=-1;
    ll sum=0, r,c, cov;
    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
        maxa=max(maxa, a[i]);
        sum+=a[i];
    }

    r = maxa+1;

    cov=0;
    for(i=0; i<n; i++) cov+=r-a[i];
    c=cov;
    while(r>c) r++, c+=cov;
 //   if(r>cov) r+=r-cov;
    printf("%I64d\n", r);
    return 0;
}
