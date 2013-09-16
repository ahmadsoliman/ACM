#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char in[100];

int main(){
    int flag, m;
    long long i, j;
    char ch;
    while(sscanf(gets(in), "%d", &m)){
        char *P = (char*) malloc (m+1);
        gets(P);
        int *zfn = (int*) malloc ((m+1)*sizeof(int);

        i=0, j=-1;
        zfn[0]=-1;
        while(i<m){
            while(j>=0 && P[i]!=P[j]) j=zfn[j];
            i++; j++;
            zfn[i]=j;
        }

        i=0; j=0; flag=0;
        while((ch=getchar()) != EOF && ch != '\n'){
            while(j>=0 && ch!=P[j]) j=zfn[j];
            i++; j++;
            if(j==m) {
                flag=1;
                printf("%lld\n", i-j);
                j=zfn[j];
            }
        }
        free(P); free(zfn);
        if(flag==0) printf("\n");
    }
    return 0;
}
