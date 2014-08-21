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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int g[1005];

int recur(int n){
    if(n==0) return g[n]=0;
    if(n<=2) return g[n]=1;
    if(g[n]!=-1) return g[n];
    set<int> gs;
    gs.insert(recur(n-2));
    for(int i=2; i<n; i++) gs.insert(recur(i-2)^recur(n-i-1));
    g[n]=0;
    while(gs.find(g[n])!=gs.end()) g[n]++;
    return g[n];
}

int main(){
    memset(g, -1, sizeof g);
    for(int i=0; i<1000; i++) recur(i);
    int n;
    scanf("%d", &n);
    if(n>=52){
        n = (n-52)%34+52;
    }
    if(g[n]>0) printf("White");
    else printf("Black");
    return 0;
}





