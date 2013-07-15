#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int nums[100005];

int main(){
    int n, i, j, c;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }
    c = 0;
    for(i=0; i<n-1; i++){
        if(nums[i]<nums[i+1]) for(j=i+2; j<n && nums[i+1]>nums[j]; j++) {
            c++;
            if(j<n-1 && nums[j]>nums[j+1]) break;
        }
    }
    printf("%d\n", c);
    return 0;
}



