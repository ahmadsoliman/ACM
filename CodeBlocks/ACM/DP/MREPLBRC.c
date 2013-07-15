#include <stdio.h>
#include <stdio.h>

char s[201];
int n, dp[201][201];

int recur(int i, int j){
    if(i==j){
        return 1;
    }
    int count=0;

    return count%10000;
}

int main(){
    scanf("%d",&n);
    scanf("%s",&s);
    printf("%d\n", recur(0,0,0,0));
    return 0;
}
