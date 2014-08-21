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

#define MAXN 100005
#define MAXIND 300005

void initialize(int node, int b, int e, int M[MAXIND], int A[MAXN], int N){
    if (b == e) M[node] = b;
    else{
    //compute the values in the left and right subtrees
      initialize(2 * node, b, (b + e) / 2, M, A, N);
      initialize(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
    //search for the minimum value in the first and
    //second half of the interval
      if (A[M[2 * node]] <= A[M[2 * node + 1]])
          M[node] = M[2 * node];
      else
          M[node] = M[2 * node + 1];
    }
}

int lazy[MAXIND];

int query(int node, int b, int e, int M[MAXIND], int A[MAXN], int i, int j){
    int p1, p2;
    //if the current interval doesn't intersect
    //the query interval return -1
    if (i > e || j < b)
      return -1;
    //if the current interval is included in
    //the query interval return M[node]
    if (b >= i && e <= j)
      return M[node];
    //compute the minimum position in the
    //left and right part of the interval
    p1 = query(2 * node, b, (b + e) / 2, M, A, i, j);
    p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
    //return the position where the overall
    //minimum is
    if (p1 == -1)
      return M[node] = p2;
    if (p2 == -1)
      return M[node] = p1;
    if (A[p1] <= A[p2])
      return M[node] = p1;
    return M[node] = p2;
}

int updateRange(int node, int b, int e, int M[MAXIND], int A[MAXN], int i, int j){

}

int A[MAXN], M[MAXIND];

int main() {
    int n, m, w;
    scanf("%d %d %d", &n, &m, &w);

    for(int i=0; i<n; i++) scanf("%d", &A[i]);
    initialize(1, 0, n-1, M, A, n);


    while(m--){
        int ind = query(1, 0, n-1, M, A, 0, n-1), indl=-1, indr=-1;
        if(ind>0) indl = query(1, 0, n-1, M, A, max(0, ind-w+1), ind-1);
        if(ind<n-1) indr = query(1, 0, n-1, M, A, ind+1, min(n-1, ind+w-1));

        if(indr==-1){

        }else if(indl==-1){

        }else if(indr-indl+1<=w){

        }else{

        }

    }

    printf("%d", A[query(1, 0, n-1, M, A, 0, n-1)]);

    return 0;

}
