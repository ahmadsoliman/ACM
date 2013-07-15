#include <stdio.h>
#include <string.h>

int n, arr[1001], dp1[1001][1001], dp2[1001][1001];

int recur1(int i, int j){ //optimal 2
    if(i>j)
        return 0;
    if(dp1[i][j]!=-1)
        return dp1[i][j];
    if((i+j)%2){
        int a=recur1(i+1,j),b=recur1(i,j-1);
        return dp1[i][j]=(a<b)?a:b;
    }else{
        if(arr[i]>=arr[j]) return dp1[i][j]=arr[i]+recur1(i+1, j);
        return dp1[i][j]=arr[j]+recur1(i,j-1);
    }
}

int recur2(int i, int j){ //optimal 1, greedy 2
    if(i>j)
        return 0;
    if(dp2[i][j]!=-1)
        return dp2[i][j];
    if((i+j)%2){
        int a=arr[i]+recur2(i+1,j),b=arr[j]+recur2(i,j-1);
        return dp2[i][j]=(a>b)?a:b;
    }else{
        if(arr[i]>=arr[j]) return dp2[i][j]=recur2(i+1, j);
        return dp2[i][j]=recur2(i,j-1);
    }
}

int main(){
    int i, a, b, kase=1;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", kase++, recur2(0,n-1)-recur1(0,n-1));
    }

    return 0;
}

