#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

char in[100000], P1[10000], P2[10000];
vector<string> comps;

int isLetter(char c){
    return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
}

int isDigit(char c){
    return c>='0'&&c<='9';
}

int main(){
    int R,N,kase=1, size;
    while(1){
        gets(in);
        if(in[0]=='0') return 0;

        comps.clear();
        char *p=strtok(in, "\"");
        while(p!=NULL){
            comps.push_back(p);
            p=strtok(NULL, "\"");
        }
        if(comps.size()==1){
            sscanf(comps[0].c_str(), "%d %d %s %s", &R, &N, P1, P2);
        }else if(comps.size()==5||comps.size()==4){
            sscanf(comps[0].c_str(), "%d %d", &R, &N);
            strcpy(P1, comps[1].c_str());
            strcpy(P2, comps[3].c_str());
        }else if(comps.size()==2){
            sscanf(comps[0].c_str(), "%d %d %s", &R, &N, P1);
            strcpy(P2, comps[1].c_str());
        }else if(comps.size()==3){
            sscanf(comps[0].c_str(), "%d %d", &R, &N);
            strcpy(P1, comps[1].c_str());
            strcpy(P2, comps[2].c_str());
        }
        R--;
        R%=(2*N);

        int i, l1=strlen(P1), l2=strlen(P2);
        for(i=0; i<l1; i++) P1[i]=tolower(P1[i]);
        for(i=0; i<l2; i++) P2[i]=tolower(P2[i]);

        if(R<N) printf("%d. %s\n", kase++, P1);
        else printf("%d. %s\n", kase++, P2);
    }
    return 0;
}







/*
        R = 0, N = 0;
        int ind = 0;
        while(in[ind]>='0'&&in[ind]<='9'){
            R = R*10 + (in[ind]-'0');
            ind++;
        }
        while(!(in[ind]>='0'&&in[ind]<='9'))
            ind++;
        while(in[ind]>='0'&&in[ind]<='9'){
            N = N*10 + (in[ind]-'0');
            ind++;
        }
        while(in[ind]==' ')
            ind++;
        if (in[ind]=='\"'){
            int ii = 0;
            ind++;
            while(in[ind]!='\"'){
                P1[ii++] = in[ind++];
            }
            ind++;
            P1[ii] = '\0';
        }
        else {
            int ii = 0;
            while(in[ind]!=' '){
                P1[ii++] = in[ind++];
            }
            P1[ii] = '\0';
        }
        while(in[ind]==' ')
            ind++;
        if (in[ind]=='\"'){
            int ii = 0;
            ind++;
            while(in[ind]!='\"'){
                P2[ii++] = in[ind++];
            }
            ind++;
            P2[ii] = '\0';
        }
        else {
            int ii = 0;
            while(isLetter(in[ind])||isDigit(in[ind])){
                P2[ii++] = in[ind++];
            }
            P2[ii] = '\0';
        }

*/
