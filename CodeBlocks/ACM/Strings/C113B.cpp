#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

string s, pre, suf;

char in[3000];

set<string> res[2100];

vector<int> kmpPreprocess(string P) {
    vector<int> zfn(P.size()+1, 0);
    int i=0, j=-1;
    zfn[0]=-1;
    while(i<P.size()){
        while(j>=0 && P[i]!=P[j]) j=zfn[j];
        i++; j++;
        zfn[i]=j;
    }
    return zfn;
}

int main(){
    scanf("%s", in);
    s = in;
    scanf("%s", in);
    pre = in;
    scanf("%s", in);
    suf = in;

    vector<int> f1=kmpPreprocess(pre), f2=kmpPreprocess(suf);

    int i=0, j=0;
    while(i<s.size() && pre.size()<=s.size()) {
        while(j>=0 && s[i]!=pre[j]) j=f1[j];
        i++; j++;
        if(j==pre.size()) {
            string s2=s.substr(i-j);
            int k=0, l=0;
            while(k<s2.size() && suf.size()<=s2.size()) {
                while(l>=0 && s2[k]!=suf[l]) l=f2[l];
                k++; l++;
                if(l==suf.size()) {
                    res[k].insert(s.substr(i-j, k));
                    l=f2[l];
                }
            }
            j=f1[j];
        }
    }
    int cnt=0;
    for(int i=0; i<=s.size(); i++) cnt+=res[i].size();
    printf("%d\n", cnt);

    return 0;
}
