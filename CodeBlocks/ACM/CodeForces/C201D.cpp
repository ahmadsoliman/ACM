#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int la, lb, lc, dp[105][105][105];
char a[105], b[105], c[105];

int recur(int i, int j, int k){
    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(k==lc) return dp[i][j][k]=-INF;
    if(i==la || j==lb) return dp[i][j][k]=0;

    if(a[i]==b[j]){
        int o1=recur(i+1, j, k), o2=recur(i, j+1, k), o3=0;
        if(a[i]==c[k]) o3 = 1+recur(i+1, j+1, k+1);
        else o3 = 1+recur(i+1, j+1, 0);
        return dp[i][j][k]=max(o1, max(o2,o3));
    }else{
        int o1=recur(i+1, j, k), o2=recur(i, j+1, k);
        return dp[i][j][k]=max(o1, o2);
    }
}

string lcs, nlcs;

void reconstruct(int i, int j, int k){
    if(k==lc) return;
    if(i==la || j==lb) return;

    if(a[i]==b[j]){
        int o1=dp[i+1][j][k], o2=dp[i][j+1][k], o3=0;
        if(a[i]==c[k]) o3 = 1+dp[i+1][j+1][k+1];
        else o3 = 1+dp[i+1][j+1][0];

        if(o3>=o1 && o3>=o2) {
            lcs.push_back(a[i]);
            if(a[i]==c[k]) reconstruct(i+1, j+1, k+1);
            else reconstruct(i+1, j+1, 0);
        }else if(o1>o2 && o1>o3) reconstruct(i+1, j, k);
        else reconstruct(i, j+1, k);

    }else{
        int o1=dp[i+1][j][k], o2=dp[i][j+1][k];

        if(o1>o2) reconstruct(i+1, j, k);
        else reconstruct(i, j+1, k);
    }
}


#define MAXN 110

char T[MAXN], P[MAXN];
int zfn[MAXN], n, m, occ, occI[MAXN];

/* P , pattern preprocess */
void kmpPreprocess() {
    int i=0, j=-1;
    zfn[0]=-1;
    while(i<m){
        while(j>=0 && P[i]!=P[j]) j=zfn[j];
        i++; j++;
        zfn[i]=j;
    }
}

void kmp(){
    occ=0;
    int i=0, j=0;
    while(i<n) {
        while(j>=0 && T[i]!=P[j]) j=zfn[j];
        i++; j++;
        if(j==m) {
            occI[occ++]=i-j;
            j=zfn[j];
        }
    }
}


int main(){
    scanf("%s", a); la=strlen(a);
    scanf("%s", b); lb=strlen(b);
    scanf("%s", c); lc=strlen(c);
    memset(dp, -1, sizeof dp);
    int res = recur(0,0,0),i,j;
    if(res<=0) printf("0\n");
    else {
        reconstruct(0,0,0);
        strcpy(T, lcs.c_str());
        strcpy(P, c);
        n=lcs.size();
        m=lc;
        kmpPreprocess();
        kmp();

        nlcs="";
        for(i=0, j=0; i<lcs.size() && j<occ; i++){
            if(i-lc+1==occI[j]){
                j++;
                continue;
            }
            nlcs.push_back(lcs[i]);
        }
        nlcs+=lcs.substr(i);
        printf("%s\n", nlcs.c_str());
    }
    return 0;
}
