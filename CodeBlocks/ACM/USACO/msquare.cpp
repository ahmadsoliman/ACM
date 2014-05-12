/*j ID: ahmadad1
PROG: msquare
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
typedef pair<string, string> ss;
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

queue<ss> q;
set<string> vis;

int main() {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    int i,j,r, k;

    string goal="12345678", cur="12345678", ns, p1, p2;
    for(i=0; i<8; i++) scanf("%d", &k), goal[i]='0'+k;

    ss state;
    q.push(ss(cur, ""));

    while(!q.empty()){
        state = q.front(); q.pop();
        cur = state.first;

        if(cur==goal){
            printf("%d\n", state.second.size());
            printf("%s\n", state.second.c_str());
            break;
        }

        ns = string(cur.rbegin(), cur.rend());
        if(!vis.count(ns))
            vis.insert(ns),
            q.push(ss(ns, state.second+'A'));

        ns = cur[3]+cur.substr(0,3)+cur.substr(5)+cur[4];
        if(!vis.count(ns))
            vis.insert(ns),
            q.push(ss(ns, state.second+'B'));

        swap(cur[1],cur[2]);swap(cur[1],cur[5]);swap(cur[1],cur[6]);
        if(!vis.count(cur))
            vis.insert(cur),
            q.push(ss(cur, state.second+'C'));
    }

    return 0;
}
