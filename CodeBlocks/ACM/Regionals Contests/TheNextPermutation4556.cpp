#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


int main(){
    int t, i, d, j, arr[100], n, kase=1;
    char arrc[100], arrc2[100];

    scanf("%d", &t);
    while(t--){
        scanf("%d %s", &i, &arrc);
        n = strlen(arrc);
        strncpy(arrc2, arrc, n);
        sort(arrc2, arrc2+n);

        next_permutation(arrc,arrc+n);

        if(strncmp(arrc,arrc2, n)==0)
            printf("%d BIGGEST\n", kase++);
        else
            printf("%d %s\n", kase++, arrc);
    }

    return 0;
}
