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
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

set<int> res;

#define MAX_SIZE 1050

struct disjoint_set{
    int arr[MAX_SIZE+1], found[MAX_SIZE+1], setscnt;

    disjoint_set(int n){
        memset(arr, -1, sizeof arr);
        memset(found, 0, sizeof found);
        setscnt=n;
    }

    void set(int e){
        arr[e]=-1;
        found[e]=1;
    }

    int find(int e){
        if(arr[e]<0) return e;
        int r=find(arr[e]);
        arr[e]=r;
        return r;
    }

    int size(int e){
        return -1*arr[find(e)];
    }

    void union_set(int e1, int e2){
        if(!found[e1]) set(e1);
        if(!found[e2]) set(e2);
        int r1=find(e1), r2=find(e2), s1=-1*arr[r1], s2=-1*arr[r2];
        if(r1==r2) return;
        setscnt--;
        if(s1>s2) arr[r1]+=arr[r2], arr[r2]=r1;
        else arr[r2]+=arr[r1], arr[r1]=r2;
    }

    void print(int e){
        int ds=find(e);

        for(int i=0; i<MAX_SIZE; i++){
            if(find(i)==ds) printf("%d ", i);
        }
        printf("\n");
    }
};

int main(){
    int n, m;
    int u,v,w, cnt;

    while(scanf("%d %d", &n, &m)){
        if(!n&&!m) break;

        res.clear();
        priority_queue<iii, vector<iii>, greater<iii> > pq;

        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            pq.push(iii(w, ii(u,v)));
        }

        disjoint_set ds(n);
        while(!pq.empty()){
            iii cur = pq.top(); pq.pop();
            if(ds.find(cur.second.first)==ds.find(cur.second.second)) { res.insert(cur.first); continue; }
            ds.union_set(cur.second.first, cur.second.second);
        }

        if(res.size()==0) printf("forest\n");
        else {
            printf("%d", *res.begin());
            set<int>::iterator it = res.begin();
            it++;
            for(; it!=res.end(); it++) printf(" %d", *it);
            printf("\n");
        }
    }
    return 0;
}
