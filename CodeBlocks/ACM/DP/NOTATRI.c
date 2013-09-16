#include <stdio.h>
#include <string.h>

int cumm[1000010], nums[2010];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int n, i,j,k, maxs, cnt;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        memset(cumm, 0, 4*sizeof(int)*(n+1));
        maxs=0;
        for(i=0; i<n; i++){
            scanf("%d", &nums[i]);
            cumm[nums[i]]++;
            if(nums[i]>maxs)maxs=nums[i];
        }
        for(i=maxs-1; i>=0; i--) cumm[i]+=cumm[i+1];

        qsort(nums, n, sizeof(int), compare);

        cnt=0;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(nums[i]+nums[j]>=maxs) break;
                cnt+=cumm[nums[i]+nums[j]+1];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
