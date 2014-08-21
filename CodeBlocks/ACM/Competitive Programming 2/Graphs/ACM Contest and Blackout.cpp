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

#define MAX_SIZE 105

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
    int n, m, t;
    int u,v,w, cnt;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);

        priority_queue<iii, vector<iii>, greater<iii> > pq;
        vector<iii> origes;
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            pq.push(iii(w, ii(u,v)));
            origes.push_back(iii(w, ii(u,v)));
        }

        int minSpan=0;
        disjoint_set ds(n);
        vector<ii> es;
        while(ds.setscnt>1){
            iii cur = pq.top(); pq.pop();
            if(ds.find(cur.second.first)==ds.find(cur.second.second)) continue;
            ds.union_set(cur.second.first, cur.second.second);
            minSpan += cur.first;
            es.push_back(cur.second);
        }

        int minSpan2=1000000000, span2;

        for(int i=0; i<es.size() ; i++){
            span2=0;

            disjoint_set ds1(n);
            priority_queue<iii, vector<iii>, greater<iii> > pq1;

            for(int j=0; j<origes.size(); j++)
                if(!(origes[j].second.first==es[i].first && origes[j].second.second==es[i].second)) pq1.push(origes[j]);

            while(!pq1.empty()){
                iii cur = pq1.top(); pq1.pop();
                if(ds1.find(cur.second.first)==ds1.find(cur.second.second)) continue;
                ds1.union_set(cur.second.first, cur.second.second);
                span2 += cur.first;
                if(span2>minSpan2) break;
            }

            if(ds1.setscnt==1) minSpan2 = min(minSpan2, span2);
        }
        if(minSpan2<minSpan) minSpan2=minSpan;

        printf("%d %d\n", minSpan, minSpan2);
    }
    return 0;
}
