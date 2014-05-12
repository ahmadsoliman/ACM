#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>

using namespace std;

map<int, int> m;
set<int> s;
set<int>::iterator it;

int nums[200005], lisl[200005], lis[200005], lism[200005], maxr[200005];

int main(){
    int t, i, j, n, k, ind, maxlis, zero=0, ans, cur;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        s.clear();
        for(i=0; i<n; i++) {
            scanf("%d", &nums[i]);
            s.insert(nums[i]);
        }
        lisl[0]=1;
        for(i=1; i<n; i++){
            if(nums[i]>nums[i-1]) lisl[i]=lisl[i-1]+1;
            else lisl[i]=1;
        }
        lis[n-1]=1;
        for(i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]) lis[i]=lis[i+1]+1;
            else lis[i]=1;
        }

        m.clear();
        ind=0;
        for(it=s.begin(); it!=s.end(); it++){
            m.insert(make_pair(*it, ind++));
        }

        for(i=n-1; i>=0; i--){
            lism[m[nums[i]]]=lis[i];
        }

        memset(maxr, 0, sizeof maxr);
        maxr[ind-1]=lism[ind-1];
        for(i=ind-2; i>=0; i--){
            if(lism[i]>lism[i+1]) maxr[i]=lism[i];
            else maxr[i]=lism[i+1];
        }

        ans=0;
        for(i=0; i<n; i++){
            cur = lisl[i]+maxr[m[nums[i]]+1];
            ans = max(ans, cur);
        }
        printf("%d\n", ans);
    }
    return 0;
}
