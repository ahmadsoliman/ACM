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

int arr[105][105], dp[105][105];

int main(){
    int n, i,j,o1,o2;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<=i; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(i=0; i<n; i++) dp[n-1][i]=arr[n-1][i];
    for(i=n-2; i>=0; i--){
        for(j=0; j<=i; j++){
            o1=arr[i][j]+dp[i+1][j];
            o2=arr[i][j]+dp[i+1][j+1];
            dp[i][j]=max(o1,o2);
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}
