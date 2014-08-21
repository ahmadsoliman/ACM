#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;


int a[5100], dist[50100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    for(int i=0; i<a[0]; i++) dist[i]=2000000000;

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,0));
    dist[0]=0;

    while(!pq.empty()){
        ii p = pq.top(); pq.pop();
        if(p.first == dist[p.second]){
            for(int i=1; i<n; i++){
                int next = (p.second+a[i])%a[0];
                if(p.first+a[i]<dist[next]){
                    dist[next] = p.first+a[i];
                    pq.push(ii(dist[next], next));
                }
            }
        }
    }

    int k, S;
    scanf("%d", &k);
    while(k--){
        scanf("%d", &S);
        if(dist[S%a[0]]<=S) printf("TAK\n");
        else printf("NIE\n");
    }


    return 0;
}
