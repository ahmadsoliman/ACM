#include <stdio.h>
#include <string.h>

char s[305], arr[305][305][305], minS[305], tmp[305];
int lenArr[305][305];

int main(){
    scanf("%s", &s);

    int len=0,i,j,k,minLen,l1,l2,tmpLen;

    while(s[len]){
        arr[len][len][0]=s[len];
        lenArr[len][len]=1;
        len++;
    }
    len++;

    for(k=1; k<len; k++){//diagonal
        for(i=0; i+k<len; i++){//i row, i+k column
            strcpy(minS, arr[i][i]);
            strcat(minS, arr[i+1][i+k]);
            minLen=lenArr[i][i]+lenArr[i+1][i+k];
            if(minLen==3 && minS[0]==minS[2]){
                minS[0]=minS[1];
                minS[1]='\0';
                minLen=1;
            }
            for(j=i+1; j<i+k; j++){
                tmpLen=lenArr[i][j]+lenArr[j+1][i+k];
                if(tmpLen>3&&tmpLen>=minLen)continue;
                strcpy(tmp , arr[i][j]);
                strcat(tmp , arr[j+1][i+k]);
                if(tmpLen==3&&tmp[0]==tmp[2]){tmp[0]=tmp[1];tmp[1]='\0';tmpLen=1;}
                if(tmpLen<minLen){
                    strcpy(minS, tmp);
                    minLen=tmpLen;
                }
            }
            strcpy(arr[i][i+k], minS);
            lenArr[i][i+k]=minLen;
        }
    }
    printf("%d\n", strlen(arr[0][len-1]));
    return 0;
}
