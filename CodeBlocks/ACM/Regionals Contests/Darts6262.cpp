#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int radii[11]={20,40,60,80,100,120,140,160,180,200};
vector<int> radv;
vector<int>::iterator it1, it2;

int main(){
    int t, n, x,y, i,j,k;
    long long score;


    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        score=0;
        for(i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            double len = hypot(x,y);

            for(j=0; j<10; j++) if(radii[j]>len || fabs(radii[j]-len)<1e-9) break;

            if(j==10) continue;
            score += (10-j);

        }
        printf("%lld\n", score);
    }

    return 0;
}

/*

1
5
32 -39
71 89
-60 80
0 0
196 89

*/
