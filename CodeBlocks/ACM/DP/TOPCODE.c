#include <stdio.h>
#include <string.h>

int n;
char s[105];

int recur(int i, int last){
    if(i==n)
        return 0;

    if(s[i]<s[last] || i==last+1) return recur(i+1, last);
    int a = recur(i+1, last), b = 1+recur(i+1, i);
    return (a>b)?a:b;
}

int main(){
    while(scanf("%s", s)>0){
        n = strlen(s);
        printf("%d\n", recur(0,0));
    }
    return 0;
}
