#include <stdio.h>

int main(){
    int n, arcs[10005], cumm[10005], circum, i,j;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        circum=0;
        for(i=0; i<n; i++) {
            scanf("%d", &arcs[i]);
            circum+=arcs[i];
            if(i==0) cumm[i]=arcs[i];
            else cumm[i]=cumm[i-1]+arcs[i];
        }
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){

            }
        }
    }
    return 0;
}
