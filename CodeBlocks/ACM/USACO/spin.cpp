/*j ID: ahmadad1
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

int s[10];
vii weds[10];

int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);

    int i,j,r, k, a,e, f,f2,done;

    for(i=0; i<5; i++){
        scanf("%d", &s[i]);
        scanf("%d", &k);
        while(k--) scanf("%d %d", &a, &e), weds[i].push_back(ii(a,e));
    }

    done=0;
    for(i=0; i<10000; i++){
        /*if(i==9){
            for(j=0; j<5; j++){
                for(k=0; k<weds[j].size(); k++){
                    printf("%d %d\n", weds[j][k].first, (weds[j][k].first+weds[j][k].second)%360);
                }
            }
        }*/
        for(j=0; j<360; j++){
            f=1;
            for(k=0; k<5; k++){
                f2=0;
                for(r=0; r<weds[k].size(); r++){
                    if((weds[k][r].first<=j && j<=(weds[k][r].first+weds[k][r].second)%360)||
                        (weds[k][r].first<=j+360 && j+360<=(weds[k][r].first+weds[k][r].second))||
                        (weds[k][r].first<=j && j<=(weds[k][r].first+weds[k][r].second))){
                        f2=1;
                        break;
                    }
                }
                f = f && f2;
                if(!f) break;
            }
            if(f){
                done=1;
                printf("%d\n", i);
                break;
            }
        }
        if(done) break;
        for(j=0; j<5; j++){
            for(k=0; k<weds[j].size(); k++){
                weds[j][k].first=(weds[j][k].first+s[j])%360;
            }
        }
    }
    if(!done) printf("none\n");

    return 0;
}




