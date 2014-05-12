#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vi;

vi res;

void recur(int n){
    if(n<=1) return;
    int cnt=0;
    while(n>0) res.push_back(n%2),n/=2, cnt++;
    recur(cnt-1);
}

int main(){
    int n, i,j;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        res.clear();
        recur(n);
        printf("0");
        for(i=res.size()-1; i>=0; i--) printf("%d", res[i]);
        printf("\n");
    }
    return 0;
}

