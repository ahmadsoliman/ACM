/*
ID: ahmadad1
PROG: milk3
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

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define a first
#define b second.first
#define c second.second

queue<iii> q;
set<int> s;
set<iii> vis;

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    int x,y,z;

    scanf("%d %d %d", &x, &y, &z);

    q.push(iii(0, ii(0,z)));

    while(!q.empty()){
        iii cur=q.front(); q.pop();
        vis.insert(cur);

        if(cur.a==0){
            s.insert(cur.c);
        }

        if(cur.a>0){
            // a->b
            iii nxt=iii(max(0, cur.a-(y-cur.b)), ii(min(y, cur.b+cur.a), cur.c));
            if(vis.find(nxt)==vis.end()) q.push(nxt);
            // a->c
            nxt=iii(max(0, cur.a-(z-cur.c)), ii(cur.b, min(z, cur.c+cur.a)));
            if(vis.find(nxt)==vis.end()) q.push(nxt);
        }
        if(cur.b>0){
            // b->a
            iii nxt=iii(min(x, cur.a+cur.b), ii(max(0, cur.b-(x-cur.a)), cur.c));
            if(vis.find(nxt)==vis.end()) q.push(nxt);
            // b->c
            nxt=iii(cur.a, ii(max(0, cur.b-(z-cur.c)), min(z, cur.c+cur.b)));
            if(vis.find(nxt)==vis.end()) q.push(nxt);
        }
        if(cur.c>0){
            // c->a
            iii nxt=iii(min(x, cur.a+cur.c), ii(cur.b, max(0, cur.c-(x-cur.a))));
            if(vis.find(nxt)==vis.end()) q.push(nxt);
            // c->b
            nxt=iii(cur.a, ii(min(y, cur.b+cur.c), max(0, cur.c-(y-cur.b))));
            if(vis.find(nxt)==vis.end()) q.push(nxt);
        }
    }

    set<int>::iterator it=s.begin();
    printf("%d", *it);
    it++;
    for(; it!=s.end(); it++) printf(" %d", *it);
    printf("\n");

    return 0;
}
