#include <stdio.h>

short t, i,j,k,l, kase=1, R, C, H, K, T, grid[101][101], vectors[501][501], X[501], dot[101][101][501], sumDot[101][101];
int maxScore, score;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &R, &C, &H, &K, &T);
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
                scanf("%d", &grid[i][j]);

        for(i=0; i<T; i++){
            scanf("%d", &X[i]);
            for(j=0; j<K; j++) scanf("%d", &vectors[i][j]);
        }

        maxScore=0;
        for(i=0; i<R; i++){
            for(j=0; j<C; j++){
                sumDot[i][j]=0;
                for(k=0; k<T; k++){
                    sumDot[i][j]+=X[k]*(dot[i][j][k]=dot[i-1][j][k]+dot[i][j-1][k]-dot[i-1][j-1][k]+vectors[k][grid[i][j]-1]);
                }
                score = H + sumDot[i][j];
                maxScore=(score>maxScore)?score:maxScore;
            }
        }

        printf("Case #%d:\n%d\n", kase++, maxScore);
    }
    return 0;
}
