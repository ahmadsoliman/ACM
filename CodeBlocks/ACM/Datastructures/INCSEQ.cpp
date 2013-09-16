#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD 5000000

int * tree;
int MaxVal;

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int arr[10010], dp[10010];

int main(){
    int n,k, i,j,l, s;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++) scanf("%d", &arr[i]);

    MaxVal=n+1;
    tree = new int[MaxVal+1];

    for(i=1; i<=k; i++){
        memset(tree, 0, sizeof(int)*(MaxVal+1));

        for(j=0; j<n; j++){
            if(i==1) dp[j]=1;
            else dp[j]=read(arr[j]-1);

            update(arr[j], dp[j]);//-(read(arr[j])-read(arr[j]-1)));
        }
    }
    s=0;
    for(i=0; i<n; i++) s+=dp[i];
    printf("%d\n", s);
    return 0;
}
