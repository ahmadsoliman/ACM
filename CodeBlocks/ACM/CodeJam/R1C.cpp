#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<string, bool> sb;
typedef vector<int> vi;
typedef vector<ii> vii;

char in[100];

int n;
vii flights;
vector<string> zips;

sb recur(int city, int visCities, int usedFlights, int usedReturn, int flightDir){
    bool alreadyVis=visCities&(1<<city);
    visCities |= (1<<city);

    if(visCities == (1<<n)-1) {
        if(usedFlights==usedReturn) return sb("", true);
    }

    string mins="999999999999999999999999999999999999999999999999999999999999";
    sb cur;

    for(int i=0; i<flights.size(); i++){
        if(!(usedFlights&(1<<i)) && flights[i].first==city && !(visCities&(1<<flights[i].second))){
            cur = recur(flights[i].second, visCities, usedFlights|(1<<i), usedReturn, flightDir|(1<<i));
            if(cur.second) mins = min(mins, cur.first);
        }
        if(!(usedFlights&(1<<i)) && flights[i].second==city && !(visCities&(1<<flights[i].first))){
            cur = recur(flights[i].first, visCities, usedFlights|(1<<i), usedReturn, flightDir);
            if(cur.second) mins = min(mins, cur.first);
        }
        if((usedFlights&(1<<i)) && !(usedReturn&(1<<i)) && flights[i].second==city && (flightDir&(1<<i))){
            cur = recur(flights[i].first, visCities, usedFlights, usedReturn|(1<<i), flightDir);
            if(cur.second) mins = min(mins, cur.first);
        }
        if((usedFlights&(1<<i)) && !(usedReturn&(1<<i)) && flights[i].first==city && !(flightDir&(1<<i))){
            cur = recur(flights[i].second, visCities, usedFlights, usedReturn|(1<<i), flightDir);
            if(cur.second) mins = min(mins, cur.first);
        }
    }
    if(mins=="999999999999999999999999999999999999999999999999999999999999") return sb("", false);
    return sb(((alreadyVis)?"":zips[city])+mins, true);
}

int main(){
    freopen("C-small.in","r",stdin);
    freopen("C-small.out", "w", stdout);

    int t, kase=1, m, x,y;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        zips.clear();
        for(int i=0; i<n; i++) {
            scanf("%s", in);
            zips.push_back(in);
        }
        flights.clear();
        for(int i=0; i<m; i++){
            scanf("%d %d", &x, &y);
            flights.push_back(ii(x-1,y-1));
            //flights.push_back(ii(y-1,x-1));
        }
        string mins="999999999999999999999999999999999999999999999999999999999999";
        for(int i=0; i<n; i++){
            sb cur = recur(i, (1<<i), 0, 0, 0);
            if(cur.second) {
                mins = min(mins, zips[i]+cur.first);
            }
        }
        printf("Case #%d: %s\n", kase++, mins.c_str());
    }

    return 0;
}
