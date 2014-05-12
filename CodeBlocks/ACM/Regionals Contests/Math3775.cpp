#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;

double area[105];

int main(){
    int s,t, i;
    double dx=0.00001;
    double x;
    area[0]=0;
    for(i=1; i<101; i++){
        area[i]+=area[i-1];
        for(x=i+dx; x<i+1; x+=dx){
            area[i]+=dx*sqrt(x*x+x)/(x*x);
        }
    }
    while(scanf("%d %d", &s, &t)>0){
        printf("%.2lf\n", area[t-1]-area[s-1]);
    }
    return 0;
}
