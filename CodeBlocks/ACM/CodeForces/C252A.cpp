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

int words[5];
char in[10000];
vector<int> res;

int main() {
    int n, v,k,u;
    scanf("%d %d", &n, &v);
    for(int i=0; i<n; i++){
        scanf("%d", &k);
        bool valid=false;
        for(int j=0; j<k; j++) {
            scanf("%d", &u);
            if(v>u) valid=true;
        }
        if(valid) res.push_back(i+1);
    }
    printf("%d\n", res.size());
    if(res.size()>0){
        printf("%d", res[0]);
        for(int i=1; i<res.size(); i++) printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}
