#include <stdio.h>

#define min(x,y) ((x<y)?x:y)
#define INF 1000000000

#define N 1000000
#define SIZE 2097152

int A[N], T[SIZE], nElems;

void initialize(int node, int b, int e){
    if(b == e)
        T[node] = A[b];
    else{
        initialize(2*node, b, (b+e)/2);
        initialize(2*node+1, (b+e)/2+1, e);

        T[node] = min(T[2*node], T[2*node+1]);
    }
}

void update(int index, int v){
    index += nElems - 1;
    T[index] = v;
    while(index > 1){
        index >>= 1;
        T[index] = min(T[index << 1], T[(index << 1) + 1]);
    }
}

int kth(int node, int k){
    if(node>=nElems)
        return node - nElems;
    int p1 = T[node << 1];
    if(p1 >= k)
        return kth(node << 1, k);
    return kth((node << 1) + 1, k-p1);
}

int kth(int k){
    if(k > T[1])
        return -1;
    return kth(1, k);
}

int main(){

    return 0;
}
