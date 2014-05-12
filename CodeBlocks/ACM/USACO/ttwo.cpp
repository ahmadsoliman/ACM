/*j ID: ahmadad1
PROG: ttwo
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
#include <set>
#include <math.h>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;
typedef pair<int, i4> i5;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define inboard(x,y) (x>=0 && x<10 && y>=0 && y<10)

queue<i5> q;
char grid[15][15];

set<i4> vis;

int rot(int dir){
    return (dir+1)%4;
}

ii move(ii cur){
    int p=cur.first, dir=cur.second;
    int x=p/10, y=p%10;
    switch(dir){
    case 0: x--; if(inboard(x,y) && grid[x][y]!='*') return ii(x*10+y, dir); else return ii(p, rot(dir));
    case 1: y++; if(inboard(x,y) && grid[x][y]!='*') return ii(x*10+y, dir); else return ii(p, rot(dir));
    case 2: x++; if(inboard(x,y) && grid[x][y]!='*') return ii(x*10+y, dir); else return ii(p, rot(dir));
    case 3: y--; if(inboard(x,y) && grid[x][y]!='*') return ii(x*10+y, dir); else return ii(p, rot(dir));
    }
}

int main() {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

    int i,j,k, fp, cp;

    for(i=0; i<10; i++) {
        scanf("%s", grid[i]);
        for(j=0; j<10; j++){
            if(grid[i][j]=='F') fp=i*10+j;
            if(grid[i][j]=='C') cp=i*10+j;
        }
    }

    i5 state(0, i4(ii(fp, 0), ii(cp, 0)));
    q.push(state);

    while(!q.empty()){
        state = q.front(); q.pop();

        vis.insert(state.second);

        ii f=state.second.first, c=state.second.second;

        //printf("%d %d :: %d %d\n", f.first/10, f.first%10, c.first/10, c.first%10);

        if(f.first==c.first) { printf("%d\n", state.first); return 0; }

        f = move(f);
        c = move(c);

        i4 ns(f,c);

        if(vis.find(ns)==vis.end()) q.push(i5(state.first+1, ns));
    }
    printf("0\n");
    return 0;
}
