#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main(){
    int t, kase=1, arr[15], i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &i);
        for(i=0; i<10; i++) scanf("%d", &arr[i]);
        qsort(arr, 10, sizeof(int), compare);
        printf("%d %d\n", kase++, arr[2]);
    }
    return 0;
}
