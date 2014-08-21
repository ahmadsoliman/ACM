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

char in[1010];
bool v[1010];
int n;

// 0011
// 0110111
// 0101010
// 1010101

int recur(int i, int c){
    if(i==n) return 0;

    if(c==v[i]) {
        return recur(i+1, !c);
    }
    return 1+recur(i+1, !c);

}

int main() {
    scanf("%d", &n);
    scanf("%s", in);
    for(int i=0; i<n; i++) v[i]=in[i]=='1';

    printf("%d\n", min(recur(0, 0), recur(0,1)));

    return 0;

}
