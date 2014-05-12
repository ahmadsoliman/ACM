#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>
#include <complex>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

// calc x^p, if * and / are the only operations

int n, res[1000000], bestSize, p, maxf=1;
vi resv;

int vis[100000];

void recur(){
    if(n>=bestSize) return;

    if(res[n-1]==p){
        resv=vi(res, res+n);
        bestSize=n;
        return;
    }

    if(maxf*pow(2,bestSize-n)<p) return;

    int tmpmax=maxf, best;

    for(int i=n-1; i>=0; i--){
        for(int j=i; j>=0; j--){
            res[n++]=res[i]+res[j];

            if(vis[res[n-1]]!=p){
                maxf=max(tmpmax, res[n-1]);
                vis[res[n-1]]=p;
                best=bestSize;
                recur();
                if(best==bestSize) vis[res[n-1]]=0;
            }
            n--;
            if(res[i]>res[j]){
                res[n++]=res[i]-res[j];
                if(vis[res[n-1]]!=p){

                    maxf=tmpmax;
                    vis[res[n-1]]=true;
                    best=bestSize;
                    recur();
                    if(best==bestSize) vis[res[n-1]]=0;
                }
                n--;
            }
        }
    }
}

int main() {
    int i,j,k;

    //scanf("%d", &p);
    memset(vis, 0, sizeof vis);

for(int k=1; k<200; k++){ //100 - 1.222, 200 - 28.862, 300 - 168.414
    p=k;

    //firt observation, set upper bound, powers of two, binary representation
    int tmpp=p, len=0;
    while(tmpp>0) {
        if(tmpp&1) len++;
        len++, tmpp/=2;
    }
    bestSize=len-1;

    //for(i=1; i<bestSize; i++)
    vis[1]=true, res[0]=1, n=1, recur();
}
    for(i=0; i<resv.size(); i++) printf("%d ", resv[i]);
    printf("\n");

    return 0;
}










