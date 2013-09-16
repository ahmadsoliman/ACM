#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int nums[105], lhs[1000010];

int main() {
    int i, n , a, b, c, d, e, f, k, v, cnt;
    scanf("%d", &n);

	for(i =0; i<n; i++){
        scanf("%d", &nums[i]);
	}

    k=0;
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            for (c = 0; c < n; c++) {
                lhs[k++] = nums[a]*nums[b]+nums[c];
            }
        }
    }

    sort(lhs, lhs+k);
    cnt=0;
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            for (c = 0; c < n; c++) {
                if(nums[c]==0) continue;
                v = (nums[a]+nums[b])*nums[c];
                if(binary_search(lhs, lhs+k, v)) cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
