/*j ID: ahmadad1
PROG: fence8
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
#include <complex>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

int n, m;
vector<int> rails;
vector<int> boards;
int sum[1050];

int recur(int r, int left){
    if(left==0) return 1;
    if(left>m-r) return 0;
    if(r==m) return 0;
    int leftc=0;
    for(int i=0; i<boards.size(); i++) leftc+=boards[i];
    if(leftc<sum[r]) return 0;

    for(int i=0; i<boards.size(); i++){
        if(rails[r]<=boards[i]){
            boards[i]-=rails[r];
            if(recur(r+1, left-1)) {
                boards[i]+=rails[r];
                return 1;
            }
            boards[i]+=rails[r];
        }
    }
    //if(recur(r+1, left)) return 1;
    return 0;
}

int main() {
    freopen("fence8.in", "r", stdin);
    freopen("fence8.out", "w", stdout);

    int i,j,k;

    scanf("%d", &n);
    boards = vector<int>(n);
    for(i=0; i<n; i++) scanf("%d", &boards[i]);
    sort(boards.rbegin(), boards.rend());

    scanf("%d", &m);
    rails = vector<int>(m);
    for(i=0; i<m; i++) scanf("%d", &rails[i]);
    sort(rails.begin(), rails.end());

    int res=0;
    for(int i=1; i<=rails.size(); i++){
        sum[i+1]=0;
        for(int j=i; j>=0; j--) sum[j]=sum[j+1]+rails[j];

        if(recur(0, i)) res=i;
        else break;
    }
    printf("%d\n", res);

    return 0;
}







