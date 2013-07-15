#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define min(x,y) ((x<y)?x:y)
#define max(x,y) ((x>y)?x:y)

int arr[3];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int r, g, b;
    long long c=0;
    scanf("%d %d %d", &arr[0], &arr[1],&arr[2]);
    qsort(arr, 3, sizeof(int), compare);
    c = arr[0]/3 + arr[1]/3 + arr[2]/3;
    arr[0]%=3;
    arr[1]%=3;
    arr[2]%=3;
    c += min(arr[0],min(arr[1],arr[2]));

    printf("%d\n", c);
    return 0;
}
