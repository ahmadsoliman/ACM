#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int * tree[1030];
int MaxVal;

int read(int x, int idx){
    long long sum = 0;
    while (idx > 0){
        sum += tree[x][idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int x, int idx ,int val){
    while (idx <= MaxVal){
        tree[x][idx] += val;
        idx += (idx & -idx);
    }
}

int mat[1030][1030];
char query[50];

int main(){
    MaxVal=1030;

    int i,j, k, n, t, x,y, x1,x2,y1,y2, num;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        for(i=0; i<n; i++) tree[i] = new int[n+1];
        memset(tree, 0, sizeof(int)*(n+1));

//sum range you use read(B) - read(A)

        while(1){
            scanf("%s", query);
            if(strcmp(query, "SET")==0){
                scanf("%d %d %d", &x, &y, &num);

            }else if(strcmp(query, "SUM")==0){
                scanf("%d %d %d", &x1, &y1, &x2, &y2);

            }else if(strcmp(query, "END")==0) break;

        }
    }
    return 0;
}
