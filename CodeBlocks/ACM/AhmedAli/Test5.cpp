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

set<int> s;

int dx[8]={0,0,     1,1,1,     -1,-1,-1};
int dy[8]={1,-1,    1,-1,0,     1,-1,0};

#define inboard(x,y) (x>=0&&y>=0&&x<n&&y<m)

int nums[110][110];

int main() {
    int t,n,m;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);
        s.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf("%d", &nums[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<8; k++){
                    if(nums[i][j]!=-1 && inboard(i+dx[k], j+dy[k]) && nums[i][j]==nums[i+dx[k]][j+dy[k]]) s.insert(nums[i][j]);
                }
            }
        }
        printf("%d\n", s.size());
    }
    return 0;

}
