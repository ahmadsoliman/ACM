/*
ID: ahmadad1
PROG: namenum
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

using namespace std;

char in[50], cur[50];

int val[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    int n, i,j, len1, len2, f, f2;

    scanf("%s", &in);
    len1 = strlen(in);

    FILE *dict  = fopen ("dict.txt", "r");

    f2=0;
    while(fscanf (dict, "%s", cur)>0){
        len2=strlen(cur);
        if(len1!=len2) continue;

        f=1;
        for(i=0; i<len2; i++){
            if(val[cur[i]-'A']!=in[i]-'0') { f=0; break; }
        }
        if(f) f2=1, printf("%s\n", cur);
    }
    if(!f2) printf("NONE\n");
    return 0;
}
