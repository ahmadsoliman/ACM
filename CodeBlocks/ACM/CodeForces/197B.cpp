#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 1000000000

int nums[100010];

int main(){
    int i, n, m;
    long long d;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++){
        scanf("%d", &nums[i]);
        nums[i]-=1;
    }
    d=nums[0];
    for(i=1; i<m; i++){
        if(nums[i]>=nums[i-1]) d+=nums[i]-nums[i-1];
        else{
            d+=n-nums[i-1]+nums[i];
        }
    }
    printf("%I64d\n", d);
    return 0;
}
