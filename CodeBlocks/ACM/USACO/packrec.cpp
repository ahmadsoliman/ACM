/*
ID: ahmadad1
PROG: packrec
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int w[10],h[10], area, board[205][205], maxdim;
set<ii> res;
vi v;

void recur(int r){
    if(r==4){
        int maxh=0, maxw=0;
        for(int i=maxdim; i>=0; i--){
            for(int j=maxdim; j>=maxw; j--){
                if(board[i][j]) { maxh=max(maxh, i+1), maxw=max(maxw, j+1); break; }
            }
        }
        if(maxw<maxh) swap(maxw, maxh);

        if(maxw*maxh<area){
            area=maxw*maxh;
            res.clear();
            res.insert(ii(maxh, maxw));
        }else if(maxw*maxh==area) res.insert(ii(maxh, maxw));

        return;
    }
    int i,j, k,l, f, lastj=maxdim;
    for(i=0; i<maxdim; i++){
        for(j=0; j<lastj; j++){
            if(!board[i][j]){
                f=0;
                for(k=0; k<w[v[r]]; k++) for(l=0; l<h[v[r]]; l++) if(board[i+k][j+l]) f=1;
                if(f) break;
                lastj=j;
                for(k=0; k<w[v[r]]; k++) for(l=0; l<h[v[r]]; l++) board[i+k][j+l]=1;
                recur(r+1);
                for(k=0; k<w[v[r]]; k++) for(l=0; l<h[v[r]]; l++) board[i+k][j+l]=0;

                f=0;
                for(k=0; k<h[v[r]]; k++) for(l=0; l<w[v[r]]; l++) if(board[i+k][j+l]) f=1;
                if(f) break;
                for(k=0; k<h[v[r]]; k++) for(l=0; l<w[v[r]]; l++) board[i+k][j+l]=1;
                recur(r+1);
                for(k=0; k<h[v[r]]; k++) for(l=0; l<w[v[r]]; l++) board[i+k][j+l]=0;

                break;
            }
        }
        if(j==0) break;
    }
}

int vc[10]={0,1,2,3};

int main() {
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);

    int i,j;

    maxdim=2;
    for(i=0; i<4; i++) scanf("%d %d", &w[i], &h[i]), maxdim+=max(w[i],h[i]);

    v=vi(vc, vc+4);
    area=10000000;
    do{
        memset(board, 0, sizeof board);
        recur(0);
    }while(next_permutation(v.begin(), v.end()));

    printf("%d\n", area);
    for(set<ii>::iterator it=res.begin(); it!=res.end(); it++) printf("%d %d\n", (*it).first, (*it).second);

    return 0;
}
