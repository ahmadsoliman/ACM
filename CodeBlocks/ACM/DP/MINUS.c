#include <stdio.h>
#include <string.h>
#include <math.h>

int n, m, nums[105], vals[105][105];

int recur(int s, int e){
    if(s==e) return vals[s][e]=nums[s][e];

    int i;
    for(i=s; i<=e; i++){

    }

}

int main(){
    int t, i,j,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(i=0; i<n; i++) scanf("%d", &nums[i]);

        memset(vals, -1, sizeof vals);
        printf("%d\n", recur(0, n-1));
    }
    return 0;
}

/*
2 3 2 1

12 10 4 3 5
12 6 3 5
12 6 -2
12 8
4

*/
