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

int main(){
    int t, i,j,k, n, c, o;
    long long a,b,x;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &c);
        BIT bit(n), xbit(n);
        for(i=0; i<c; i++){
            scanf("%d", &o);
            if(o){
                scanf("%lld %lld", &a,&b);
                printf("%lld\n", (bit.read(b)*b-xbit.read(b))-(bit.read(a-1)*(a-1)-xbit.read(a-1)));
            }else{
                scanf("%lld %lld %lld", &a, &b, &x);
                bit.update(a, x);
                bit.update(b+1, -x);
                xbit.update(a, x*(a-1));
                xbit.update(b+1, -x*b);
            }
        }
    }
    return 0;
}








