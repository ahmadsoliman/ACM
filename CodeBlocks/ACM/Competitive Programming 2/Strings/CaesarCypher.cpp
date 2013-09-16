#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int mod(int x, int m){
    while(x<0) x+=m;
    return x%m;
}
vector<string> dic;
string enc, dec, maxdec;
char in[300], decs[300];

int main(){
    int i,j, c,l, maxc=-1;
    while(1){
        gets(in);
        dic.push_back(string(in));
        if(in[0]=='#') break;
    }
    gets(in);
    enc = string(in);
    for(i=1; i<=26; i++){
        dec = "";
        for(j=0; j<enc.size(); j++){
            if(enc[j]==' ')
                c=mod(-i,27);
            else
                c=mod((enc[j]-'A'-i+1), 27);
            if(c==0)
                dec.push_back(' ');
            else
                dec.push_back('A'+(c-1));
        }
        strncpy(in, dec.c_str(), dec.size());
        char * pch = strtok(in," ");
        c=0;
        while(pch!=NULL){
            if(find(dic.begin(), dic.end(), string(pch))!=dic.end()) c++;
            pch = strtok(NULL, " ");
        }
        if(c>maxc){
            maxc=c;
            maxdec=dec;
        }
    }
    strncpy(decs, maxdec.c_str(), maxdec.size());
    char * pch = strtok(decs," ");
    c=0;
    while(pch!=NULL){
        l=strlen(pch);
        if(c+l>60){
            printf("\n");
            c=0;
        }else if(c>0) { c++; printf(" "); }
        c+=l;
        printf("%s", pch);
        pch = strtok(NULL, " ");
    }
    printf("\n");
    return 0;
}
