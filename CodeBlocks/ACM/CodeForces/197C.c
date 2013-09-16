#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 1000000000

char flag[11];
int n, nums[1010], cumm[1010], dp[1010][25][11][11], cur[1010];

/* diff = right-left
right = diff+left
left = right-diff
*/

int recur(int i, int diff, int lastl, int lastr){
    if(i==n) return 1;
    if(lastl>-1 && lastr>-1 && dp[i][diff+10][lastl][lastr]!=-1) return dp[i][diff+10][lastl][lastr];
    int j;
    for(j=0; j<10; j++){
        if(flag[j]=='1'){
            if(diff<=0 && lastr!=j && diff+(j+1)>0 && recur(i+1, diff+(j+1), j, lastr)) { cur[i]=j+1; return dp[i][diff+10][lastl][lastr]=1;}
            else if(diff>0 && lastl!=j && diff-(j+1)<0 && recur(i+1, diff-(j+1), lastl, j)) { cur[i]=j+1; return dp[i][diff+10][lastl][lastr]=1;}
        }
    }
    return dp[i][diff+10][lastl][lastr]=0;
}

int main(){
    int i,res;
    scanf("%s", flag);
    scanf("%d", &n);
    memset(dp, -1, sizeof dp);
    res=recur(0, 0, -1, -1);
    if(res){
        printf("YES\n");
        for(i=0; i<n; i++) {
            printf("%d", cur[i]);
            if(i<n-1) printf(" ");
        }
        printf("\n");
    }else printf("NO\n");
    return 0;
}
