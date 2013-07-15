#include <stdio.h>
#include <string.h>

#define max(x,y) (x>y)?x:y

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int nums[105];
char s[100];

int main(){
    int t, n, G, i, j, tmp;
    gets(s);
    sscanf(s, "%d", &t);
    while(t--){
        gets(s);
        n=0;
        char * pch;
        pch = strtok (s," ");
        while (pch != NULL){
            sscanf(pch, "%d", &nums[n++]);
            pch = strtok (NULL, " ");
        }

        G=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++){
                tmp = gcd(nums[i],nums[j]);
                G=max(G,tmp);
            }
        printf("%d\n", G);
    }
    return 0;
}
