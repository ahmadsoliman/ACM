#include <stdio.h>
#include <string.h>

int n, sourC[205][205], sweetC[205][205], dp[205][205];
char sweet[205];

int recur(int i, int j){
    if(i==j)
        return (sweet[i]=='1')?1:0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int k, maxC=((sweetC[i][j]>sourC[i][j])?j-i+1:0), curC;
    for(k=i; k<j; k++){
        curC = recur(i,k)+recur(k+1,j);
        if(curC>maxC)
            maxC = curC;
    }
    return dp[i][j] = maxC;
}

int main(){
    int t, i, j;
    char c;
    gets(sweet);
    sscanf(sweet, "%d", &t);
    while(t--){
        gets(sweet);
        sscanf(sweet, "%d", &n);
        gets(sweet);

        memset(sweetC, 0, sizeof sweetC);
        memset(sourC, 0, sizeof sourC);

        for(i=0; i<n; i++){
            for(j=i; j<n; j++) {
                if(sweet[j]=='1'){
                    if(i==j)
                        sweetC[i][j]=1;
                    else{
                        sweetC[i][j] = sweetC[i][j-1]+1;
                        sourC[i][j] = sourC[i][j-1];
                    }
                }else{
                    if(i==j)
                        sourC[i][j]=1;
                    else{
                        sourC[i][j] = sourC[i][j-1]+1;
                        sweetC[i][j] = sweetC[i][j-1];
                    }
                }
            }
        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0, n-1));
    }
    return 0;
}
