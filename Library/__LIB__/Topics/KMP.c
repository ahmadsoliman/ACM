#include <stdio.h>
#include <string.h>

#define MAXN 100010

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
    int t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%s", T);
        scanf("%s", P);
        n = strlen(T);
        m = strlen(P);
        kmpPreprocess();
        kmp();
        for(i=0; i<occ; i++){
            printf("P is found at index %d in T\n", occI[i]);
        }
    }
    return 0;
}
