/*j ID: ahmadad1
PROG: agrinet
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
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int graph[105][105];

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

int main() {
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);

    int n, i,j,k,r,l;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    priority_queue<iii, vector<iii>, greater<iii> > pq;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            pq.push(iii(graph[i][j], ii(i,j)));
        }
    }

    int res=0;
    disjoint_set ds(n);
    while(ds.setscnt>1){
        iii cur = pq.top(); pq.pop();
        if(ds.find(cur.second.first)==ds.find(cur.second.second)) continue;
        ds.union_set(cur.second.first, cur.second.second);
        res+=cur.first;
    }
    printf("%d\n", res);

    return 0;
}
