/*j ID: ahmadad1
PROG: contact
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
typedef pair<int, string> is;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char in[100];
string s, cur;

map<string, int> m;
map<string, int>::iterator it;

#include <functional>
struct DereferenceCompareNode : public std::binary_function<is*, is*, bool>
{
    bool operator()(const is &a, const is &b) const{
        if(a.first<b.first) return 1;
        if(a.first>b.first) return 0;

        if(a.second.size()<b.second.size()) return 0;
        if(a.second.size()>b.second.size()) return 1;
        return a.second>b.second;
    }
};



int main() {
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);

    int i,j,r,l, a,b,n;

    scanf("%d %d %d", &a,&b,&n);

    s="";
    while(scanf("%s", in)>0) s+=string(in);

    for(; a<=b; a++){
        for(i=0; i+a<=s.size(); i++){
            cur = s.substr(i, a);
            it = m.find(cur);
            if(it==m.end()) m.insert(make_pair(cur, 1));
            else it->second++;
        }
    }

    priority_queue<is, vector<is>, DereferenceCompareNode > pq;
    for(it=m.begin(); it!=m.end(); it++){
        pq.push(is(it->second, it->first));
    }

    i=0;
    while(n-- && !pq.empty()){
        is cur=pq.top(); pq.pop();
        printf("%d\n", cur.first);
        printf("%s", cur.second.c_str());
        i=1;
        while(!pq.empty() && pq.top().first==cur.first) {
            if(i==6) printf("\n"), i=0;
            else if(i>0) printf(" ");
            printf("%s", pq.top().second.c_str()), pq.pop();
            i++;
        }
        printf("\n");
    }

    return 0;
}


