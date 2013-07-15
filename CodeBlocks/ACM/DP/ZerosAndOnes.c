#include <stdio.h>
#include <string.h>

int N,K;

long long recur(int zeros, int ones){
    int i = zeros+ones;
    if(i==N){
        if(zeros==ones) return 1;
        else return 0;
    }
    if(K&(1<<(N-i-1))) return recur(zeros, ones+1);
    return recur(zeros, ones+1) + recur(zeros+1, ones);
}

int main(){
    int t, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &K);
        printf("Case %d: %ld\n", kase++, recur(0,1));
    }
    return 0;
}
