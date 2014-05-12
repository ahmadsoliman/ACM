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

int gcd(int n, int m){
    if(n==0) return m;
    return gcd(m%n, n);
}

int main(){
    int n, i,j,k, d=0, maxn=0, c;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
        d=gcd(d, a[i]);
        maxn=max(maxn, a[i]);
    }
    sort(a, a+n);

    c = maxn/d - n;

    if(c%2==0) printf("Bob\n");
    else printf("Alice\n");
    return 0;
}
