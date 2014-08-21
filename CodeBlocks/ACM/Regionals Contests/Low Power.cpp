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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int nums[1000100], vis[1000100];
vii diffs;

struct BIT{
    int * tree;
    int MaxVal;

    BIT(int n){
        MaxVal = n;
        tree = new int[MaxVal+1];
        memset(tree, 0, sizeof(int)*(MaxVal+1));
    }

    int read(int idx){
        idx++;
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(int idx ,int val){
        idx++;
        while (idx <= MaxVal){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
};

int main(){
    int n,k,sz;
    while(scanf("%d %d", &n, &k)>0){
        sz = 2*n*k;
        for(int i=0; i<sz; i++){
            scanf("%d", &nums[i]);
            if(i>2){
                diffs.push_back(ii(nums[i]-nums[i-1],i-1));
            }
        }
        memset(vis, 0, sizeof vis);

        int maxDiff=0;
        sort(nums, nums+sz);

        maxDiff=max(maxDiff, nums[1]-nums[0]);

        sort(diffs.begin(), diffs.end());

        BIT bit(sz);


        int cs=1, last=sz-1;

        vis[0]=vis[1]=1;
        bit.update(0, 1);
        bit.update(1, 1);

        for(int cnt=2*(k-1); cnt>0 && last>0; last--){
            if(vis[last]) continue;
            cnt--;
            vis[last]=1;
            bit.update(last, 1);
        }



        for(int i=0; cs<n && i<diffs.size(); i++){
            int ind=diffs[i].second;

            if(vis[ind]||vis[ind+1]) continue;
            int left = sz-(ind+1)-(bit.read(sz-1)-bit.read(ind+1));
            if(left<2*(k-1)) continue;

            vis[ind]=vis[ind+1]=1;
            bit.update(ind, 1);
            bit.update(ind+1, 1);

            for(int cnt=2*(k-1); cnt>0 && last>0; last--){
                if(vis[last]) continue;
                cnt--;
                vis[last]=1;
                bit.update(last, 1);
            }

            cs++;
            maxDiff=max(maxDiff, nums[ind+1]-nums[ind]);
        }

//        for(int i=0; i<sz; i++) printf("%d ", vis[i]);

        printf("%d\n", maxDiff);
    }
    return 0;
}
