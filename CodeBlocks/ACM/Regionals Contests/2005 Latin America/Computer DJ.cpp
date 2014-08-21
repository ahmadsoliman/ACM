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
typedef pair<int, string> is;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<string> words;
char in[1000];

int main(){
    int n, q, k, cur;

    while(scanf("%d %d", &n, &q)>0){
        if(!n&&!q) break;
        words.clear();
        for(int i=0; i<n; i++) scanf("%s", in), words.push_back(in);

        for(int i=0; i<q; i++){
            scanf("%d", &k);

            int chars;
            for(chars=1; ; chars++){
                cur = pow(n, chars)*chars;
                if(cur>k) break;
                k-=cur;
            }

            for(int j=chars-1; j>0; j--){
                cur = k/(pow(n, j)*(j+1));
                k -= cur*(pow(n, j)*(j+1));
            }
            printf("%d\n", k);
            //printf("%s\n", words[k-1].c_str());
        }
        printf("\n");
    }

    return 0;
}
