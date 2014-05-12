#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

char in[105];
vector<string> words;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out", "w", stdout);

    int t, n, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        words.clear();
        for(int i=0; i<n; i++){
            scanf("%s", in);
            words.push_back(in);
        }
        string w="";
        w+=words[0][0];
        for(int i=1; i<words[0].size(); i++){
            if(words[0][i]!=words[0][i-1]) w+=words[0][i];
        }
        bool valid=true;
        for(int i=1; i<words.size(); i++){
            string w2="";
            w2+=words[i][0];
            for(int j=1; j<words[i].size(); j++){
                if(words[i][j]!=words[i][j-1]) w2+=words[i][j];
            }
            if(w2 != w) {
                valid=false;
                break;
            }
        }
        if(!valid) {
            printf("Case #%d: Fegla Won\n", kase++);
            continue;
        }
        vector<vector<int> > cnts(words.size(), vector<int>(w.size(), 0));
        for(int i=0; i<words.size(); i++){
            for(int j=0, k=0; j<words[i].size(); ){
                if(words[i][j]==w[k]) cnts[i][k]++, j++;
                else k++;
            }
        }
        int res=0;
        for(int i=0; i<w.size(); i++){
            int maxCnt=0;
            for(int j=0; j<words.size(); j++){
                maxCnt=max(maxCnt, cnts[j][i]);
            }
            int minv=1000000000, curv;
            for(int j=0; j<=maxCnt; j++){
                curv=0;
                for(int k=0; k<words.size(); k++){
                    curv += abs(cnts[k][i]-j);
                }
                minv = min(curv, minv);
            }
            res += minv;
        }
        printf("Case #%d: %d\n", kase++, res);
    }
    return 0;
}
