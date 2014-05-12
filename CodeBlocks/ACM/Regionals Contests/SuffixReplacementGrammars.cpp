#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <complex>
#include <iostream>

#define INF 1000000000

using namespace std;

char in[1000];

vector<set<string> > words;
string l1[200], l2[200];
map<string, int> hmap;

int dp[25][205][205];

int main(){
    freopen("suffix.in","r",stdin);

    string S, T;
    int NR, kase=1;

    while(1){
        scanf("%s", in);
        S = in;
        if(S[0]=='.') break;

        scanf("%s", in);
        T = in;
        scanf("%d", &NR);

        words = vector<set<string> >(22);
        for(int i=0; i<S.size(); i++){
            string x = S.substr(i);
            words[x.size()].insert(x);
        }
        for(int i=0; i<T.size(); i++){
            string x = T.substr(i);
            words[x.size()].insert(x);
        }

        for(int i=0; i<NR; i++){
            scanf("%s", in);
            l1[i]=in;
            scanf("%s", in);
            l2[i]=in;

            for(int j=0; j<l1[i].size(); j++){
                string x = l1[i].substr(j);
                words[x.size()].insert(x);
            }
            for(int j=0; j<l2[i].size(); j++){
                string x = l2[i].substr(j);
                words[x.size()].insert(x);
            }
        }

        hmap.clear();
        for(int i=1; i<21; i++){
            int j=0;
            for(set<string>::iterator it = words[i].begin(); it!=words[i].end(); it++, j++){
                hmap[*it]=j;
            }
        }

        for(int l=0; l<=S.size(); l++)
        for(int i=0; i<words[l].size(); i++)
        for(int j=0; j<words[l].size(); j++){
            dp[l][i][j]=INF;
        }

        for(int i=0; i<NR; i++){
            dp[l1[i].size()][hmap[l1[i]]][hmap[l2[i]]]=1;
        }

        for(int l=2; l<=S.size(); l++){
            for(set<string>::iterator it = words[l].begin(); it!=words[l].end(); it++){
                set<string>::iterator it2(it); it2++;
                for(; it2!=words[l].end(); it2++){
                    if((*it)[0]==(*it2)[0]) {
                        string u1 = (*it).substr(1);
                        string u2 = (*it2).substr(1);
                        if(hmap.find(u1)==hmap.end() || hmap.find(u2)==hmap.end()) continue;

                        dp[l][hmap[*it]][hmap[*it2]] = min(dp[l][hmap[*it]][hmap[*it2]], dp[l-1][hmap[u1]][hmap[u2]]);
                        dp[l][hmap[*it2]][hmap[*it]] = min(dp[l][hmap[*it2]][hmap[*it]], dp[l-1][hmap[u2]][hmap[u1]]);
                    }
                }
            }

            for(int k=0; k<words[l].size(); k++)
            for(int i=0; i<words[l].size(); i++)
            for(int j=0; j<words[l].size(); j++){
                dp[l][i][j]=min(dp[l][i][j], dp[l][i][k]+dp[l][k][j]);
            }
        }
        if(dp[S.size()][hmap[S]][hmap[T]]>=INF) printf("Case %d: No solution\n", kase++);
        else printf("Case %d: %d\n", kase++, dp[S.size()][hmap[S]][hmap[T]]);
    }

    return 0;
}
/*
AA BB 2
A B
AB BA

AAA ACC 2
AA BB
BB CC

AAA CCC 5
A B
AB BA
ABA BAA
BAA BBA
BBA CCC


AAA, AAB, ABA, BAA, BBA, CCC
*/
