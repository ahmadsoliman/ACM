#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int mod1[100], mod2[100], mod0[100];

int main(){
    int n, i,j,k, cnt, last, pow, tmp;

    while(scanf("%d", &n)>0){

        pow=2;
        cnt=0;
        mod0[1]=1;
        mod1[1]=1;
        mod2[1]=0;
        while(n<=(1<<pow)){
            mod1[pow]=2*mod0[pow-1];
            mod2[pow]=2*mod1[pow-1];
            mod0[pow]=2*mod2[pow-1];
        }
    }
    return 0;
}
