#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int nums[105], visited[105][64100], SUM, N;
vector<int> satisfied_exprns;

int prune(int i, int res_so_far, vector<int> exprns){
    if(satisfied_exprns.size()>0)
        return 0;
    if(res_so_far>32000 || res_so_far<-32000)
        return 0;
    if(i==N){
        if(res_so_far==SUM){
            satisfied_exprns=exprns;
            return 1;
        }
        return 0;
    }
    if(visited[i][res_so_far]>-1)
        return visited[i][res_so_far];
    vector<int> v1(exprns.begin(),exprns.end()), v2(exprns.begin(),exprns.end()), v3(exprns.begin(),exprns.end());
    v1.push_back(0);
    v2.push_back(1);
    v3.push_back(2);
    if(res_so_far%nums[i]==0){
        vector<int> v4(exprns.begin(),exprns.end());
        v4.push_back(3);
        return visited[i][res_so_far]=prune(i+1, res_so_far+nums[i], v1) || prune(i+1, res_so_far-nums[i], v2) || prune(i+1, res_so_far*nums[i], v3) || prune(i+1, res_so_far/nums[i], v4) ;
    }
    return visited[i][res_so_far]=prune(i+1, res_so_far+nums[i], v1) || prune(i+1, res_so_far-nums[i], v2) || prune(i+1, res_so_far*nums[i], v3);
}

int main(){
    int t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        for(i=0; i<N; i++){
            scanf("%d", &nums[i]);
        }
        scanf("%d", &SUM);
        if(N==1){
            if(SUM==nums[0])
                printf("%d=%d\n", SUM, SUM);
            else
                printf("NO EXPRESSION\n");
        }
        memset(visited, -1, sizeof visited);
        vector<int> v;
        if(!prune(1,nums[0],v)){
            printf("NO EXPRESSION\n");
            continue;
        }
        for(i=0; i<satisfied_exprns.size(); i++){
            switch(satisfied_exprns[i]){
                case 0:
                    printf("%d+",nums[i]);break;
                case 1:
                    printf("%d-",nums[i]);break;
                case 2:
                    printf("%d*",nums[i]);break;
                case 3:
                    printf("%d/",nums[i]);break;
            }
        }
        printf("%d=%d\n", nums[i], SUM);
        satisfied_exprns.clear();
    }

    return 0;
}
