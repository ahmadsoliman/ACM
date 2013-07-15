#include <stdio.h>

int main(){
    int i,j,k,l,m,tmp, arr[3][3];
    while(1){
        if(scanf("%d", &arr[0][0])<1) break;
        scanf("%d", &arr[0][1]);
        scanf("%d", &arr[0][2]);
        for(i=1; i<3; i++) for(j=0; j<3; j++) scanf("%d", &arr[i][j]);
        for(j=0; j<3; j++){
            tmp = arr[j][1];
            arr[j][1] = arr[j][2];
            arr[j][2] = tmp;
        }
        int c, min=1000000000, res[3];
        for(i=0; i<3; i++){//first
            for(j=0; j<3; j++){//second
                for(k=0; k<3; k++){//third
                    if(i==j||i==k||j==k) continue;
                    c=0;
                    for(l=0; l<3; l++){//color
                        for(m=0; m<3; m++){//bin
                            if(!((m==0&&l==i)||(m==1&&l==j)||(m==2&&l==k)))
                                c += arr[m][l];
                        }
                    }
                    if(c<min){
                        res[0] = i;
                        res[1] = j;
                        res[2] = k;
                        min = c;
                    }
                }
            }
        }
        char resS[4];
        for(i=0; i<3; i++){
            switch(res[i]){
                case 0: resS[i] = 'B';break;
                case 1: resS[i] = 'C';break;
                case 2: resS[i] = 'G';break;
            }
        }
        resS[3] = '\0';
        printf("%s %d\n", resS, min);
    }
    return 0;
}
