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

char in[1000];
vector<ii> nums;

int main(){
    int t,n;
    string s;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int k;
        bool f=true;
        while(n--) scanf("%d", &k), f&=(k<=1);
        if(f) printf("not ambiguous\n");
        else printf("ambiguous\n");
    }

    return 0;
}





