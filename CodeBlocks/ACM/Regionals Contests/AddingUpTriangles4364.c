#include <stdio.h>

int main(){
    int n, kase=1, i,j,k,l, v, maxv, triangle[410][810];

    while(scanf("%d", &n)>0){
        if(n==0) return 0;

        maxv = -2000000000;
        for(i=0; i<n; i++){
            l = (i<<1)+1;
            for(j=0; j<l; j++){
                scanf("%d", &triangle[i][j]);
                if(triangle[i][j]>maxv) maxv = triangle[i][j];
                if(j>0) triangle[i][j]+=triangle[i][j-1];
            }
        }


        for(i=0; i<n; i++){
            k = (i<<1)+1;
            for(j=0; j<k; j++){
                for(l=0, v=0; l+i<n; l++){
                    v+=triangle[i+l][j+2*l]-((j>0)?triangle[i+l][j-1]:0);
                    if(v>maxv) maxv = v;
                }
            }
        }

        for(i=n-1; i>=0; i--){
            k = (i<<1)+1;
            for(j=0; j<k; j++){
                for(l=0, v=0; i>=l && j<((i-l)<<1)+1; l++){
                    v+=triangle[i-l][j]-((j>(l<<1)+1)?triangle[i-l][j-(l<<1)-1]:0);
                    if(v>maxv) maxv = v;
                }
            }
        }

        printf("%d. %d\n", kase++, maxv);
    }
    return 0;
}

/*
5
            -1
         -1 -1 -1
      -1 -1 -1 -1 -1
   -1 -1 -1 -1  1  1  1
-1 -1 -1 -1 -1 -1  1 -1 -1

*/
