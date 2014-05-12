#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define max(x,y) (((x)>(y))?(x):(y))
#define MAXN 1000

using namespace std;

char T[MAXN];
int n;
int RA[MAXN], tempRA[MAXN], SA[MAXN], tempSA[MAXN];
int c[MAXN], LCP[MAXN], PHI[MAXN], PLCP[MAXN];

void countingSort(int k){
    int i, t, sum, maxi=max(300, n);
    memset(c, 0, sizeof c);
    for(i=0; i<n; i++)
        c[i+k<n  ? RA[i+k] : 0]++;
    for(i=sum=0; i<maxi; i++)
        t=c[i], c[i]=sum, sum+=t;
    for(i=0; i<n; i++)
        tempSA[c[SA[i]+k<n ? RA[SA[i]+k] : 0]++] = SA[i];
    for(i=0; i<n; i++) SA[i] = tempSA[i];
}

void constructSA(){
    int i,k,r;
    for(i=0; i<n; i++) RA[i]=T[i], SA[i]=i;
    for(k=1; k<n; k<<=1){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]]=r=0;
        for(i=1; i<n; i++)
            tempRA[SA[i]] = (RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k]) ? r: ++r;
        for(i=0; i<n; i++) RA[i] = tempRA[i];
        if(RA[SA[n-1]]==n-1) break;
    }
}

void computeLCP(){
    int i,L;
    PHI[SA[0]]=-1;
    for(i=1; i<n; i++)
        PHI[SA[i]]=SA[i-1];
    for(i=L=0; i<n; i++){
        if(PHI[i]==-1) { PLCP[i]=0; continue; }
        while(T[i+L]==T[PHI[i]+L]) L++;
        PLCP[i]=L;
        L=max(L-1, 0);
    }
    for(i=1; i<n; i++)
        LCP[i]=PLCP[SA[i]];
}

char tmp[1000];
set<string> myset;
set<string>::iterator it;

int main(){
    int i, j, k, l1, l2, maxs, entered=0;
    while(gets(T)!=NULL){
        if(entered) printf("\n"), gets(T);
        else entered=1;

        l1 = (int)strlen(T);
        gets(tmp);
        strcat(T, tmp);

        n = (int)strlen(T);

        if(l1==n || l1==0) { printf("No common sequence.\n"); continue; }

        T[n++] = '$';
        constructSA();
        computeLCP();
        //for (i = 0; i < n; i++) printf("%s %d\n", T+SA[i], LCP[i]);

        maxs=0;
        for(i=1; i<n; i++){
            if((SA[i-1]<l1 && SA[i]>=l1) || (SA[i-1]>=l1 && SA[i]<l1)){
                maxs = max(maxs, LCP[i]);
            }
        }
        if(maxs==0) { printf("No common sequence.\n"); continue; }
        myset.clear();
        for(i=1; i<n; i++){
            if((SA[i-1]<l1 && SA[i]>=l1) || (SA[i-1]>=l1 && SA[i]<l1)){
                if(LCP[i]==maxs) myset.insert(string(T+SA[i]).substr(0, maxs));
            }
        }
        for(it=myset.begin(); it!=myset.end(); it++) printf("%s\n", it->c_str());
    }
    return 0;
}
