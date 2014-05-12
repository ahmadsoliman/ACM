/*
ID: ahmadad1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<vi, vi> state;

/*
A 0
B 1
C 2
D 3
E 4
F 5
G 6
H 7
I 8
*/
int c[10]={4,3,4,3,5,3,4,3,4},
v[10][5]={{0,1,3,4},{0,1,2},{1,2,4,5},
          {0,3,6},{1,3,4,5,7},{2,5,8},
          {3,4,6,7},{6,7,8},{4,5,7,8}};

vi res;

int recur(vi clock, int cur, int cnt){
    int f=1, i,j;
    for(i=0; i<9; i++) if(clock[i]!=0) {f=0; break;}
    if(f){
        for(i=0; i<res.size(); i++) {
            printf("%d", res[i]);
            if(i<res.size()-1) printf(" ");
        }
        printf("\n");
        return 1;
    }
    if(cur==9) return 0;

    if(cnt>0){
        res.push_back(cur+1);
        vi cl=clock;
        for(j=0; j<c[cur]; j++) {
            cl[v[cur][j]]+=3;
            if(cl[v[cur][j]]==12) cl[v[cur][j]]=0;
        }
        if(recur(cl, cur, cnt-1)) return 1;
        res.pop_back();
    }

    cur++;
    if(cur==9) return 0;

    if(recur(clock, cur, 3)) return 1;

    return 0;
}

int main() {
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);

    int i,j,k, f;
    vi cl=vi(9);
    for(i=0; i<9; i++) scanf("%d", &cl[i]), cl[i]%=12;

    vi clock;
    recur(cl, 0, 3);

    return 0;
}
