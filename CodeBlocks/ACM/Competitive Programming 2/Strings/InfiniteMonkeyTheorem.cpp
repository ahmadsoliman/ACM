#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>


#define INF 1000000000

using namespace std;

double prob[26];
char in[100], c[10];
int len, n;

int main(){
    int m;
    while(scanf("%d %d", &n, &m)>0){
        if(!n&&!m) break;

        for(int i=0; i<n; i++){
            double p;
            scanf("%s %lf", c, &p);
            prob[c[0]-'a']=p;
        }

        scanf("%s", in);
        len = strlen(in);
        if(m<len) {
            printf("%0.00%\n");
            continue;
        }
        double p=1;
        for(int i=0; i<len; i++){
            p*=p*prob[in[i]-'a'];
        }
        printf("%.2lf%\n", p*(m-len+1)*100);
    }
    return 0;
}
