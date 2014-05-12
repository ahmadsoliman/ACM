#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int n, owe[25][25], dp[1<<20+5], bal[25], kase=1;

set<int> res;
set<int>::iterator it;

void recur(int bm){
    int f=0, last=-1, c=0;

    if(dp[bm]==kase) return;
    dp[bm]=kase;

    long long bal;
    for(int i=0; i<n; i++){
        if(!(bm&(1<<i))){
            bal=0;
            for(int j=0; j<n; j++){
                if(i!=j && !(bm&(1<<j))) bal+=owe[i][j];
            }
            if(bal>0) c++, recur(bm|(1<<i));
            else f++, last = i+1;
        }
    }
    if(c==0 && f==1) res.insert(last);
}

int main(){
    int t, i,j,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d", &owe[i][j]);
            }
        }
        res.clear();
        recur(0);

        it=res.begin();
        if(res.size()==0) { printf("0\n"); continue; }
        else printf("%d", *it), it++;

        for(; it!=res.end(); it++) {
            printf(" %d", *it);
        }
        printf("\n");
        kase++;
    }
    return 0;
}
/*
1
5
0 1 -3 2 1
-1 0 1 -2 4
3 -1 0 -2 1
-2 2 2 0 -5
-1 -4 -1 5 0
*/
