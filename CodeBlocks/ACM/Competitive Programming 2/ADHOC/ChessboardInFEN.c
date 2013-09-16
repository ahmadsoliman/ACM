#include <stdio.h>
#include <string.h>

int main(){
    char board[8][8], in[100], element[9];
    char * pch;
    int attacked[8][8], i,j,k,r, l, c;
    while(gets(in)!=NULL){
        memset(attacked, 0, sizeof attacked);
        pch = strtok (in, "/");
        i=0;
        while (pch != NULL) {
            strncpy(element, pch, sizeof element - 1);
            l = strlen(element);

            j=0;
            for(k=0; k<l; k++)
                if(element[k]>='0'&&element[k]<='9') for(r=0; r<element[k]-'0'; r++) board[i][j++] = '*';
                else {
                    attacked[i][j] = 1;
                    board[i][j++] = element[k];
                }
            i++;
            pch = strtok (NULL, "/");
        }
        if(i==0) continue;

        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                if(board[i][j]=='*') continue;
                if(board[i][j]=='p') {
                    if(i<7&&j<7) attacked[i+1][j+1]=1;
                    if(i<7&&j>0) attacked[i+1][j-1]=1;
                } else if(board[i][j]=='P') {
                    if(i>0&&j<7) attacked[i-1][j+1]=1;
                    if(i>0&&j>0) attacked[i-1][j-1]=1;
                }  else if(board[i][j]=='n'||board[i][j]=='N') {
                    if(i<7&&j<6) attacked[i+1][j+2]=1;
                    if(i<6&&j<7) attacked[i+2][j+1]=1;
                    if(i<7&&j>1) attacked[i+1][j-2]=1;
                    if(i<6&&j>0) attacked[i+2][j-1]=1;
                    if(i>0&&j<6) attacked[i-1][j+2]=1;
                    if(i>1&&j<7) attacked[i-2][j+1]=1;
                    if(i>1&&j>0) attacked[i-2][j-1]=1;
                    if(i>0&&j>1) attacked[i-1][j-2]=1;
                } else if(board[i][j]=='k'||board[i][j]=='K'){
                    if(i<7) attacked[i+1][j]=1;
                    if(i<7&&j<7) attacked[i+1][j+1]=1;
                    if(i<7&&j>0) attacked[i+1][j-1]=1;
                    if(j<7) attacked[i][j+1]=1;
                    if(i>0&&j<7) attacked[i-1][j+1]=1;
                    if(i>0) attacked[i-1][j]=1;
                    if(i>0&&j>0) attacked[i-1][j-1]=1;
                    if(j>0) attacked[i][j-1]=1;
                }

                if(board[i][j]=='b'||board[i][j]=='B'||board[i][j]=='q'||board[i][j]=='Q') {
                    for(k=i+1,r=j+1; k<8 && r<8; k++, r++) {
                        if(board[k][r]!='*') break;
                        attacked[k][r]=1;
                    }
                    for(k=i-1,r=j-1; k>=0 && r>=0; k--, r--) {
                        if(board[k][r]!='*') break;
                        attacked[k][r]=1;
                    }
                    for(k=i+1,r=j-1; k<8 && r>=0; k++, r--) {
                        if(board[k][r]!='*') break;
                        attacked[k][r]=1;
                    }
                    for(k=i-1,r=j+1; k>=0 && r<8; k--, r++) {
                        if(board[k][r]!='*') break;
                        attacked[k][r]=1;
                    }
                }

                if(board[i][j]=='r'||board[i][j]=='R'||board[i][j]=='q'||board[i][j]=='Q') {
                    for(k=j+1; k<8; k++) {
                        if(board[i][k]!='*') break;
                        attacked[i][k]=1;
                    }
                    for(k=j-1; k>=0; k--) {
                        if(board[i][k]!='*') break;
                        attacked[i][k]=1;
                    }
                    for(k=i+1; k<8; k++) {
                        if(board[k][j]!='*') break;
                        attacked[k][j]=1;
                    }
                    for(k=i-1; k>=0; k--) {
                        if(board[k][j]!='*') break;
                        attacked[k][j]=1;
                    }
                }
            }
        }

        for(i=0, c=0; i<8; i++) for(j=0; j<8; j++) c+=attacked[i][j];
        printf("%d\n", 64-c);
    }
    return 0;
}
