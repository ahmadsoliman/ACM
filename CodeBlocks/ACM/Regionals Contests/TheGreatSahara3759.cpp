#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

#define UP 0
#define DOWN 1
#define PLAYER1 1
#define PLAYER2 2

using namespace std;

int orien[15][15], num[15][15], p1[10], p2[10], board[15][15], x11[10], y11[10], x2[10], y2[10];

int inboard(int i, int j){
    if(i<0 || i>5) return 0;
    if(i==0 || i==5) return j>=2 && j<=8;
    if(i==1 || i==4) return j>=1 && j<=9;
    return j>=0 && j<=10;
}

int check(){
    int i, f=0;
    for(i=0; i<6; i++){
        //if(i==5) printf("a1");
        if(inboard(x2[i], y2[i]+1) && board[x2[i]][y2[i]+1]==0) continue;
        //if(i==5) printf("a2");
        if(inboard(x2[i], y2[i]-1) && board[x2[i]][y2[i]-1]==0) continue;
        //if(i==5) printf("a3");
        if(orien[x2[i]][y2[i]]==UP && inboard(x2[i]+1, y2[i]) && board[x2[i]+1][y2[i]]==0) continue;
        //if(i==5) printf("a4");
        if(orien[x2[i]][y2[i]]==DOWN && inboard(x2[i]-1, y2[i]) && board[x2[i]-1][y2[i]]==0) continue;
        //printf("%d\n", i);
        //if(i==5) printf("a5");
        f=1; break;
    }
    return f;
}

void print(){
    for(int i=0; i<6; i++){
        for(int j=0; j<11; j++){
            if(!inboard(i, j)) continue;
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i,j,k,l, o, f, kase=1, x,y;

    k=1;
    for(i=0; i<3; i++){
        if(i==0) j=2;
        else if(i==1) j=1;
        else if(i==2) j=0;
        o=UP;
        for(; j<11; j++){
            if(!inboard(i,j)) break;
            orien[i][j]=o;
            o=!o;
            num[i][j]=k++;
        }
    }
    for(i=3; i<6; i++){
        if(i==3) j=0;
        else if(i==4) j=1;
        else if(i==5) j=2;
        o=DOWN;
        for(; j<11; j++){
            if(!inboard(i,j)) break;
            orien[i][j]=o;
            o=!o;
            num[i][j]=k++;
        }
    }

    while(scanf("%d", &p1[0])>0){
        if(p1[0]==0) return 0;

        for(i=1; i<6; i++) scanf("%d", &p1[i]);
        for(i=0; i<6; i++) scanf("%d", &p2[i]);

        memset(x11, 0, sizeof x11);
        memset(y11, 0, sizeof y11);
        memset(x2, 0, sizeof x2);
        memset(y2, 0, sizeof y2);
        memset(board, 0, sizeof board);
        for(i=0; i<6; i++){
            for(j=0; j<11; j++){
                if(!inboard(i,j)) continue;
                for(k=0; k<6; k++) {
                    if(num[i][j]==p1[k]) board[i][j]=PLAYER1, x11[k]=i, y11[k]=j;
                    if(num[i][j]==p2[k]) board[i][j]=PLAYER2, x2[k]=i, y2[k]=j;
                }
                //printf("%d ", orien[i][j]);
            }
            //printf("\n");
        }

        f=0;
        for(k=0; k<6; k++){
            x=x11[k], y=y11[k];
            if(inboard(x, y+1) && board[x][y+1]==0){
                board[x][y]=0;
                board[x][y+1]=PLAYER1;

                f=check();
                if(f) break;

                board[x][y]=PLAYER1;
                board[x][y+1]=0;
            }
            //if(k==2) printf("\n%d\n", inboard(x, y-1));
            if(inboard(x, y-1) && board[x][y-1]==0){
                board[x][y]=0;
                board[x][y-1]=PLAYER1;

                f=check();
                if(f) break;

                board[x][y]=PLAYER1;
                board[x][y-1]=0;
            }
            if(orien[x][y]==UP && inboard(x+1, y) && board[x+1][y]==0){
                board[x][y]=0;
                board[x+1][y]=PLAYER1;

                f=check();
                if(f) break;

                board[x][y]=PLAYER1;
                board[x+1][y]=0;
            }else if(orien[x][y]==DOWN && inboard(x-1, y) && board[x-1][y]==0){
                board[x][y]=0;
                board[x-1][y]=PLAYER1;

                f=check();
                if(f) break;

                board[x][y]=PLAYER1;
                board[x-1][y]=0;
            }
           // print();
        }
        //printf("%d\n", k);
        if(f) printf("%d. TRAPPED\n", kase++);
        else printf("%d. FREE\n", kase++);
    }
    return 0;
}
/*
1 8 11 48 49 50    9 22 23 24 25 26

1 4 40 41 42 43    2 21 22 23 24 25

*/
