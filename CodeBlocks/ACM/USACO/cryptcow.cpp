/*j ID: ahmadad1
PROG: cryptcow
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

#define INF 1000000000

string res="Begin the Escape execution at the Break of Dawn";
char in[100];

int cti(char c){
    if(c>='a'&&c<='z') return c-'a';
    return c-'A'+26;
}

int cnt[30];
set<string> vis;

int recur(string s){
    if(s==res) return 0;

    //if(vis.find(s)!=vis.end()) return INF;
   // vis.insert(s);

    //printf("%s\n", s.c_str());

    string newpart;
    int minv=INF, f;
    for(int i=s.size()-3; i>=0; i--){
        if(s[i]!='C') continue;
        f=1;
        for(int j=i+1; j<s.size()-2; j++){
            if(s[j]!='O') continue;
            for(int k=j+1; k<s.size(); k++){
                if(s[k]!='W') continue;
                f=0;
                newpart=s.substr(0,i)+s.substr(j+1,k-j-1)+s.substr(i+1,j-i-1)+s.substr(k+1);
                //if(res.find(newpart)<0) continue;

                minv=min(minv, 1+recur(newpart));
                if(minv<INF) {
                    //printf("%s\n", s.c_str());
                    return minv;
                }
            }
            //if(!f) return minv;
        }
        //if(!f) return minv;
    }
    return minv;
}
/*
4
CaOBegin the EscWpe CnCak OexeOt the BWcutioWofO aCreW Dawn

BCC execuO the EsCinCaWCCreaOpWtiOn at OCDOcOWaOegCeWtheOW BWoWk of Wwn

BeCOgC CC execuOf DOBCiCCrWaOOt theCOCeak oWWin Oon aWtheOOW EscapeWtWWWwn

CC O CC W CC O W OO C OO W OC W O WWWW
*/
int main() {
  //  freopen("cryptcow.in", "r", stdin);
    //freopen("cryptcow.out", "w", stdout);

    int n,m, i,j,k;
    string s;

    gets(in);
    s=string(in);

    for(i=0; i<s.size(); i++) {
        if(s[i]=='C'||s[i]=='O'||s[i]=='W') cnt[s[i]-'A']++;
    }

    if(!(cnt[2]==cnt[14] && cnt[14]==cnt[22])){
        printf("0 0\n");
        return 0;
    }

    for(i=0; i<s.size(); i++) if(s[i]=='C') break;
    if(i<s.size() && s.substr(0, i)!=res.substr(0,min((int)res.size(),i))) {
        printf("0 0\n");
        return 0;
    }

    for(i=s.size()-1; i>=0; i--) if(s[i]=='W') break;
    if(i>0 && s.substr(i+1)!=res.substr(res.size()-(s.size()-i)+1)) {
        printf("0 0\n");
        return 0;
    }
/*
    int f=1;
    for(i=0; i<s.size(); i++){
        if(s[i]=='C'||s[i]=='O'||s[i]=='W'){
            for(j=i+1; j<s.size(); j++){
                if(s[j]=='C'||s[j]=='O'||s[j]=='W'){
                    if(res.find(s.substr(i+1, j-i-1))<0){
                        f=0;
                    }
                    break;
                }
            }
        }
        if(!f) break;
    }
    if(!f) {
        printf("0 0\n");
        return 0;
    }
*/

//printf("%s\n", res.c_str());

    k = recur(s);
    if(k<INF) printf("1 %d\n", k);
    else printf("0 0\n");

    return 0;
}









