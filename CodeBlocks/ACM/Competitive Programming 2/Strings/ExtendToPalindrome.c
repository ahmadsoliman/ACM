#include <stdio.h>
#include <string.h>

#define MAXN 200010

char P[MAXN], s[MAXN];
int zfn[MAXN], m;

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

int main(){
    int t, i, len;
    while(scanf("%s", s)>0){
        len = strlen(s);
        m = 2*len+1;
        P[len]='$';
        for(i=0; i<len; i++) P[i+len+1]=P[len-1-i]=s[i];
        P[m]='\0';
        kmpPreprocess();

        for(i=len-zfn[m]-1; i>=0; i--) s[len++]=s[i];
        s[len]='\0';
        printf("%s\n", s);
    }
    return 0;
}
