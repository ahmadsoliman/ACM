#include <stdio.h>
#include <string.h>

char in[1010];

int main(){
    int t, n, i;
    scanf("%d", &t);
    while(t--){
        scanf("%s", in);
        n=strlen(in);
        if(in[n/2-1]==in[n/2]) printf("Do-it\n");
        else printf("Do-it-Not\n");
    }
    return 0;
}
