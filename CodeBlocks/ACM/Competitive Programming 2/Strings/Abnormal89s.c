#include <stdio.h>
#include <string.h>

#define MAXN 200010

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
    maxj=-1;
    int i=1, j=0;
    while(i<n) {
        while(j>=0 && T[i]!=P[j]) j=zfn[j];
        i++; j++;
        if(i==n) maxj=j;
        if(j==m) {
            j=zfn[j];
        }
    }
}

int main(){
    int t, i, palin, alin;
    scanf("%d", &t);
    while(t--){
        palin=alin=1;
        scanf("%s", P);
        n = m = strlen(P);
        for(i=0; i<m; i++) {
            T[i]=P[m-i-1];
            if(T[i]!=P[i]) palin=0;
        }
        kmpPreprocess();
        kmp();

        if(maxj!=-1){
            for(i=0; i< (n-maxj)/2; i++) {
                if(P[maxj+i]!=P[n-i-1]) {
                    alin=0;
                    break;
                }
            }
        } else alin=0;

        if(alin) printf("alindrome\n");
        else if(palin) printf("palindrome\n");
        else printf("simple\n");
    }
    return 0;
}

/*

aaa = aa a, a aa

aaa
----
aaa
aa
a

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
