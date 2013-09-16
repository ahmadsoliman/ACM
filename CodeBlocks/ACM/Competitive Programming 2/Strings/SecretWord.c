#include <stdio.h>
#include <string.h>

#define MAXN 1000010

char T[MAXN], P[MAXN];
int zfn[MAXN], n, m, maxj;

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
    maxj=0;
    int i=0, j=0;
    while(i<n) {
        while(j>=0 && T[i]!=P[j]) j=zfn[j];
        i++; j++;
        if(j>maxj) maxj=j;
        if(j==m) j=zfn[j];
    }
}

int main(){
    int t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%s", P);
        n = m = strlen(P);
        for(i=0; i<m; i++) T[i]=P[m-i-1];
        kmpPreprocess();
        kmp();
        for(i=0; i<maxj; i++) T[i]=P[maxj-i-1];
        T[maxj]='\0';
        printf("%s\n", T);
    }
    return 0;
}

/*

caaaab

baaaac
baaaa
baaa
baa
ba
b


aabaaa
-------
aaabaa

aabaaa
aabaa
aaba
aab
aa
a

*/
