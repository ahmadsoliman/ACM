#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int dp[1005][1005], visited[1005][1005];
int FILL_A=0, FILL_B=1, EMPTY_A=2, EMPTY_B=3, POUR_A=4, POUR_B=5, N, Ca, Cb;

vector<int> final_steps;

int recur(int aNow, int bNow, vector<int> steps){
    if(final_steps.size()>0){
        return 0;
    }
    if(bNow==N){
        //if(final_steps.size()==0)
            final_steps=steps;
        //else if(steps.size()<final_steps.size())
        //    final_steps=steps;
        return 1;
    }
    if(visited[aNow][bNow])
        return dp[aNow][bNow];
    else
        visited[aNow][bNow]=1;

    int i;
    vector<int> vA, vB, vC, vD, vE, vF;
    for(i=0; i<steps.size(); i++){
        vA.push_back(steps[i]);
        vB.push_back(steps[i]);
        vC.push_back(steps[i]);
        vD.push_back(steps[i]);
        vE.push_back(steps[i]);
        vF.push_back(steps[i]);
    }
    //if(aNow<Ca){
        vA.push_back(FILL_A);
        vE.push_back(POUR_B);
        int tmp = aNow+bNow;

    //}
    //if(bNow<Cb){
        vB.push_back(FILL_B);
        vF.push_back(POUR_A);

    //}
    //if(aNow>0){
        vC.push_back(EMPTY_A);
    //}
    //if(bNow>0){
        vD.push_back(EMPTY_B);
    //}
    return (dp[aNow][bNow]=(recur(Ca, bNow, vA)||
                            recur(aNow, Cb, vB)||
                            ((tmp<=Ca)?recur(tmp, 0, vE):recur(Ca, bNow-(Ca-aNow), vE))||
                            ((tmp<=Cb)?recur(0, tmp, vF):recur(aNow-(Cb-bNow), Cb, vF))||
                            recur(0, bNow, vC)||
                            recur(aNow, 0, vD)));
}
int main(){
    while(scanf("%d %d %d", &Ca, &Cb, &N)){
        memset(dp, -1, sizeof dp);
        memset(visited, 0, sizeof visited);

        vector<int> v;
        recur(0, 0, v);
        int i;

        for(i=0; i<final_steps.size(); i++){
            switch(final_steps[i]){
                case 0:
                    printf("fill A\n");break;
                case 1:
                    printf("fill B\n");break;
                case 2:
                    printf("empty A\n");break;
                case 3:
                    printf("empty B\n");break;
                case 4:
                    printf("pour A B\n");break;
                case 5:
                    printf("pour B A\n");break;
            }
        }
        printf("success\n");
        final_steps.clear();
    }
}
