#include <stdio.h>
#include <limits.h>

#define max(x,y) ((x>y)?x:y)

typedef long long ll;

int kase=1, R, C, H, K, T, grid[105][105], vectors[505][505], X[505];
ll a[105][105], s, S, t;
int row, x, i;

#define MIN -20000000000000ll
ll columnSum[105];
ll kadane2D(int R, int C){
    s=MIN,S=MIN;
    for(row = 0; row<R; row++) {
        for(i=0; i<C; i++) columnSum[i] = 0;
        for(x = row; x<R; x++) {
            s = MIN, t = 0;
            for(i=0; i<C; i++) {
                columnSum[i]+=a[x][i];
                t+=columnSum[i];
                s = max(s, t);
                if(t<0) t = 0;
            }
            S = max(S, s);
        }
    }
    return S;
}

int main(){
    int t, i,j,k,l;
    scanf("%d", &t);
    ll score;
    while(t--){
        scanf("%d %d %d %d %d", &R, &C, &H, &K, &T);
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
                scanf("%d", &grid[i][j]);
        for(i=0; i<T; i++){
            scanf("%d", &X[i]);
            for(j=0; j<K; j++) scanf("%d", &vectors[i][j]);
        }
        for(i=0; i<R; i++){
            for(j=0; j<C; j++){
                a[i][j]=0;
                for(k=0; k<T; k++){
                    a[i][j]+=X[k]*vectors[k][grid[i][j]-1];
                }
            }
        }
        score=kadane2D(R, C)+H;
        printf("Case #%d:\n%lld\n", kase++, score);
    }
    return 0;
}
