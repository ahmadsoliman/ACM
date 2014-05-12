/*
ID: ahmadad1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

map<string, int> sti;
map<string, int>::iterator it;

vector<string> names;

char s[100];
int bal[100], origbal[100];

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int n, i,j,k, ind, amount;

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%s", s), names.push_back(s), sti.insert(make_pair(s, i));
    memset(bal, 0, sizeof bal);
    memset(origbal, 0, sizeof origbal);

    for(j=0; j<n; j++){
        scanf("%s", s);
        ind = (*sti.find(s)).second;
        scanf("%d %d", &origbal[ind], &k);
        if(k==0) continue;
        amount=origbal[ind]/k;
        bal[ind]+=origbal[ind]%k;
        for(i=0; i<k; i++){
            scanf("%s", s);
            bal[(*sti.find(s)).second]+=amount;
        }
    }

    for(i=0; i<n; i++) printf("%s %d\n", names[i].c_str(), bal[i]-origbal[i]);

    return 0;
}
/*
5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0
*/
