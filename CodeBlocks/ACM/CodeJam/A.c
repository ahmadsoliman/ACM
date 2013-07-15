#include <stdio.h>

char b[4][4];

int main(){
    int t, i, j, gameDone, winner, kase=1;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("o.out", "w", stdout);
    char s[4];
    scanf("%d", &t);
    while(t--){
        gameDone=1;
        for(i=0; i<4; i++){
            scanf("%s", s);
            for(j=0; j<4; j++){
                b[i][j] = s[j];
                if(b[i][j]=='.')gameDone=0;
            }
        }
        winner=-1;//0 == X , 1 == O
        for(i=0; i<4; i++){
            if((b[i][0]=='X'||b[i][0]=='T')&&(b[i][1]=='X'||b[i][1]=='T')
                &&(b[i][2]=='X'||b[i][2]=='T')&&(b[i][3]=='X'||b[i][3]=='T')){
                    winner = 0;
                    break;
                }
            if((b[i][0]=='O'||b[i][0]=='T')&&(b[i][1]=='O'||b[i][1]=='T')
                &&(b[i][2]=='O'||b[i][2]=='T')&&(b[i][3]=='O'||b[i][3]=='T')){
                    winner = 1;
                    break;
                }
        }
        for(i=0; i<4; i++){
            if(winner!=-1)break;
            if((b[0][i]=='X'||b[0][i]=='T')&&(b[1][i]=='X'||b[1][i]=='T')
                &&(b[2][i]=='X'||b[2][i]=='T')&&(b[3][i]=='X'||b[3][i]=='T')){
                    winner = 0;
                    break;
                }
            if((b[0][i]=='O'||b[0][i]=='T')&&(b[1][i]=='O'||b[1][i]=='T')
                &&(b[2][i]=='O'||b[2][i]=='T')&&(b[3][i]=='O'||b[3][i]=='T')){
                    winner = 1;
                    break;
                }
        }
        if(winner==-1 && (b[0][0]=='X'||b[0][0]=='T')&&(b[1][1]=='X'||b[1][1]=='T')
            &&(b[2][2]=='X'||b[2][2]=='T')&&(b[3][3]=='X'||b[3][3]=='T')){
                winner = 0;
            }
        if(winner==-1 && (b[0][0]=='O'||b[0][0]=='T')&&(b[1][1]=='O'||b[1][1]=='T')
            &&(b[2][2]=='O'||b[2][2]=='T')&&(b[3][3]=='O'||b[3][3]=='T')){
                winner = 1;
            }
        if(winner==-1 && (b[0][3]=='X'||b[0][3]=='T')&&(b[1][2]=='X'||b[1][2]=='T')
            &&(b[2][1]=='X'||b[2][1]=='T')&&(b[3][0]=='X'||b[3][0]=='T')){
                winner = 0;
            }
        if(winner==-1 && (b[0][3]=='O'||b[0][3]=='T')&&(b[1][2]=='O'||b[1][2]=='T')
            &&(b[2][1]=='O'||b[2][1]=='T')&&(b[3][0]=='O'||b[3][0]=='T')){
                winner = 1;
            }
        printf("Case #%d: ", kase++);
        if(winner==0) printf("X won");
        else if(winner==1) printf("O won");
        else if(gameDone) printf("Draw");
        else printf("Game has not completed");
        //if(t>0)
        printf("\n");
    }
}
