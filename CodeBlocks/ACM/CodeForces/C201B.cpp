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

int a[100005], fixed[100005];

int main(){
    int n, i,j,k, fixedc=0, doable=0;
    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(i==a[i]) fixed[i]=1;
        else fixed[i]=0;
        fixedc+=fixed[i];
    }
    if(fixedc==n-2){
        printf("%d\n", n);
        return 0;
    }
    for(i=0; i<n; i++){
        if(!fixed[i]){
            if(!fixed[a[i]]){
                if(a[a[i]]==i){ printf("%d\n", fixedc+2); return 0;}
                else doable=1;
            }
        }
    }
    if(doable) printf("%d\n", fixedc+1);
    else printf("%d\n", fixedc);

    return 0;
}
