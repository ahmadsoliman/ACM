#include <stdio.h>
#include <string.h>

int n, N, arr[15010], tree[30010];

int query(int index, int a, int b, int i, int j){
    if(a>=i && b<=j) return tree[index];
    if(b<i || a>j) return 0;
    return query(2*index, a, (a+b)/2, i,  j) + query(2*index+1, (a+b)/2+1, b, i, j);
}

int recur(int i, int k){
    if(k==1) return query(1, 0, N, i, n);
   // if(i==n) return 0;
    int j, minC=1000000000, curC, a;
    for(j=i; j<=n; j++){
        curC = recur(j+1, k-1);
        a = query(1, 0, N, i, j);
        if(a>curC) curC = a;
        if(curC<minC) minC = curC;
    }
    return minC;
}

int main(){
    int t, i, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        memset(tree, 0, sizeof tree);
        N=1;
        while(N<n) N<<=1;
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);
            tree[N+i] = arr[i];
        }
        for(i=N-1; i>0; i--){
            tree[i] = tree[2*i]+tree[2*i+1];
        }
        printf("%d\n", recur(0, k));
    }
    return 0;
}
