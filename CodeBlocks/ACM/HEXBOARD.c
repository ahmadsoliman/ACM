#include <stdio.h>

char board[90][90];

int main(){
    int n, len, middle, i , j;
    while(scanf("%d",&n)>0){
        if(n==-1)
            break;
        len = n*4-1;
        middle=len/2;

        //spaces
        for(i=0; i<len; i++){
            for(j=0; j<len; j++){
                board[i][j]=' ';
            }
        }
        //underscores
        for(i=0; i<len/3; i++){
            for(j=i; j<len-i; j+=2){
                board[j][middle-2*i]=board[j][middle+2*i]='_';

                if(j+1<len-i)
                    board[j+1][middle-2*i-1]=board[j+1][middle+2*i-1]='/';
                if(j+1<len-i)
                    board[j+1][middle-2*i+1]=board[j+1][middle+2*i+1]='\\';

                if(j>i)
                    board[j][middle-2*i-1]=board[j][middle+2*i-1]='\\';
                if(j>i)
                    board[j][middle-2*i+1]=board[j][middle+2*i+1]='/';
            }
        }

        for(i=0; i<len; i++){
            for(j=0; j<len; j++){
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
        printf("***\n");
    }
    return 0;
}
