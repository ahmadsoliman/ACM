#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int * tree;
int MaxVal;

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int nums[300010], numfound[1000010], ans[200010];
vii qrs;
vector<iii> events;

#define type second.second

bool cmp(iii a, iii b){
	if (a.first==b.first)
        return a.type<b.type;
	return a.first<b.first;
}

int main(){
    int n, q, i,j,k, l,r, found;
    scanf("%d", &n);
    MaxVal=0;
    for(i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        events.push_back(iii(i+1, ii(nums[i], 0)));
    }
    scanf("%d", &q);
    for(i=0; i<q; i++) {
        scanf("%d %d", &l, &r);
        qrs.push_back(ii(l, r));
        events.push_back(iii(r, ii(i, 1)));
    }
    sort(events.begin(), events.end(), cmp);

    MaxVal=n;
    tree = new int[MaxVal+1];
    memset(tree, 0, sizeof(int)*(MaxVal+1));

    memset(numfound, -1, sizeof numfound);

    for(i=0; i<events.size(); i++){
        if(events[i].type==0){
            if(numfound[events[i].second.first]==-1) {
                numfound[events[i].second.first]=events[i].first;
                update(events[i].first, 1);
            } else {
                update(numfound[events[i].second.first], -1);
                update(events[i].first, 1);
                numfound[events[i].second.first]=events[i].first;
            }
        }else{
            l=qrs[events[i].second.first].first;
            r=qrs[events[i].second.first].second;
            ans[events[i].second.first]=read(r)-read(l-1);
        }
    }
    for(i=0; i<q; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}

