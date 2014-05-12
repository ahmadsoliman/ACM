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

int main(){
    int n, i,j,k, bm, done=(1<<10)-1;
    ll kn, kntmp;
    while(scanf("%d", &n)>0){
        bm=0, kn=n;
        k=0;
        while(bm!=done){
            kntmp=kn;
            while(kntmp>0){
                bm|=(1<<(kntmp%10));
                kntmp/=10;
            }
            kn+=n;
            k++;
        }
        printf("%d\n", k);
    }
    return 0;
}
