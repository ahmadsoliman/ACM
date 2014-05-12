#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;

int R;

ii times[15];
vector<int> inter[15][9];
bitset<9> halls[15];

int presenthalls[9], maxh, done, dp[9][4100];

int recur(int h, int bm){
    if(bm==done) return 1;
    if(h==maxh) return 0;

    for(int i=0; i<)
}

int main(){
    int t, i,j,k, a,b, h;
    scanf("%d", &t);
    while(t-->0){
        scanf("%d", &R);
        memset(presenthalls, 0, sizeof presenthalls);
        maxh=0;
        for(i=0; i<R; i++){
            scanf("%d %d %d", &a, &b, &k);
            times[i]=ii(a,b);
            halls[i]=bitset<9>();
            for(j=0; j<k; j++){
                scanf("%d", &h);
                halls[i][h]=1;
                presenthalls[h]=1;
                maxh=max(maxh, h);
            }
        }
        for(i=0; i<R; i++) for(j=0; j<9; j++) inter[i][j].clear();

        for(i=0; i<R; i++){
            for(j=0; j<R; j++){
                if(times[i].first<=times[j].second || times[j].first<=times[i].second){
                    bitset<9> intr = halls[i]&halls[j];
                    for(k=1; k<9; k++){
                        if(intr[k]) {
                            inter[i][k].push_back(j);
                            inter[j][k].push_back(i);
                        }
                    }
                }
            }
        }
        done = (1<<R)-1;
        printf("%d\n", recur(1, 0));
    }
    return 0;
}
