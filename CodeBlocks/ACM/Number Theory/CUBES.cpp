#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> state;

vector<int> cubes;
vector<state> res;
vector<int>::iterator it;

int main(){
    int i,j,k, v, tmp1,tmp2,tmp3;

    for(i=2; i<101; i++) cubes.push_back(i*i*i);

    for(i=2; i<100; i++){
        v=i*i*i;
        tmp1=v;
        for(j=i; j<100; j++){
            v=tmp1+j*j*j;
            tmp2=v;
            if(v>1000000) break;
            for(k=j; k<100; k++){
                v=tmp2+k*k*k;
                if(v>1000000) break;
                if(binary_search(cubes.begin(), cubes.end(), v)){
                    it=lower_bound(cubes.begin(), cubes.end(), v);
                    res.push_back(state(it-cubes.begin(), iii(i, ii(j,k))));
                }
            }
        }
    }
    sort(res.begin(), res.end());
    for(i=0; i<res.size(); i++){
        printf("Cube = %d, Triple = (%d,%d,%d)\n", res[i].first+2, res[i].second.first, res[i].second.second.first, res[i].second.second.second);
    }
    return 0;
}
