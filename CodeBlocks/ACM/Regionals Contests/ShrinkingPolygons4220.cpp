#include <stdio.h>
#include <algorithm>
#include <math.h>


#define EPS 1e-9

using namespace std;

int main(){
    int n, arcs[10005], cumm[10005], circum, i,j,k, arc, done, curarc, m;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        circum=0;
        for(i=0; i<n; i++) {
            scanf("%d", &arcs[i]);
            circum+=arcs[i];
            if(i==0) cumm[i]=arcs[i];
            else cumm[i]=cumm[i-1]+arcs[i];
        }
        done=0;
        for(i=0; !done&&i<n; i++){
            arc=0;
            for(j=i, k=0; !done&&k<n-2 ; k++, j=(j+1)%n){
                arc+=arcs[j];
                curarc=arc;
                if(fabs(1.0*circum/arc-circum/arc)<EPS){
                    printf("%d %d %d %d\n",i,j,arc,arcs[j]);
                    while(binary_search(cumm, cumm+n, curarc+((i>0)?cumm[i-1]:0))){
                        curarc+=arc;
                    }
                    if(curarc==circum){
                        done=1;
                        m=circum/arc;
                    }
                }
            }
        }
        if(done && m>=3) printf("%d\n", n-m);
        else printf("-1\n");
    }
    return 0;
}
