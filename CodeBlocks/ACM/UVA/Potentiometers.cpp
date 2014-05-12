#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

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
    int t, i,j,k, n,a,b,x, kase=1, entered=0;
    char c;
    while(sscanf(gets(in), "%d", &n)){
        if(n==0) break;
        if(!entered) entered=1;
        else printf("\n");
        BIT bit(n);
        for(i=0; i<n; i++){
            sscanf(gets(in),"%d", &x);
            bit.update(i+1, x);
        }
        printf("Case %d:\n", kase++);
        while(1){
            gets(in);
            if(in[0]=='E') break;
            sscanf(in, "%c %d %d", &c, &a,&b);
            if(in[0]=='S'){
                bit.update(a, -1*(bit.read(a)-bit.read(a-1)));
                bit.update(a,b);
            }else {
                printf("%d\n", bit.read(b)-bit.read(a-1));
            }
        }
    }
    return 0;
}



