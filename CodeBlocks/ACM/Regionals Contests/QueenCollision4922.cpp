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

vector<ii> qns;

int main(){
    int n,g, k,x,y,s,t, i,j,l, coll;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        scanf("%d", &g);
        qns.clear();
        for(i=0; i<g; i++){
            scanf("%d %d %d %d %d", &k,&x,&y,&s,&t);
            for(j=0; j<k; j++) qns.push_back(ii(x+j*s, y+j*t));
        }
        vi qnsx[n+10], qnsy[n+10];
        vii qnsd1[2*n+10], qnsd2[2*n+10];

        for(i=0; i<qns.size(); i++){
            qnsx[qns[i].first].push_back(qns[i].second);
            qnsy[qns[i].second].push_back(qns[i].first);

            qnsd1[qns[i].first+qns[i].second].push_back(qns[i]);
            qnsd2[qns[i].second-qns[i].first+n].push_back(qns[i]);
        }
        coll=0;
        for(i=0; i<=n; i++){
            if(qnsx[i].size()>1) coll+=qnsx[i].size()-1;
            if(qnsy[i].size()>1) coll+=qnsy[i].size()-1;
        }
        for(i=0; i<2*n; i++){
            if(qnsd1[i].size()>1) coll+=qnsd1[i].size()-1;
            if(qnsd2[i].size()>1) coll+=qnsd2[i].size()-1;
        }
        printf("%d\n", coll);
    }
    return 0;
}
