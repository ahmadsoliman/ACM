#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
bool vis[105];

vector< vector<int> > cur;

int main(){
    int t, n, c, i,j, last, done, finish;
    //scanf("%d", &t);
    //while(t--){
    scanf("%d", &n);


    for(i=0; i<n; i++){
        scanf("%d", &c);
        nums.push_back(c);
    }
    sort(nums.rbegin(), nums.rend());

    finish=0;
    while(!finish){
        finish=1;
        for(i=0; i<n; i++){
            if(!vis[i]){
                done=0;
                for(j=0; j<cur.size(); j++){
                    if(cur[j].back()>nums[i]){
                        cur[j].push_back(nums[i]);
                        done=1;
                        vis[i]=1;
                        break;
                    }else if(cur[j].back()==nums[i]) done=1;
                }
                if(!done){
                    vis[i]=1;
                    cur.push_back(vector<int>());
                    cur.back().push_back(nums[i]);
                }
                finish&=vis[i];
            }
        }

        for(i=0; i<n; i++){
            if(!vis[i]){
                done=0;
                for(j=0; j<cur.size(); j++){
                    if(cur[j].back()==nums[i] && cur[j].back()!=0) {
                        cur[j].push_back(nums[i]);
                        vis[i]=1;
                    }
                }
                if(!done){
                    vis[i]=1;
                    cur.push_back(vector<int>());
                    cur.back().push_back(nums[i]);
                }
            }
        }
    }
    for(i=0; i<cur.size(); i++){
        for(j=0; j<cur[i].size(); j++){
            printf("%d ", cur[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", cur.size());
    return 0;
}
