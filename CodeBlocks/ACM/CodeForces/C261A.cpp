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


int main() {
    int x,y,z,w;
    scanf("%d %d %d %d", &x, &y, &z, &w);

    int s;
    if(x==z){
        s = abs(w-y);
        printf("%d %d %d %d\n", x+s, y, x+s, w);
    }else if(y==w){
        s = abs(x-z);
        printf("%d %d %d %d\n", x, y+s, z, y+s);
    }else{
        if(abs(x-z)==abs(y-w)){
            s = abs(x-z);
            printf("%d %d %d %d\n", min(x,z), max(w,y), max(x,z), min(y,w));
        }else{
            printf("-1\n");
        }
    }


    return 0;

}

