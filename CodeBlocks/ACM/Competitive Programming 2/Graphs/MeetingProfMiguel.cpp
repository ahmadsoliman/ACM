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

#define pb push_back

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

char t1[5], t2[5], c1[5], c2[5], ss1[5], ss2[5];

int g1[50][50], g2[50][50];

int main() {
    int m, w, s1,s2;

    while(scanf("%d", &m)>0){
        if(m==0) break;
        for(int i=0; i<26; i++) for(int j=0; j<26; j++) g1[i][j]=g2[i][j]=1000000000;
        for(int i=0; i<26; i++) g1[i][i]=g2[i][i]=0;
        for(int i=0; i<m; i++){
            scanf("%s %s %s %s %d", t1, t2 , c1, c2, &w);
            if(t1[0]=='Y'){
                g1[c1[0]-'A'][c2[0]-'A']=w;
                if(t2[0]=='B') g1[c2[0]-'A'][c1[0]-'A']=w;
            }else{
                g2[c1[0]-'A'][c2[0]-'A']=w;
                if(t2[0]=='B') g2[c2[0]-'A'][c1[0]-'A']=w;
            }
        }
        scanf("%s %s", &ss1, &ss2);
        s1 = ss1[0]-'A';
        s2 = ss2[0]-'A';
        for(int k=0; k<26; k++)
        for(int i=0; i<26; i++)
        for(int j=0; j<26; j++){
            if(g1[i][k]+g1[k][j]<g1[i][j]) g1[i][j]=g1[i][k]+g1[k][j];
            if(g2[i][k]+g2[k][j]<g2[i][j]) g2[i][j]=g2[i][k]+g2[k][j];
        }
        int minv=2000000000, mini;
        vector<int> res;
        for(int i=0; i<26; i++){
            w = g1[s1][i]+g2[s2][i];
            if(w<minv) minv=w, res.clear(), res.pb(i);
            else if(w==minv) res.pb(i);
        }
        if(minv>=100000000) printf("You will never meet.\n");
        else {
            printf("%d", minv);
            for(int i=0; i<res.size(); i++) printf(" %c", res[i]+'A');
            printf("\n");
        }
    }


    return 0;

}

/*
4
Y U A B 4
Y U C A 1
M U D B 6
M B A D 10
A A
*/
