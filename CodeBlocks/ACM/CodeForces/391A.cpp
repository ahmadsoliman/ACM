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

int main() {
    string s;

    cin >> s;
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        int c=0;
        while(i<s.size()-1 && s[i]==s[i+1]) i++,c++;
        if(c&1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
