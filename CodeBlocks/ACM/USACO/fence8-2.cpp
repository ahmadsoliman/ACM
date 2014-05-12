/*j ID: ahmadad1
PROG: fence8
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
#include <complex>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

#define BSM 1050

int n,m;
vi rails;
vi boards;
vi cummSum;

vector<vvi> options;

void find_options(int board, int left, vi option, int next){
    if(left==0){
        options[board].push_back(option);
    }
    if(left<rails[next]||left>cummSum[next]) return;
    for(int i=next; i<m; i++){
        if(left<rails[i]||left>cummSum[i]) return;
        option.push_back(i);
        find_options(board, left-rails[i], option, i+1);
        option.pop_back();
    }
}

struct state{
    int x;
    bitset<BSM> bs;
    state(int x1, bitset<BSM> bs1){
        x=x1;
        bs=bs1;
    }
};

inline bool operator<(const state& lhs, const state& rhs){
    if(lhs.x==rhs.x) {
        for(int i=0; i<m; i++){
            if(lhs.bs[i]==rhs.bs[i]) continue;
            return lhs.bs[i]<rhs.bs[i];
        }
        return 0;
    }
    return lhs.x < rhs.x;
}

set<state> s;

int recur(int board, bitset<BSM> bs){
    if(board==n) return 0;

    state st(board, bs);
    if(s.find(st)!=s.end()) return 0;
    s.insert(st);

    int maxVal = recur(board+1, bs);
    int tried=0;
    for(int i=0; i<options[board].size(); i++){
        bitset<BSM> bstmp = bs;
        bool f=1;
        for(int j=0; j<options[board][i].size(); j++){
            if(bs[options[board][i][j]]){
                f=0; break;
            }
            bstmp[options[board][i][j]]=1;
        }
        if(f){
            maxVal=max(maxVal, recur(board+1, bstmp)+(int)options[board][i].size());
            tried++;
            // if(tried>7) break; // ay kalam
        }
    }
    return maxVal;
}

int main() {
 //   freopen("fence8.in", "r", stdin);
   // freopen("fence8.out", "w", stdout);

    int i,j,k;

    scanf("%d", &n);
    boards = vi(n);
    for(i=0; i<n; i++) scanf("%d", &boards[i]);
    sort(boards.begin(), boards.end());

    scanf("%d", &m);
    rails = vi(m);
    for(i=0; i<m; i++) scanf("%d", &rails[i]);
    sort(rails.begin(), rails.end());

    cummSum = vi(m);
    cummSum[rails.size()-1]=rails[rails.size()-1];
    for(int i=rails.size()-2; i>=0; i--){
        cummSum[i]=rails[i]+cummSum[i+1];
    }

    options = vector<vvi>(n);
    for(int i=0; i<n; i++){
        find_options(i, boards[i], vi(), 0);

        //sort options with more rails first
        vii p;
        for(int j=0; j<options[i].size(); j++){
            p.push_back(ii(options[i][j].size(), j));
        }
        sort(p.rbegin(), p.rend());
        vvi newOptions(options[i].size());
        for(int j=0; j<p.size(); j++){
            newOptions[j]=options[i][p[j].second];
        }
        options[i]=newOptions;
    }

    // sort boards with less number of options first
    vii p;
    for(int i=0; i<n; i++){
        p.push_back(ii(options[i].size(), i));
    }
    sort(p.begin(), p.end());
    vector<vvi> newOptions(n);
    for(int i=0; i<n; i++){
        newOptions[i]=options[p[i].second];
    }
    options=newOptions;

    printf("%d\n", recur(0, bitset<BSM>()));

    return 0;
}
