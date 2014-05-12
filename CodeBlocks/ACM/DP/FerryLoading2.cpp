#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vi cars, cumm;

int dp[1000][10005], ferry;

int recur(int i, int left){
    if(i==cars.size()) return dp[i][left]=0;
    if(dp[i][left]!=-1) return dp[i][left];

    int right = ferry-(cumm[i]-(ferry-left));

    int a=0, b=0;
    if(left>=cars[i]) a=1+recur(i+1, left-cars[i]);
    if(right>=cars[i]) b=1+recur(i+1, left);

    return dp[i][left]=max(a,b);
}

void reconstruct(int i, int left, int right){
    if(i==cars.size()) return;
    if(left<cars[i]&&right<cars[i]) return;

    int a=0, b=0;
    if(left>=cars[i]) a=1+dp[i+1][left-cars[i]];
    if(right>=cars[i]) b=1+dp[i+1][left];

    if(a>=b){
        printf("port\n");
        reconstruct(i+1, left-cars[i], right);
    }else{
        printf("starboard\n");
        reconstruct(i+1, left, right-cars[i]);
    }
}

int main(){
    int t, entered=0;

    scanf("%d", &t);
    while(t--){
        if(entered) printf("\n");
        else entered=1;

        cars.clear();

        scanf("%d", &ferry);
        ferry*=100;
        int car;
        while(scanf("%d", &car)){
            if(car==0) break;
            cars.push_back(car);
        }
        cumm = vi(cars.size()+1);
        cumm[0]=0;
        for(int i=0; i<cars.size(); i++) cumm[i+1]=cumm[i]+cars[i];

        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0, ferry));
        reconstruct(0, ferry, ferry);
    }
    return 0;
}
