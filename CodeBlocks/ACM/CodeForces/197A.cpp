#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 1000000000

int nums[10000];
char in[10000];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int i, n;
    scanf("%s", in);
    char * pch = strtok (in, "+");
    while (pch != NULL){
        sscanf(pch, "%d", &nums[i++]);
        pch = strtok (NULL, "+");
    }
    n=i;
    qsort(nums, n, sizeof(int), compare);
    for(i=0; i<n; i++){
        printf("%d", nums[i]);
        if(i<n-1) printf("+");
    }
    printf("\n");

    return 0;
}
