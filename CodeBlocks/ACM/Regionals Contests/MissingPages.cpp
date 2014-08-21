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

vi pages[255];

int main() {
    int n,p;

    while(scanf("%d", &n)){
        if(n==0) break;
        scanf("%d", &p);

        for(int i=1, j=n; i<j; i+=2, j-=2){
            if(p==i) printf("%d %d %d\n", i+1, j-1, j);
            if(p==i+1) printf("%d %d %d\n", i, j-1, j);
            if(p==j-1) printf("%d %d %d\n", i, i+1, j);
            if(p==j) printf("%d %d %d\n", i, i+1, j-1);
        }
    }

    return 0;

}
