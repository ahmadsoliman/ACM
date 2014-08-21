#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int nums[100000];
vector<int> lis;

int main(){
    int i, j, n, k, maxlis, zero=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        lis.push_back(zero);
    }

    std::vector<int>::iterator low;
    lis[0]=nums[k=0];
    for(i=1, maxlis=1; i<n; i++){
        if(nums[i]>lis[k]) {
            lis[++k]=nums[i];
            if(k+1>maxlis) maxlis=k+1;
        } else{
            low = lower_bound(lis.begin(), lis.begin()+k+1, nums[i]);
            lis[k=low-lis.begin()]=nums[i];
        }
    }
    printf("%d\n", maxlis);
    return 0;
}

/*
8
-7 10 9 2 3 8 8 1
*/
