/*
ID: ahmadad1
PROG: calfflac
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

using namespace std;

typedef vector<int> vi;

int isPalin(vi v){
    for(int i=0; i<v.size(); i++) if(v[i]!=v[v.size()-1-i]) return 0;
    return 1;
}

string st, tmp;

char toLower(char c){
    if(c>='A'&&c<='Z') c='a'+(c-'A');
    return c;
}

int main() {
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);

    int i,j, s,e, c, len=0, nlen, maxi, f;
    char c1, c2;

    st="";
    while(getline(cin, tmp)>0) st+=tmp+"\n";

    for(i=0; i<st.size(); i++){
        for(s=i-1, e=i+1; s>=0 && e<st.size(); ){
            c1=tolower(st[s]);
            c2=tolower(st[e]);
            if(!(c1>='a'&&c1<='z')) { s--; continue;}
            if(!(c2>='a'&&c2<='z')) { e++; continue;}
            if(c1!=c2) { break; }
            s--, e++;
        }
        s++, e--;
        while(s<e){
            c1=tolower(st[s]); if((c1>='a'&&c1<='z')) break;
            s++;
        }
        while(e>s){
            c1=tolower(st[e]); if((c1>='a'&&c1<='z')) break;
            e--;
        }
        if(e-s+1>len) maxi=s, len=e-s+1;

        for(s=i, e=i+1; s>=0 && e<st.size(); ){
            c1=tolower(st[s]);
            c2=tolower(st[e]);
            if(!(c1>='a'&&c1<='z')) { s--; continue;}
            if(!(c2>='a'&&c2<='z')) { e++; continue;}
            if(c1!=c2) { break; }
            s--, e++;
        }
        s++, e--;
        while(s<e){
            c1=tolower(st[s]); if((c1>='a'&&c1<='z')) break;
            s++;
        }
        while(e>s){
            c1=tolower(st[e]); if((c1>='a'&&c1<='z')) break;
            e--;
        }
        if(e-s+1>len) maxi=s, len=e-s+1;
    }

    nlen=len;
    for(i=maxi; i<maxi+len; i++) {
        c1=tolower(st[i]);
        if(!(c1>='a'&&c1<='z')) nlen--;
    }
    printf("%d\n", nlen);
    printf("%s", st.substr(maxi, len).c_str());
    if(st[maxi+len-1]!='\n') printf("\n");
    return 0;
}
