#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n , a, b, c, d, e, f, count;
    scanf("%d", &n);

    int *nums= (int *)calloc(101, sizeof(int));

	for(i =0; i<n; i++){
        scanf("%d", &nums[i]);
	}
    qsort(nums, n, sizeof(int), compare_int);

	for(i =0; i<n; i++){
        printf("%d", nums[i]);
	}

    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            for (c = 0; c < n; c++) {
                for (d = 0; d < n; d++) {
                    for (e = 0; e < n; e++) {
                        if(a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e) continue;
                        if((f=nums[a]*nums[b]+nums[c])%nums[d]==0) f = f/nums[d] - nums[e];

                    }
                }
            }
        }
    }
}
