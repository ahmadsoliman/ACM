#include <stdio.h>
#include <string.h>

#define MAXN 2000010

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
    while(1){
        scanf("%s", P);
        if(strcmp(P, ".")==0) return 0;
        m = strlen(P);
        n = 2*m;
        strcpy(T, P);
        strcat(T, P);
        kmpPreprocess();
        kmp();
        printf("%d\n", occ-1);
    }
    return 0;
}
