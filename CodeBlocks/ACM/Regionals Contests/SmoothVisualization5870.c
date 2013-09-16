#include <stdio.h>
#include <string.h>

int main(){
    int t, i, j, k, l, diff, added, h, maxh, out[10000][8];
    char num[110];
    scanf("%d", &t);
    while(t--){
        scanf("%s", num);
        memset(out, 0, sizeof out);
        k = strlen(num);
        maxh=0;
        for(i=0, l=0; i<k; i++){
            if(num[i]-'0'>maxh) maxh=num[i]-'0';
            for(j=0; j<num[i]-'0'; j++) out[l][j]=1;
            l++;
            if(i<k-1){
                h=num[i]-'0';
                diff=(num[i+1]-'0')-(num[i]-'0');
                added=1;
                if(diff<0){
                    added=-1;
                    diff*=-1;
                }
                h+=added;
                while(diff-->1){
                    for(j=0; j<h; j++) out[l][j]=1;
                    h+=added;
                    l++;
                }
            }
        }
        for(i=maxh-1; i>=0; i--){
            for(j=0; j<l; j++){
                if(out[j][i]) printf("+");
                else printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
/*
3
1425
114242
1726
*/
