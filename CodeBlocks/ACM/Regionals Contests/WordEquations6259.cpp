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

char var[10], rhs[10000], in[10000], pattern[3000];
int isVar[1000], lenp;
vector<int> varlist[1000];
string val[1000];

string construct(int node){
    if(isVar[node]==1) return val[node];
    string res="";
    for(int i=0; i<varlist[node].size(); i++){
        res+=construct(varlist[node][i]);
    }
    isVar[node]=1;
    val[node]=res;
    return res;
}

string s;

int recur(int i, int j){
    if(j==lenp) return 1;
    if(i==s.size()) return 0;
    if(s[i]==pattern[j]) return recur(i+1, j+1);
    return recur(i+1, j);
}

int main(){
    int t, n, i,j,k, ind, lhs, cur, start;

    sscanf(gets(in), "%d", &t);
    while(t--){
        sscanf(gets(in), "%d", &n);

        memset(isVar, 0, sizeof isVar);
        for(i=0; i<550; i++) val[i]="", varlist[i].clear();
        sti.clear();
        ind=0;

        for(i=0; i<n; i++){
            gets(in);

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

        gets(in);
        it = sti.find(in);
        start=it->second;

        s = construct(start);

        gets(pattern);
        lenp=strlen(pattern);
        if(recur(0,0)) printf("YES\n");
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
debate

*/
