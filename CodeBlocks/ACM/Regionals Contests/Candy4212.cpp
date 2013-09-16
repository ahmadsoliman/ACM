#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

vector< vector<int> > arr, dp1;
vector<int> dp2;

int recur1(int i, int j){
    if(j>=m) return 0;
    if(dp1[i][j]!=-1) return dp1[i][j];
    int a = recur1(i, j+1), b=arr[i][j]+recur1(i, j+2);
    return dp1[i][j] = max(a,b);
}

int recur2(int i){
    if(i>=n) return 0;
    if(dp2[i]!=-1) return dp2[i];
    int a = recur2(i+1), b=dp1[i][0]+recur2(i+2);
    return dp2[i] = max(a,b);
}

int main(){
    int i,j, v;
    while(scanf("%d %d", &n, &m)>0){
        if(n==0&&m==0) return 0;
        for(i=0; i<n; i++){
            if(i>=arr.size()) arr.push_back(vector<int>());
            else arr[i].clear();
            if(i>=dp1.size()) dp1.push_back(vector<int>());
            dp1[i]=vector<int>(m, -1);
            for(j=0; j<m; j++){
                scanf("%d", &v);
                arr[i].push_back(v);
            }
        }
        for(i=0; i<n; i++) recur1(i, 0);
        dp2=vector<int>(n, -1);
        printf("%d\n", recur2(0));
    }
    return 0;
}
