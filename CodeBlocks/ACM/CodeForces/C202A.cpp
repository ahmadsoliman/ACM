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

#define INF 1000000000

int main(){
    int n, i,j,k, c1=0,c2=0, f;
    scanf("%d", &n);
    f=1;
    for(i=0; i<n; i++){
        scanf("%d", &k);
        if(k==25) { c1++; continue; }
        else if(k==50){
            if(c1==0) { f=0; break;}
            c1--, c2++;
        }else {
            if((c1>=1&&c2>=1)) c1--, c2--;
            else if(c1>=3) c1-=3;
            else {f=0; break; }
        }
    }
    if(f) printf("YES\n");
    else  printf("NO\n");
    return 0;
}
