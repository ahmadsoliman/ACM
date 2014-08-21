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

char in[10000];

int main() {
    int n,  k;
    scanf("%s", &in);
    scanf("%d", &k);

    n=strlen(in);

    int maxl=0;
    int tot=n+k;
    bool f;
    for(int i=0; i<tot; i++){
        for(int len=1; i+2*len<=tot; len++){
            f=true;
            for(int j=i; j+len<i+2*len; j++){
                if(j+len>=n || in[j]==in[j+len]) continue;
                else {f=false; break;}
            }
            if(f) { maxl=max(maxl, 2*len); }
        }
    }
    printf("%d\n", maxl);

    return 0;

}
