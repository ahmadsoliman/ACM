#include <stdio.h>
#include <map>

using namespace std;

int n, k[105], c[105];

typedef pair<int, int> ii;

map<ii, int> dp;

int recur(int t, int diff){
    if(t==n) return abs(diff);
    int i, curdiff, mindiff=1000000;
    for(i=0; i<=k[t]; i++){
        curdiff=recur(t+1, diff+(i-(k[t]-i))*c[t]);
        if(curdiff<mindiff) mindiff=curdiff;
    }
    return mindiff;
}

int main(){
    int i,j;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &k[i], &c[i]);
    printf("%d\n", recur(0, 0));
    return 0;
}
