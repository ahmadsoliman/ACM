#include <stdio.h>
#include <string.h>


typedef struct {
    int row, col;
    long long cost;
} matrix;

int n, rows[100], cols[100], choices[100][100];
matrix dp[100][100];

matrix recur(int l, int r){
    if(l==r){
        matrix res;
        res.row = rows[l];
        res.col = cols[l];
        res.cost = 0;
        choices[l][r] = -2;
        return res;
    }

    if(dp[l][r].cost!=-1)
        return dp[l][r];

    if(r-l==1) {
        matrix res;
        res.row = rows[l];
        res.col = cols[r];
        res.cost = rows[l]*cols[r]*cols[l];
        choices[l][r] = -1;
        return res;
    }

    int i, minI;
    long long cur;
    matrix a, b, min;
    min.cost = 1000000000;
    for(i=l;i<r;i++){
        a = recur(l, i);
        b = recur(i+1, r);
        cur = a.cost + b.cost + a.row*b.col*a.col;
        if(cur<min.cost){
            min.row = a.row;
            min.col = b.col;
            min.cost = cur;
            minI = i;
        }
    }
    choices[l][r] = minI;
    return dp[l][r] = min;
}

char tree[100][10];

void fillTree(int i, int l, int r){
    if(choices[l][r]==-2){
        sprintf(tree[i], "A%d", l+1);
    }else if(choices[l][r]==-1){
        sprintf(tree[i], "x");
        sprintf(tree[2*i], "A%d", l+1);
        sprintf(tree[2*i+1], "A%d", l+2);
    }else{
        sprintf(tree[i], "x");
        fillTree(2*i, l, choices[l][r]);
        fillTree(2*i+1, choices[l][r]+1, r);
    }
}

void printTree(int i){
    if(strcmp(tree[i], "x")==0){
        printf("(");
        printTree(2*i);
        printf(" x ");
        printTree(2*i+1);
        printf(")");
    }else{
        printf(tree[i]);
    }
}

int main(){
    int i,j, kase=1;
    while(scanf("%d", &n)>0){
        if(n==0) break;
        for(i=0; i<n; i++) {
            scanf("%d", &rows[i]);
            scanf("%d", &cols[i]);
        }
        matrix tmp;
        tmp.cost = -1;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                dp[i][j] = tmp;
            }
        }
        tmp = recur(0, n-1);
        fillTree(1, 0, n-1);
        printf("Case %d: ", kase++);
        printTree(1);
        printf("\n");
    }
    return 0;
}
