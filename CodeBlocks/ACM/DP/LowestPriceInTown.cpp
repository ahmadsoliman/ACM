#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

char in[100000];
int cnt[105], m;
bool vis[105];
double price[105], dp[105];

double recur(int left){
    if(left<=0) return 0.0;

    if(vis[left]) return dp[left];

    double minVal=2000000000;
    for(int i=0; i<m; i++){
        minVal = min(minVal, price[i]+recur(left-cnt[i]));
    }
    vis[left]=true;
    return dp[left]=minVal;
}

int main(){
    int kase=1, cur;
    double p;
    while(gets(in)){
        sscanf(in, "%lf %d", &p, &m);
        cnt[0]=1, price[0]=p;
        for(int i=0; i<m; i++){
            sscanf(gets(in), "%d %lf", &cnt[i+1], &price[i+1]);
        }
        m++;

        memset(vis, false, sizeof vis);

        gets(in);
        printf("Case %d:\n", kase++);
        char *p = strtok(in, " ");
        while(p!=NULL){
            sscanf(p, "%d", &cur);
            printf("Buy %d for $%.2lf\n", cur, recur(cur));
            p = strtok(NULL, " ");
        }
    }
    return 0;
}
