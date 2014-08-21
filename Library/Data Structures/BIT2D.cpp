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
