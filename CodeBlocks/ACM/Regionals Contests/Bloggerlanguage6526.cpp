#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

char P[1000],T[1100];

#define MAXN 1100

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

bitset<1100> flagT;
bitset<1000> flagP;

int main(){
    int t, i,j,k, L,R, maxv, cur;

    while(scanf("%d %s", &t, P)>0){
        scanf("%s", T);

        flagT=bitset<1100>();
        flagP=bitset<1000>();

        n=strlen(T);
        m=strlen(P);
        for(i=0; i<n; i++){
            if(T[i]>='A'&&T[i]<='Z'){
                flagT[i]=1;
                T[i]='a'+(T[i]-'A');
            }else flagT[i]=0;
        }
        for(i=0; i<m; i++){
            if(P[i]>='A'&&P[i]<='Z'){
                flagP[i]=1;
                P[i]='a'+(P[i]-'A');
            }else flagP[i]=0;
        }

        kmpPreprocess();
        kmp();

        for(i=0; i<t; i++){
            scanf("%d %d", &L, &R);
            L--, R--;

            maxv=-1;
            for(j=0; j<occ; j++){
                if(occI[j]<L) continue;
                if(occI[j]+m>R+1) break;

                cur=0;
                for(k=0; k<m; k++){
                    if(flagT[occI[j]+k]!=flagP[k]) cur++;
                }
                maxv=max(maxv, cur);
            }
            for(j=L; j<=R; j++) flagT.flip(j);
            printf("%d\n", maxv);
        }
    }

    return 0;
}
