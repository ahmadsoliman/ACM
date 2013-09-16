#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[2005];

int main(){
    int t, n, cnt, i,len;

    scanf("%d", &n);

    scanf("%s", s);
    len = strlen(s);
    cnt=0;
    for(i=4; i<len; i++){
        if(i%n==0){
            if(s[i-1]==s[i-2]&&s[i-1]==s[i-3]) cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
