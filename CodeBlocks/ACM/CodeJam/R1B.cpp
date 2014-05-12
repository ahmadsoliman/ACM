#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    freopen("B-small.in","r",stdin);
    freopen("B-small.out", "w", stdout);

    int t, A,B,K, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &A, &B, &K);

        int cnt=0;
        for(int i=0; i<A; i++){
            for(int j=0; j<B; j++){
                if((i&j)<K) cnt++;
            }
        }
        printf("Case #%d: %d\n", kase++, cnt);
    }

    return 0;
}
