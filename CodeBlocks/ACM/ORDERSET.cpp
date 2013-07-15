#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;

#define min(x,y) ((x<y)?x:y)
#define INF 1000000000

#define N 1000000
#define SIZE 2097152

int tree[SIZE], nElems;

void update(int index, int v){
    index += nElems ;
    tree[index] = v;
    while(index > 1){
        index >>= 1;
        tree[index] = tree[index << 1] + tree[(index << 1) + 1];
    }
}

int kth(int node, int k){
    if(node>=nElems)
        return node - nElems;
    int p1 = tree[node << 1];
    if(p1 >= k)
        return kth(node << 1, k);
    return kth((node << 1) + 1, k-p1);
}

int kth(int k){
    if(k > tree[1])
        return -1;
    return kth(1, k);
}

int count(int node, int b, int e, int i, int j){
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int p1, p2;

    p1 = count(2*node, b, (b+e)/2, i, j);
    p2 = count(2*node+1, (b+e)/2+1, e, i, j);
    return p1 + p2;
}

int count(int i, int j){
    if(j<i)
        return 0;
    return count(1, 0, nElems-1, i, j);
}

char Q1[200005];
int Q2[200005], M[200005];

int main(){
    int Q, x, i, j, index, v;
    char c;
    scanf("%d\n", &Q);

    set<int> T;
    for(i=0; i<Q; i++){
        if(i<Q-1)scanf("%c %d\n", &Q1[i], &Q2[i]);
        else scanf("%c %d", &Q1[i], &Q2[i]);
        if(Q1[i]!='K'){
            T.insert(Q2[i]);
        }
    }

    nElems = 1;
    while(nElems < T.size()) nElems <<= 1;

    map<int, int> H;
    index=0;
    set<int>::iterator itr=T.begin();
    while(itr!=T.end()){
        M[index]=*itr;
        H.insert(make_pair(M[index], index));
        index++;
        itr++;
    }

    for(i=0; i<Q; i++){
        switch(Q1[i]){
        case 'I':
            update(H.find(Q2[i])->second, 1);
            break;
        case 'D':
            update(H.find(Q2[i])->second, 0);
            break;
        case 'K':
            v = kth(Q2[i]);
            if(v==-1) printf("invalid\n");
            else printf("%d\n",M[v]);
            break;
        case 'C':
            printf("%d\n", count(0, H.find(Q2[i])->second -1));
            break;
        }
    }

    return 0;
}
