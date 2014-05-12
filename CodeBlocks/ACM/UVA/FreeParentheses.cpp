#include <stdio.h>
#include <string.h>
#include <math.h>

char in[3000];
int nums[3000];
int sign[3000];

int n, dp[35][35][6100];

void recur(int i, int open, int val){
    if(dp[i][open][val+3000]) return;

}

int main(){
    int t, i,j,k;
    char c;
    scanf("%d\n", &t);
    while(t--){
        n=0;
        memset(sign, 0, sizeof sign);
        while(1){
            scanf("%d%c", &k, &c);
            nums[n]=k;
            if(c=='\n') break;
            if(c=='-') sign[n+1]=1;
            n++;
        }
        n++;

    }
    return 0;
}
