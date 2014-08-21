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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char in[100];
map<string, int> sti;
vector<string> words;

vector<int> g[10005];
int l1[2005], l2[2005], vis[2005];

int main() {
    int w, n, s,t,u,v;
    string l;

    while(scanf("%d", &w)>0){
        if(w==0) break;
        for(int i=0; i<5000; i++) g[i].clear();
        memset(l1, 0, sizeof l1);
        memset(l2, 0, sizeof l2);
        sti.clear();
        words.clear();
        n=0;

        scanf("%s", in);
        l=in;
        if(sti.find(l)==sti.end()) s=n, sti[l]=n++;
        else s=sti[l];

        scanf("%s", in);
        l=in;
        if(sti.find(l)==sti.end()) t=n, sti[l]=n++;
        else t=sti[l];

        for(int i=0; i<w; i++){
            scanf("%s", in);
            l=in;
            if(sti.find(l)==sti.end()) u=n, sti[l]=n++;
            else u=sti[l];

            scanf("%s", in);
            l=in;
            if(sti.find(l)==sti.end()) v=n, sti[l]=n++;
            else v=sti[l];

            scanf("%s", in);
            words.pb(in);
            g[u].pb(i);
            g[v].pb(i);
            l1[i]=u;
            l2[i]=v;
        }

        memset(vis, 0, sizeof vis);
        bool found=false;
        priority_queue<iii, vector<iii>, greater<iii> > pq;
        for(int i=0; i<g[s].size(); i++) pq.push(iii(words[g[s][i]].size(),ii(g[s][i], s)));

        while(!pq.empty()){
            iii p=pq.top(); pq.pop();

            int word=p.second.first, lang=p.second.second;
            if(vis[word]) continue;
            vis[word]=1;

            int newlang;
            if(lang==l1[word]) newlang=l2[word];
            else if(lang==l2[word]) newlang=l1[word];
            else printf("leh!\n");

            if(newlang==t){
                found=true;
                printf("%d\n", p.first);
                break;
            }

            for(int i=0; i<g[newlang].size(); i++){
                int v = g[newlang][i];
                if(words[word][0]==words[v][0]) continue;
                pq.push(iii(p.first+words[v].size(), ii(v, newlang)));
            }
        }
        if(!found) printf("impossivel\n");
    }

    return 0;

}
