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

vector<int> nums;

int main(){
    freopen("B-small.in","r",stdin);
    freopen("B-small.out", "w", stdout);

    int t, n, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        nums = vector<int>(n);
        for(int i=0; i<n; i++) scanf("%d", &nums[i]);

        vector<int> tmp = nums;
        int swaps=0, i;
        for(i=0; i<n-1; i++) if(tmp[i]>tmp[i+1]) break;
        for(; i<n-1; i++) {
            if(i==0) swap(tmp[i], tmp[i+1]), swaps++;
            else if(tmp[i] < tmp[i+1]) continue;
            else if(tmp[i+1]>tmp[i-1]) swap(tmp[i], tmp[i+1]), swaps++;
            else break;
        }
        int lim=i;
        for(i=n-1; i>lim; i--){
            for(int j=i; j>lim+1; j--){
                if(tmp[j]>tmp[j-1]) swap(tmp[j], tmp[j-1]), swaps++;
            }
        }

        tmp = nums;
        reverse(tmp.begin(), tmp.end());
        int swaps2=0;
        for(i=0; i<n-1; i++) if(tmp[i]>tmp[i+1]) break;
        for(; i<n-1; i++) {
            if(i==0) swap(tmp[i], tmp[i+1]), swaps2++;
            else if(tmp[i] < tmp[i+1]) continue;
            else if(tmp[i+1]>tmp[i-1]) swap(tmp[i], tmp[i+1]), swaps2++;
            else break;
        }
        lim=i;
        for(i=n-1; i>lim; i--){
            for(int j=i; j>lim+1; j--){
                if(tmp[j]>tmp[j-1]) swap(tmp[j], tmp[j-1]), swaps2++;
            }
        }
        printf("Case #%d: %d\n", kase++, min(swaps, swaps2));
    }

    return 0;
}
