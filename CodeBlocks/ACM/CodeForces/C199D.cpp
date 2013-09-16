#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

#define MOD 1000000007

char grid[3][10010];

int n, dp[10010][10][10][2], x,y;

int recur(int i, int col1, int col2, int done){
    if(i==n) {
        if(done) return 1;
        else return 0;
    }
    if(dp[i][col1][col2][done]!=-1) return dp[i][col1][col2][done];
    for(int j=0; j<3; j++){
        if(grid[j][i]!='.') col1 |= (1<<j);
        if(grid[j][i+1]!='.') col2 |= (1<<j);
    }
    int c=0;
    if(!done){
        if(i==x-2 && grid[y][i]=='.'&&grid[y][i+1]=='.'&&!(col1&(1<<y))&&!(col2&(1<<y))) c = recur(i, col1|(1<<y), col2|(1<<y), 1);
        if(i==x+1 && grid[y][i]=='.'&&grid[y][i+1]=='.'&&!(col1&(1<<y))&&!(col2&(1<<y))) c = recur(i, col1|(1<<y), col2|(1<<y), 1);
        if(y==0&&i==x){
            if(grid[1][i]=='.'&&grid[2][i]=='.'&&!(col1&(1<<1))&&!(col1&(1<<2))) c = recur(i, col1|(1<<1)|(1<<2), col2, 1);
        }
        if(y==2&&i==x){
            if(grid[0][i]=='.'&&grid[1][i]=='.'&&!(col1&(1<<0))&&!(col1&(1<<1))) c = recur(i, col1|(1<<0)|(1<<1), col2, 1);
        }
        if(y==0&&i==x-1){
            if(grid[1][i+1]=='.'&&grid[2][i+1]=='.'&&!(col2&(1<<1))&&!(col2&(1<<2))) c = recur(i, col1, col2|(1<<1)|(1<<2), 1);
        }
        if(y==2&&i==x-1){
            if(grid[0][i]=='.'&&grid[1][i]=='.'&&!(col2&(1<<0))&&!(col2&(1<<1))) c = recur(i, col1, col2|(1<<1)|(1<<2), 1);
        }
    }

    for(int j=0; j<3; j++){
        if(grid[j][i]=='.' && !(col1&(1<<j))){
            int a=0,b=0;
            if(j<2 && grid[j+1][i]=='.' && !(col1&(1<<(j+1)))) a = recur(i, col1|(1<<j)|(1<<(j+1)), col2, done);
            if(i<n-1 && grid[j][i+1]=='.' && !(col2&(1<<(j)))) b = recur(i, col1|(1<<j), col2|(1<<j), done);
            return dp[i][col1][col2][done]=(a+b+c)%MOD;
        }
    }
    return dp[i][col1][col2][done]=(c+recur(i+1, col2, 0, done))%MOD;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<3; i++){
        scanf("%s", grid[i]);
        for(int j=0; j<n; j++) if(grid[i][j]=='O') {y=i; x=j;}
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(0, 0, 0, 0));
    return 0;
}
