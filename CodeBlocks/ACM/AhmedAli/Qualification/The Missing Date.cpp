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

int main(){
    int t, y1,m1,y2,m2,y3,m3;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &y1, &m1);
        scanf("%d %d", &y2, &m2);
        y3 = y1 + y2 + ((m1+m2>12)?1:0);
        m3 = (m1+m2)%12;
        if(m3==0) m3=12;
        printf("%d %d\n", y3, m3);
    }

    return 0;
}





