#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int graph[15][15], nums[15], nums2[15];

vector<int> v1, v2;

int main(){
    int n, i,j,k, f;
    while(scanf("%d", &n)>0){

        if(n==0) return 0;
        v1.clear();
        v2.clear();
        for(i=0; i<n; i++){scanf("%d", &nums[i]); v1.push_back(nums[i]);}
        for(i=0; i<n; i++){scanf("%d", &nums2[i]); v2.push_back(nums2[i]);}

        if(n==1){
            printf("caught\n");
            continue;
        } else if(n==2){
            if(nums[0]==nums2[0]) printf("escaped\n");
            else printf("caught\n");
            continue;
        } else if(n%2==1){
            if(v1==v2) printf("caught\n");
            else printf("escaped\n");
            continue;
        }

        memset(graph, 0, sizeof graph);
        for(i=1; i<n; i++){
            graph[nums[i]][nums[i-1]]=graph[nums[i-1]][nums[i]]=1;
        }
        graph[nums[n-1]][nums[0]]=graph[nums[0]][nums[n-1]]=1;

        f=1;
        if(nums2[0]!=nums[0]) f=0;
        else{
            for(i=1; i<n; i++){
                if(graph[nums2[i]][nums2[i-1]]==0) { f=0; break; }
            }
            if(graph[nums2[n-1]][nums2[0]]==0) f=0;
        }
        if(f) printf("caught\n");
        else printf("escaped\n");
    }
    return 0;
}
