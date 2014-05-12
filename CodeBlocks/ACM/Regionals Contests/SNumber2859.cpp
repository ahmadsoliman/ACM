#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
    int i,j, n, val;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        v.clear();
        for(i=0; i<n; i++) scanf("%d", &val), v.push_back(val);
        sort(v.begin(), v.end());
        n-=2;
        while(n>0) {
            if(v[n]!=v[n+1]) break;
            n--;
        }
        printf("%d\n", v[n]);
    }
    return 0;
}
