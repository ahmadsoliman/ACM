#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

#define inboard(x,y) (x>=0&&x<N&&y>=0&&y<M)
#define EPS 1e-9

typedef struct soldier {
    int player, role, strength;

    soldier& operator =(const soldier &o){
        if(this == &o)
            return *this;
        this->player=o.player;
        this->role=o.role;
        this->strength=o.strength;
        return *this;
    }
} ;

int N, M, S[3], type[10][10], maxScore,
    moves[4][2]={{1,0},{0,1},{-1,0},{0,-1}},
    attacks[3][12][2]={{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}},
                       {{1,0},{0,1},{-1,0},{0,-1}},
                       {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}, {2,0},{0,2},{-2,0},{0,-2}}},
    attackLen[3]={8,4,12};
double attackFactor[3][3]={{1.0,0.5,2.0},{2.0,1.0,0.5},{0.5,2.0,1.0}};

int vis[6][6];
vector< vector<soldier> > curboard;
vector< pair<int,int> > curmoves;
void getMoves(int x, int y, int player, int role, int pace){
    vis[x][y]=1;
    if(curboard[x][y].player==-1) curmoves.push_back(make_pair(x,y));
    if(--pace<0) return;
    int i, dx, dy;
    for(i=0; i<4; i++){
        dx = x+moves[i][0]; dy = y+moves[i][1];
        if(inboard(dx,dy)&&!vis[dx][dy]&&type[dx][dy]!=2&&!(role==1&&type[dx][dy]==1)&&player!=curboard[dx][dy].player)
            getMoves(dx, dy, player, role, pace);
    }
}

void recur(vector< vector<soldier> > board, int turn, int K){
    int i, j, c1=0, c2=0;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(board[i][j].player==0)c1++;
            else if(board[i][j].player==1)c2++;
        }
    }

    if(c1==0||c2==0||K==0){
        int i, j, score=0;
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++){
                if(board[i][j].player==0) score+=board[i][j].strength;
                else if(board[i][j].player==1) score-=board[i][j].strength;
            }
        }
        if(score>maxScore) maxScore=score;
    }
    int k,l, x,y, dx,dy, role;
    vector< vector<soldier> > newboard, newboard2;
    soldier emptys;
    emptys.player=-1;
    emptys.strength=emptys.role=0;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(board[i][j].player!=turn) continue;
            role = board[i][j].role;
            curmoves.clear();
            curboard=board;
            getMoves(i,j, turn, role, S[role]);
            for(k=0; k<curmoves.size(); k++){
                x=curmoves[k].first; y=curmoves[k].second;
                newboard=board;
                newboard[x][y]=newboard[i][j];
                newboard[i][j]=emptys;
                recur(newboard, !turn, K-1);
                for(l=0; l<attackLen[role]; l++){
                    dx=x+attacks[role][l][0];
                    dy=y+attacks[role][l][1];
                    if(inboard(dx,dy)&&newboard[dx][dy].player!=-1&&newboard[dx][dy].player!=turn){
                        newboard2=newboard;
                        newboard2[dx][dy].strength-=(int)ceil(newboard[x][y].strength*attackFactor[role][newboard[dx][dy].role]);
                        if(newboard2[dx][dy].strength<=0) newboard2[dx][dy]=emptys;
                        recur(newboard2, !turn, K-1);
                    }
                }
            }
        }
    }
}

int main(){
    int K, i,j,x,y, T;
    vector< vector<soldier> > board;
    while(scanf("%d %d %d", &N, &M, &K)>0){
        if(N==0&&M==0&&K==0) return 0;
        soldier s1;
        s1.player=-1;
        board.clear();
        for(i=0; i<N; i++) {
            board.push_back(vector<soldier>());
            for(j=0; j<M; j++) {
                board[i].push_back(s1);
                scanf("%d", &type[i][j]);
            }
        }
        scanf("%d %d %d %d", &T, &S[0], &S[1], &S[2]);
        for(i=0; i<T; i++){
            soldier s;
            scanf("%d %d %d %d %d", &x, &y, &s.player, &s.strength, &s.role);
            board[x-1][y-1] = s;
        }
        maxScore=-200000000;
        recur(board, 0, K);
        printf("%d\n", maxScore);
    }
    return 0;
}
