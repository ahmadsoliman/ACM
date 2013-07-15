#include <stdio.h>
#include <string.h>

char s[27];
int n, sums[27][27];

int recur(int l, int arr[], int i, int j, int cuts){
    if(cuts==0){
        if(l==0) return 0;
        while(l--) if(arr[l]>arr[l+1]) return 0;
        return 1;
    }
    if(i==n||j==n) return 0;
    int a = recur(l,arr,i,j+1,cuts), b;
    int arr2[l+1];
    memccpy(arr2, arr, l, sizeof(int));
    arr2[l++] = sums[i][j];
    b = recur(l, arr2, j+1, j+1, cuts-1);
    return a+b;
}

int main(){
    int i,j, kase=1, res;
    while(scanf("%s", s)>0){
        if(strcmp(s, "bye")==0) return 0;
        n=strlen(s);
        for(i=0; i<n; i++) {
            for(j=i; j<n; j++){
                if(i==j) sums[i][j] = s[i]-'0';
                else sums[i][j] = sums[i][j-1]+(s[j]-'0');
            }
        }
        res=1;
        int arr[0];
        for(i=1; i<n; i++) {
            res+=recur(0, arr, 0,0, i);
        }
        printf("%d. %d\n", kase++, res);
    }
    return 0;
}
