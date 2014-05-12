#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

map<string, int> sti;
map<string, int>::iterator it;

char var[100], rhs[100], eq[100], pl[100], in[100], in2[100], v1[100], v2[100];
int isVar[1000], lenp;
vector<int> varlist[1000];
string val[1000], pattern;

string s;
int recur(int i, int j){
    if(j==lenp||i==s.size()) return j;
    if(s[i]==pattern[j]) return recur(i+1, j+1);
    return recur(i+1, j);
}

int dp[1000][2550];

int construct(int node, int j){
    if(j==lenp) return j;
    if(dp[node][j]!=-1) return dp[node][j];
    if(isVar[node]==1) {
        s = val[node];
        return dp[node][j]=recur(0, j);
    }
    for(int i=0; i<varlist[node].size(); i++){
        j=construct(varlist[node][i], j);
        if(j==lenp) break;
    }
    return dp[node][j]=j;
}

int main(){
    int t, n, i,j,k, ind, lhs, cur, start;

    gets(in);
    while(strcmp(in, "")==0) gets(in);
    sscanf(in, "%d", &t);
    while(t--){
        gets(in);
        while(strcmp(in, "")==0) gets(in);
        sscanf(in, "%d", &n);

        memset(isVar, 0, sizeof isVar);
        for(i=0; i<1000; i++) val[i]="", varlist[i].clear();
        sti.clear();
        ind=0;

        for(i=0; i<n; i++){
            gets(in);
            while(strcmp(in, "")==0) gets(in);

            char *p=strtok(in, " =+");

            strcpy(var, p);
            it = sti.find(var);
            if(it==sti.end()) lhs=ind, sti.insert(make_pair(var, ind++));
            else lhs=it->second;

            p=strtok(NULL, " =+");


            if(p[0]>='a'&&p[0]<='z'){
                val[lhs]=p;
                isVar[lhs]=1;
            }else{
                // variable
                isVar[lhs]=2;
                while(p!=NULL){
                    strcpy(var, p);
                    it = sti.find(var);
                    if(it==sti.end()) cur=ind, sti.insert(make_pair(var, ind++));
                    else cur=it->second;
                    varlist[lhs].push_back(cur);

                    p=strtok(NULL, " =+");
                }
            }
        }

        gets(in2);
        while(strcmp(in2, "")==0) gets(in2);
        sscanf(in2, "%s", in);
        it = sti.find(in);
        start=it->second;

        gets(in2);
        while(strcmp(in2, "")==0) gets(in2);
        sscanf(in2, "%s", in);
        lenp=strlen(in);
        pattern = string(in);

        memset(dp, -1, sizeof dp);
        if(construct(start, 0)==lenp) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
2
6
START = FIRST + SECND
FIRST = D + E
SECND = F + E
D = good
E = times
F = bad
START
debate
6
START = FIRST + SECND
FIRST = D + E
SECND = F + E
D = good
E = times
F = bad
START
oodimeimez

*/
