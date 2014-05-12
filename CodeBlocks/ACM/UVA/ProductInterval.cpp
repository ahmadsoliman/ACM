#include <stdio.h>
#include <string.h>

using namespace std;

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

char in[100];

int main(){
    int t, n, i,j,k, a,b, x,y;

    while(scanf("%d %d", &n, &k)>0){
        BIT zeros(n), neg(n);

        for(i=0; i<n; i++){
            scanf("%d", &x);
            if(x==0) zeros.update(i+1, 1);
            else if(x<0) neg.update(i+1, 1);
        }
        for(i=0; i<k; i++){
            scanf("%s %d %d", in, &a, &b);

            if(in[0]=='C'){
                x = zeros.read(a)-zeros.read(a-1);
                if(x==1) zeros.update(a, -1);
                else{
                    x = neg.read(a)-neg.read(a-1);
                    if(x==1) neg.update(a, -1);
                }

                if(b==0) zeros.update(a, 1);
                else if(b<0) neg.update(a, 1);
            }else{
                x = zeros.read(b)-zeros.read(a-1);
                if(x>0) printf("0");
                else {
                    x = neg.read(b)-neg.read(a-1);
                    if(x&1) printf("-");
                    else printf("+");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
/*
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
*/
