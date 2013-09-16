#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

string nums[10010];
char in[15];

int main(){
    int t, n, i, flag;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%s", in);
            nums[i] = string(in);
        }
        sort(nums, nums+n);
        flag=1;
        for(i=1; i<n; i++){
            if(nums[i-1]==nums[i].substr(0,nums[i-1].size())){
                flag=0;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
