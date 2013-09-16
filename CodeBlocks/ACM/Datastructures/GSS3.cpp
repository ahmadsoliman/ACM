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

    return 0;
}
