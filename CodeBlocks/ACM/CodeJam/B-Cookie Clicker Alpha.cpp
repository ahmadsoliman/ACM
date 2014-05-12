#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out", "w", stdout);
    int t, kase=1;
    scanf("%d", &t);
    while(t--){
        double c,f,x, time=0.0, lastAns=0.0, curAns, rate=2.0;
        scanf("%lf %lf %lf", &c,&f,&x);

        lastAns = x/rate;
        while(1){
            time += c/rate;
            rate += f;

            curAns = time+x/rate;
            if(lastAns<curAns){
                time = lastAns;
                break;
            }
            lastAns = curAns;
        }

        printf("Case #%d: %.7lf\n", kase++, time);
    }
    return 0;
}
