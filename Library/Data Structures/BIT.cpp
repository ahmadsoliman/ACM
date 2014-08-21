#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

long long * tree;
long long MaxVal;

long long read(long long idx){
    long long sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(long long idx ,long long val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

struct BIT{
    long long * tree;
    long long MaxVal;

    BIT(int n){
        MaxVal = n;
        tree = new long long[MaxVal+1];
        memset(tree, 0, sizeof(long long)*(MaxVal+1));
    }

    long long read(long long idx){
        long long sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(long long idx ,long long val){
        while (idx <= MaxVal){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
};

int main(){
    int t, i,j, n;
    MaxVal = n;
    tree = new long long[MaxVal+1];
    memset(tree, 0, sizeof(long long)*(MaxVal+1));
    return 0;
}
