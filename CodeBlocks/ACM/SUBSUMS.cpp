#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int nums[100];

vector<int> s;
vector<int>::iterator itl, ith;

int main(){
    int i,j,k, n,a,b;

    scanf("%d %d %d", &n, &a, &b);

    for(i=0; i<n; i++) scanf("%d", &nums[i]);

    int halfs=(n+1)/2, lefts=n-halfs, bm, cursum;

    long long cnt=0;
    if(a<=0 && b>=0) cnt++;

    for(bm=1; bm<(1<<halfs); bm++){
        cursum=0;
        for(i=0; i<halfs; i++) if(bm&(1<<i)) cursum+=nums[i];
        s.push_back(cursum);
        if(cursum>=a && cursum<=b) cnt++;
    }
    sort(s.begin(), s.end());

    for(bm=1; bm<(1<<lefts); bm++){
        cursum=0;
        for(i=0; i<lefts; i++) if(bm&(1<<i)) cursum+=nums[halfs+i];
        if(cursum>=a && cursum<=b) cnt++;

        itl=lower_bound(s.begin(), s.end(), a-cursum);
        ith=upper_bound(s.begin(), s.end(), b-cursum);

        cnt+=ith-itl;
    }
    printf("%lld\n", cnt);
    return 0;
}






