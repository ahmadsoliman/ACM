#include <stdio.h>

int main(){
    int t, i,j, y, arr[52], kase=1;
    char c1,c2, v[52], s[52], in[10];

    scanf("%d", &t);
    while(t--){
        for(i=0; i<52; i++){
            scanf("%s", in);
            c1=in[0];
            c2=in[1];
            v[i]=c1;
            s[i]=c2;
            switch(c1){
                case 'A': case 'K': case 'Q': case 'J': case 'T' : arr[i]=10; break;
                default: arr[i]=c1-'0';
            }
        }
        y=0;
        for(i=0, j=26; i<3; i++){
            y+=arr[j];
            j= j - (11-arr[j]);
        }
        y=y-j+26-1;
        in[0]=v[y];
        in[1]=s[y];
        printf("Case %d: %s\n", kase++, in);
    }
    return 0;
}
