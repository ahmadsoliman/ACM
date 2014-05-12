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
#define MAX 1000000

vi d, divs[MAX+2];

int main(){
    int n, i,j,k, sqrtn, flag, found=0, i2;

    d = vi(MAX+1, 2);
    for(i=2; i<=1000; i++){
        i2=i*i;
        for(j=i; j<999978; j+=i)  {
            if(i2 > j) continue;
            d[j]++;
            divs[j].push_back(i);
            if(j!=i2) d[j]++, divs[j].push_back(j/i);
        }
    }

    for(i=2; i<999978; i++){
        if(d[i]<4) continue;
        flag=1;
        for(j=0; j<divs[i].size(); j++) if(d[i]%d[divs[i][j]]) { flag=0; break; }
        if(flag) { found++; if(found==108) printf("%d\n", i), found=0; }
    }
    return 0;
}
