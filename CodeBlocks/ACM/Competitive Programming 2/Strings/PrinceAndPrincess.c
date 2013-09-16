#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int s1[62510], s2[62510], kase, t, i, j, n, n1, n2, pos[62510];

int main(){
    kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &n1, &n2);

        scanf("%d", &i);
        for(i=0; i<n1; i++) {
            scanf("%d", &s1[i]);
            pos[s1[i]]=i;
        }
        scanf("%d", &i);
        for(i=0; i<n2; i++) scanf("%d", &s2[i]);


        printf("Case %d: %d\n", kase++, );
    }
    return 0;
}
