#include <stdio.h>
#include <string.h>

int n, arr[20];

int recur(int w, int bm){
    int h, i, j, tmp, sum=0, c=0, index, bm1, bm2;
    for(i=0, tmp=1; i<=n; i++, tmp<<=1) if(bm&tmp) { sum+=arr[i]; c++; index=i;}
    h = sum/w;

    if(c==1) return w*h == arr[index];
    if(w*h!=sum) return 0;

    for(i=0; i<n; i++){
        if(!(bm&(1<<i))) continue;
        bm1 = (1<<i);
        bm2 = bm & ~(1<<i);
        for(j=1; j<w; j++) if(recur(j, bm1)&&recur(w-j, bm2)) return 1;
        if(recur(w, bm1)&&recur(w, bm2)) return 1;
    }
    return 0;
}

int main(){
    int x, y, i, sum, kase=1;
    while(scanf("%d", &n)>0){
        if(n==0)
            break;
        scanf("%d %d", &x, &y);
        for(i=0, sum=0; i<n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        if(sum>x*y)
            printf("Case %d: No\n", kase++);
        else if(recur(x, ~0))
            printf("Case %d: Yes\n", kase++);
        else
            printf("Case %d: No\n", kase++);
    }

    return 0;
}
