#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int v[105];

int main(){
    int n, w, i,j,k, val, maxv, maxocc;
    double res, colorrate, curcolor;

    while(scanf("%d %d", &n, &w)>0){
        if(n==0 && w==0) return 0;

        memset(v, 0, sizeof v);
        maxv=0;
        for(i=0; i<n; i++) scanf("%d", &val), v[val/w]++, maxv=max(maxv, val/w);
        maxv++;

        maxocc=0;
        for(i=0; i<maxv; i++) {
          maxocc = max(maxocc, v[i]);
        }

        res=0.01;
        colorrate = 1.0/(maxv-1);
        curcolor=1;

        for(i=0; i<maxv; i++){
            res += curcolor*v[i]/maxocc;
            curcolor-=colorrate;
        }

        printf("%.6lf\n", res);
    }
    return 0;
}
