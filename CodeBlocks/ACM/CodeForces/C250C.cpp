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
typedef pair<ii, int> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;

vi nums;
viii tmp;
vi energy;
vi graph[1100];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    nums = vi(n);
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);

    int u,v;
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<graph[i].size(); j++){
            sum+=nums[graph[i][j]];
        }
        tmp.push_back(iii(ii(-nums[i], sum), i));
        energy.push_back(sum);
    }
    sort(tmp.rbegin(), tmp.rend());

    int res=0;

    for(int i=n-1; i>=0; i--){
        u = tmp[i].second;
        tmp.pop_back();

//        printf("%d %d\n", u+1, energy[u]);
        res += energy[u];
        for(int j=0; j<graph[u].size(); j++){
            energy[graph[u][j]]-=nums[u];
        }
        for(int j=0; j<tmp.size(); j++){
            v = tmp[j].second;
            tmp[j].first.second = energy[v];
//            for(int k=0; k<graph[u].size(); k++){
//                if(v==graph[u][k]){
//                    tmp[j].first.second = -nums[v]*graph[v].size();
//                }
//            }
        }
        sort(tmp.rbegin(), tmp.rend());
//        for(int j=0; j<tmp.size(); j++){
//            printf("%d %d %d\n", tmp[j].first.first, tmp[j].first.second, tmp[j].second);
//        }
    }
    printf("%d\n", res);

    return 0;
}
