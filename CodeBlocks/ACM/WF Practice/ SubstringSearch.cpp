#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

char in[401000];
int last[2000];

vector<int> get(string s){
    vector<int> r(s.size(), 0);
    memset(last, -1, sizeof last);
    for(int i=0; i<s.size(); i++){
        if(last[s[i]]>-1) r[i] = i-last[s[i]];
        last[s[i]]=i;
    }
    return r;
}

#define MAX_N 400010

string t;
vector<int> T, P;
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && !(P[i]==P[j] || (P[i]>j && P[j]==0))) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
  }
}           // in the example of P = "SEVENTY SEVEN" above

vector<int> kmpSearch() { // this is similar as kmpPreprocess(), but on string T
  vector<int> matches;
  int i = 0, j = 0; // starting values
  while (i < n) { // search through string T
    while (j >= 0 && !(T[i]==P[j] || (T[i]>j && P[j]==0))) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == m) { // a match found when j == m
      matches.push_back(i-j);
      j = b[j]; // prepare j for the next possible match
    }
  }
  return matches;
}

int main(){
    freopen("substring.in", "r", stdin);
    freopen("substring.out", "w", stdout);

    string s;

    scanf("%s", in);
    s = in;

    scanf("%s", in);
    t = in;

    n = s.size(), m = t.size();
    T = get(s);
    P = get(t);
    kmpPreprocess();

    vector<int> res = kmpSearch();
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    if(res.size()>0){
        printf("%d", res[0]+1);
        for(int i=1; i<res.size(); i++) printf(" %d", res[i]+1);
        printf("\n");
    }

    return 0;
}
