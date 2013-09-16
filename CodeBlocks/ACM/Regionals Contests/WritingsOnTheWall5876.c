#include <stdio.h>
#include <string.h>

#define MAXN 50010

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
        if(i==n && j>0) {
            printf("j %d z %d\n", j, zfn[j-1]);
            i = i -(j-1) + zfn[j-1];
            occ+=(j-1)/(n-i);
            j=0;
        }
        if(j==m) j=zfn[j];
    }
}
/*
         i
xyzabcabcabc
         abcabcabcxyz
         j
   i
xyzabcabcabcabc
   abcabcabcabcxyz

*/

int main(){
    int t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%s %s", T, P);
        n = strlen(T);
        m = strlen(P);
        kmpPreprocess();
        kmp();
        printf("%d\n", occ+1);
    }
    return 0;
}
