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
    int t;
    string s;

    scanf("%d", &t);
    while(t--){
        scanf("%s", in);
        s=in;
        nums = vector<ii>(26, ii(0,0));
        for(int i=0; i<26; i++) nums[i].second=-i;
        for(int i=0; i<s.size(); i++) nums[s[i]-'a'].first++;
        sort(nums.rbegin(), nums.rend());
        printf("%d %c\n", nums[0].first, -nums[0].second+'a');
    }

    return 0;
}





