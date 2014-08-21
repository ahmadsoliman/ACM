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

multiset<int> nums;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out", "w", stdout);

    int t, n, x, kase=1, num;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &x);

        nums.clear();
        for(int i=0; i<n; i++) scanf("%d", &num), nums.insert(-1*num);

        int cnt=0;
        for(set<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            int left = x+(*it);

            set<int>::iterator ittemp = it;
            ittemp++;
            set<int>::iterator it2 = lower_bound(ittemp, nums.end(), -1*left);
//            printf("%d %d\n", *it, *it2);

            if(it2!=nums.end()){
                nums.erase(it2);
            }
            cnt++;
        }
        printf("Case #%d: %d\n", kase++, cnt);
    }

    return 0;
}
