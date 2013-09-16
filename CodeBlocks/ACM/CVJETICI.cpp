#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int * tree;
int MaxVal;

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int main(){
    int n, i,j, l,r, vl ,vr;
    scanf("%d", &n);

    MaxVal=100010;
    tree = new int[MaxVal+1];
    memset(tree, 0, sizeof(int)*(MaxVal+1));
    //sum range you use read(B) - read(A)
    for(i=0; i<n; i++){
        scanf("%d %d", &l, &r);
        printf("%d\n", ((vl=read(l))+(vr=read(r))));

        update(l, -vl);
        update(l+1, vl);
        update(r, -vr);
        update(r+1, vr);

        update(l+1, 1);
        update(r, -1);
    }
    return 0;
}
