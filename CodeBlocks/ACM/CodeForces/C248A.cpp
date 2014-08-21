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

set<char> s;

char in[1000000];

int main() {
    int n;
    gets(in);
    n = strlen(in);
    for(int i=1; i<n-1; i++){
        if(in[i]==' '||in[i]==',') continue;
        s.insert(in[i]);
    }
    printf("%d\n", s.size());

    return 0;

}
