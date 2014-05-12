#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

char in[100];

vi occ[30];
vi::iterator it;

char toChar(int n){
    return (char)(n+(int)'a');
}

int score(char c){
    return (int)(c-'a');
}

int main(){
    freopen("mahdi.in", "r", stdin);
    int i,j,k, t,m, len, mul, add, lasti, kase=1, f;
    char lc;

    scanf("%d", &t);
    while(t--){
        for(i=0; i<30; i++) occ[i].clear();

        scanf("%s %d %d %d", in, &len, &mul, &add);
        lc = in[0];

        occ[score(lc)].push_back(0);
        for(i=1; i<len; i++){
            lc = toChar(((score(lc)*(mul%26))%26 + ((i%26)*(add%26))%26)%26);
            occ[score(lc)].push_back(i);
        }

        printf("Case %d:\n", kase++);
        scanf("%d", &m);

        for(k=0; k<m; k++){
            scanf("%s %d %d %d", in, &len, &mul, &add);
            lc = in[0];

            if(occ[score(lc)].size()==0){
                printf("REPEAT\n");
                continue;
            }
            lasti = occ[score(lc)][0];

            f=1;
            for(i=1; i<len; i++){
                lc = toChar(((score(lc)*(mul%26))%26 + ((i%26)*(add%26))%26)%26);
                it = upper_bound(occ[score(lc)].begin(), occ[score(lc)].end(), lasti);
                if(it==occ[score(lc)].end()){
                    f=0; break;
                }
                lasti = *it;
            }
            if(f) printf("BRAVO\n");
            else printf("REPEAT\n");
        }

    }
    return 0;
}
