/*j ID: ahmadad1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

int cols[20], isColFree[20], board[20][20], rdfree[30], ldfree[30];
int n, cnt;

void print(){
    printf("%d", cols[0]+1);
    for(int i=1; i<n; i++) printf(" %d", cols[i]+1);
    printf("\n");
}

int check(int row, int col){
    if(isColFree[col] || ldfree[row+col] || rdfree[row-col+n]) return 0;
    return 1;
}

void recur(int row){
    if(row==n){
        if(cnt<3) print();
        cnt++;
        return;
    }

    for(int i=0; i<n; i++){
        if(check(row, i)){
            board[row][i]=1;
            cols[row]=i;
            isColFree[i]=1;
            ldfree[row+i]=1;
            rdfree[row-i+n]=1;

            recur(row+1);
            ldfree[row+i]=0;
            rdfree[row-i+n]=0;
            isColFree[i]=0;
            board[row][i]=0;
        }
    }

}

int main() {
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    int i,j,k,l, r;

    int a,b, num=0;
    scanf("%d", &n);

    memset(board, 0, sizeof board);
    memset(isColFree, 0, sizeof isColFree);
    memset(ldfree, 0, sizeof ldfree);
    memset(rdfree, 0, sizeof rdfree);

    cnt=0;
    recur(0);
    printf("%d\n", cnt);

    return 0;
}
