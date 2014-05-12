#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000

vector<int> w;
int n,d;

// word, count number of words starting with c with len l
// aa, ab,

// words
int recur(int n, int j){
    if(i==n) return 0;

    int a=recur(i, j+1, 0), b=recur(i, j, len+1)
    c=cozt+recur(i+1, j, len+1)
}

// ab, aa, b 23

int main(){
    int i,j,k;
    while(scanf("%d %d", &n, &d)>0){
        if(n==0 && d==0) return 0;
        w = vector<int>(d);
        for(i=0; i<d; i++) scanf("%d", &w[i]);
        sort(w.rbegin(), w.rend());

        printf("%d\n", recur(0, 0, 0));
    }
    return 0;
}
