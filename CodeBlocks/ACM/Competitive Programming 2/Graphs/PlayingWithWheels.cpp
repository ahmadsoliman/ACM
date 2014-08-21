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

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, string> st;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

set<string> vis;

int mod(int x){
    if(x<0) return x+10;
    return x%10;
}

int main() {
    int t, n, k;
    scanf("%d", &t);
    while(t--){
        string init, fin;
        for(int i=0; i<4; i++) scanf("%d", &k), init+='0'+k;
        for(int i=0; i<4; i++) scanf("%d", &k), fin+='0'+k;
        vis.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            string cur;
            for(int i=0; i<4; i++) scanf("%d", &k), cur+='0'+k;
            vis.insert(cur);
        }
        bool found=false;
        queue<st> q;
        q.push(st(0,init));
        vis.insert(init);
        st cur;
        string news;
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(cur.second==fin) { found=true, printf("%d\n", cur.first); break; }

            for(int i=0; i<4; i++){
                news = cur.second;
                news[i]='0'+mod(news[i]-'0'+1);
                if(vis.find(news)==vis.end()) vis.insert(news), q.push(st(cur.first+1, news));
                news = cur.second;
                news[i]='0'+mod(news[i]-'0'-1);
                if(vis.find(news)==vis.end()) vis.insert(news), q.push(st(cur.first+1, news));
            }
        }
        if(!found) printf("-1\n");
    }

    return 0;

}
