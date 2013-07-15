#include <stdio.h>
#include <math.h>

int main(){
    int i, cubes[1001], isCube[1000000];
    for(i=1; i<1001; i++){
        cubes[i]=i*i*i;
        if(cubes[i]<1000000)
            isCube[cubes[i]]=1;
    }
    int n, x3;
    while(scanf("%d", &n)>0){
        if(n==0)
            break;
        for(i=1; i<1001; i++){
            x3 = n+cubes[i];
            if(x3<1000000){
                if(isCube[x3]){
                    printf("%d %d\n", (int)(pow(x3, 1.0/3.0)+1e-9), i);
                    break;
                }
            }else{

            }
        }
        if(i==1001)
            printf("No solution\n");
    }

    return 0;
}
