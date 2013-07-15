#include <stdio.h>
#include <stdio.h>
#define max(x,y) ((x>y)?x:y)

int n, vol[61], imp[61], isAtt[61], att[61][3], itemC[61], dp[61][32002];

int recur(int i, int V){
    if(i==n||V==0) return 0;
    if(isAtt[i]) return recur(i+1, V);
    if(dp[i][V]!=-1) return dp[i][V];
    int a=recur(i+1, V), b=0, cur;
    if(vol[i]<=V){
        b = vol[i]*imp[i]+recur(i+1, V-vol[i]);
        if(itemC[i]==1&&vol[i]+vol[att[i][0]]<=V){
            cur = vol[i]*imp[i]+vol[att[i][0]]*imp[att[i][0]]+recur(i+1, V-vol[i]-vol[att[i][0]]);
            if(cur>b) b=cur;
        }

        if(itemC[i]==2&&vol[i]+vol[att[i][0]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][0]]*imp[att[i][0]]+recur(i+1, V-vol[i]-vol[att[i][0]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==2&&vol[i]+vol[att[i][1]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][1]]*imp[att[i][1]]+recur(i+1, V-vol[i]-vol[att[i][1]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==2&&vol[i]+vol[att[i][0]]+vol[att[i][1]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][0]]*imp[att[i][0]]+vol[att[i][1]]*imp[att[i][1]]+recur(i+1, V-vol[i]-vol[att[i][0]]-vol[att[i][1]]);
            if(cur>b) b=cur;
        }

        if(itemC[i]==3&&vol[i]+vol[att[i][0]]+vol[att[i][1]]+vol[att[i][2]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][0]]*imp[att[i][0]]+vol[att[i][1]]*imp[att[i][1]]+vol[att[i][2]]*imp[att[i][2]]+recur(i+1, V-vol[i]-vol[att[i][0]]-vol[att[i][1]]-vol[att[i][2]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==3&&vol[i]+vol[att[i][0]]+vol[att[i][1]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][0]]*imp[att[i][0]]+vol[att[i][1]]*imp[att[i][1]]+recur(i+1, V-vol[i]-vol[att[i][0]]-vol[att[i][1]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==3&&vol[i]+vol[att[i][0]]+vol[att[i][2]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][0]]*imp[att[i][0]]+vol[att[i][2]]*imp[att[i][2]]+recur(i+1, V-vol[i]-vol[att[i][0]]-vol[att[i][2]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==3&&vol[i]+vol[att[i][1]]+vol[att[i][2]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][2]]*imp[att[i][2]]+vol[att[i][1]]*imp[att[i][1]]+recur(i+1, V-vol[i]-vol[att[i][2]]-vol[att[i][1]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==3&&vol[i]+vol[att[i][0]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][0]]*imp[att[i][0]]+recur(i+1, V-vol[i]-vol[att[i][0]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==3&&vol[i]+vol[att[i][1]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][1]]*imp[att[i][1]]+recur(i+1, V-vol[i]-vol[att[i][1]]);
            if(cur>b) b=cur;
        }
        if(itemC[i]==3&&vol[i]+vol[att[i][2]]<=V) {
            cur = vol[i]*imp[i]+vol[att[i][2]]*imp[att[i][2]]+recur(i+1, V-vol[i]-vol[att[i][2]]);
            if(cur>b) b=cur;
        }
    }
    return dp[i][V]=max(a,b);
}

int main(){
    int t, V, i, a;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d", &V, &n);
        memset(itemC, 0, sizeof itemC);
        for(i=0; i<n; i++){
            scanf("%d %d %d", &vol[i], &imp[i], &a);
            a--;
            isAtt[i]=0;
            if(a>=0) {
                isAtt[i]=1;
                att[a][itemC[a]++]=i;
            }
        }
        memset(dp, -1 , sizeof dp);
        printf("%d\n", recur(0, V));
    }
    return 0;
}
