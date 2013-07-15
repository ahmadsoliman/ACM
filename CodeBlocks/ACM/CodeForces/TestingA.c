#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int k;

int main(){
    scanf("%d", &k);
    if(k%2==1)
        printf("-1\n");
    else{
        int i, j, l, i2, j2, l2;
        for(l=0; l<k; l++){
            for(i=0; i<k; i++){
                for(j=0; j<k; j++){
                    i2 = i/2;
                    j2=j/2;
                    l2=l/2;
                    if(i2%2==j2%2 && i2%2==l2%2){
                        if(l%2==0)
                            printf("w");
                        else
                            printf("b");
                    }else{
                        if(l%2==0)
                            printf("w");
                        else
                            printf("b");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
