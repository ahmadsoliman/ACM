#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

pair<int,int> ka[100005];

int main(){
    int n, i, p=0, k , a, needed;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d", &k, &a);
        ka[i]= make_pair(k,a);
    }
    sort(ka, ka+n);
    vector<pair<int,int>> rem;
    rem.push_back(ka[0]);
    for(i=1; i<n; i++){
        if(ka[i].second>4*ka[i+1].second){
            needed=ceil(1.0*ka[i].second/(4*ka[i+1].second))*;
        }else{
            rem.remove()
        }
    }
//    if(ka[i]>4);
    return 0;
}
