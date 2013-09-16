#include <stdio.h>
#include <string.h>

#define INF 1000000000

int main(){
    int t, s, i, maxs, kase=1;
    char str[100000], elem[100];

    gets(str);
    sscanf(str, "%d", &t);

    while(t--){
        maxs=-1;
        gets(str);

        char *pch = strtok (str, " ");

        while (pch != NULL) {
            sscanf(pch, "%d", &s);

            if(s>maxs) maxs=s;

            pch = strtok (NULL, " ");
        }
        printf("Case %d: %d\n", kase++, maxs);
    }
    return 0;
}
