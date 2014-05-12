#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


vector<int> nums, newn;

int main(){
    int t, n, i,j,k, f;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        nums.clear();
        f=1;
        for(i=0;i<n; i++){
            scanf("%d", &k);
            nums.push_back(k);
            if(k!=0) f=0;
        }
        if(f) { printf("ap!\n"); continue; }
        k=0, f=1;

        while(nums.size()>1 && f){
            newn.clear();
            f=0;
            for(i=1; i<nums.size(); i++){
                newn.push_back(nums[i]-nums[i-1]);
                if(newn.back()!=0) f=1;
            }
            nums=newn;
            k++;
        }
        if(!f){
            for(i=0; i<k; i++) printf("z");
            printf("ap!\n");
        }else{
            if(nums.back()<0) printf("*bunny*\n");
            else printf("*fizzle*\n");
        }
    }
    return 0;
}
