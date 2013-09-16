#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int * tree[1030];
int MaxVal;

int read(int idx, int idy){
    int sum = 0, tmp=idy;
    while (idx > 0){
        idy=tmp;
        while( idy > 0){
            sum += tree[idx][idy];
            idy -= (idy & -idy);
        }
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int idy ,int val){
    int tmp=idy;
    while (idx <= MaxVal) {
        idy=tmp;
        while(idy <= MaxVal) {
            tree[idx][idy] += val;
            idy += (idy & -idy);
        }
        idx += (idx & -idx);
    }
}

int mat[1030][1030];
char query[50];

int main(){
    int i,j, k, n, t, x,y, x1,x2,y1,y2, num, sum;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        MaxVal=n;

        for(i=0; i<=n; i++) {
            tree[i] = new int[n+1];
            memset(tree[i], 0, sizeof(int)*(n+1));
        }
//sum range you use read(B) - read(A)

        memset(mat, 0, sizeof mat);
        while(1){
            scanf("%s", query);
            if(strcmp(query, "SET")==0){
                scanf("%d %d %d", &x, &y, &num);
                x++; y++;
                update(x, y, num-mat[x][y]);
                mat[x][y]=num;
            }else if(strcmp(query, "SUM")==0){
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++;y1++;x2++;y2++;
                sum=read(x2, y2)-read(x2, y1-1)-read(x1-1, y2)+read(x1-1,y1-1);
                printf("%d\n", sum);
            }else if(strcmp(query, "END")==0) break;
        }
    }
    return 0;
}
