#include <stdio.h>
#include <stdlib.h>

int hCuts[1005], vCuts[1005], m, n;

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main(){
    int t, i, j, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);
        m--;
        n--;
        for(i=0; i<m; i++)
            scanf("%d",&vCuts[i]);
        for(i=0; i<n; i++)
            scanf("%d",&hCuts[i]);

        qsort(vCuts, m, sizeof(int), compare);
        qsort(hCuts, n, sizeof(int), compare);

        c=i=j=0;
        while(i<m || j<n)
            if(i<m && (j==n || vCuts[i]>=hCuts[j]))
                c += vCuts[i++]*(j+1);
            else
                c += hCuts[j++]*(i+1);

        printf("%d\n", c);
    }
    return 0;
}
