
#include <stdio.h>
#include <stdlib.h>

int compare_int (const int *a, const int *b)
{
  int temp = *a - *b;
  if (temp > 0)
    return 1;
  else if (temp < 0)
    return -1;
  else
    return 0;
}

int main()
{
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
                    if(!nums[d])
                        continue;
                    for (e = 0; e < n; e++) {
                        f = (nums[a]*nums[b]+nums[c])/nums[d] - nums[e];

                    }
                }
            }
        }
    }
}
