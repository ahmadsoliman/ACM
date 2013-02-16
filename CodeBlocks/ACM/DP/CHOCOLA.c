#include <stdio.h>

int hCuts[1005], vCuts[1005];

int main(){
    int t, m, n, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);
        for(i=0; i<m; i++)
            scanf("%d",&vCuts[i]);
        for(i=0; i<n; i++)
            scanf("%d",&hCuts[i]);

    }
    return 0;
}
