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

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int words[5];
char in[10000];

int main() {

    for(int i=0; i<4; i++) {
        scanf("%s", in);
        words[i]=strlen(in)-2;
    }

    int lucky=0, whos=0;
    for(int i=0; i<4; i++){
        bool shorter=true, longer=true;
        for(int j=0; j<4; j++){
            if(i==j) continue;
            if(2*words[i]>words[j]) shorter=false;
            if(words[i]<2*words[j]) longer=false;
        }
        if(shorter||longer) lucky++, whos=i;
    }
    if(lucky!=1) printf("C\n");
    else printf("%c\n", 'A'+whos);

    return 0;
}
